import lldb


def read_argument(arg):
    arg = arg.strip()
    if "=" in arg:
        key, value = arg.split("=", 1)
        return value
    return arg


def print_chunk_list(debugger, command, result, internal_dict, head=None):
    addr_str = read_argument(command)
    if not addr_str.startswith("0x"):
        print("Usage: pcl <pointer_address>", file=result)
        return

    target = debugger.GetSelectedTarget()
    process = target.GetProcess()

    addr = int(addr_str, 16)
    visited = set()

    node_offset = 8

    print("Traversing chunk list:", file=result)

    # head == `allocator->chunks`
    if head is not None:
        head = head.GetValueAsUnsigned()
        head -= node_offset

    while addr != 0 and addr not in visited and head != addr:
        visited.add(addr)
        chunk_val = target.CreateValueFromAddress("chunk", lldb.SBAddress(
            addr, target), target.FindFirstType("struct chunk_hdr"))
        alloc_size = chunk_val.GetChildMemberWithName(
            "alloc_size").GetValueAsUnsigned()
        mapped_size = chunk_val.GetChildMemberWithName(
            "mapped_size").GetValueAsUnsigned()
        hash_val = chunk_val.GetChildMemberWithName(
            "hash").GetValueAsUnsigned()

        print(
            f"0x{addr:016x}: alloc_size={alloc_size}, mapped_size={mapped_size}, hash={hash_val}", file=result)

        node = chunk_val.GetChildMemberWithName("node")
        next_ptr = node.GetChildMemberWithName("next").GetValueAsUnsigned()

        if next_ptr == 0:
            break

        addr = next_ptr - node_offset
    if head is not None and addr != head:
        print(
            f"Warning: chunk list ended unexpectedly at 0x{addr:016x}", file=result)


def hyp(debugger, command, result, internal_dict):
    target = debugger.GetSelectedTarget()
    if not target:
        print("error: no target loaded", file=result)
        return

    hyp_alloc = target.FindFirstGlobalVariable("hyp_allocator")
    if not hyp_alloc.IsValid():
        print("error: 'hyp_allocator' not found", file=result)
        return

    alloc_addr = hyp_alloc.AddressOf().GetValueAsUnsigned()
    start = hyp_alloc.GetChildMemberWithName("start").GetValueAsUnsigned()
    size = hyp_alloc.GetChildMemberWithName("size").GetValueAsUnsigned()
    print(f"hyp_allocator(0x{alloc_addr:x}) metadata:\n"
          f"  start = 0x{start:x}\n"
          f"  size  = {size}", file=result)

    chunks = hyp_alloc.GetChildMemberWithName("chunks")
    head_ptr = chunks.AddressOf().GetValueAsUnsigned()
    next_ptr = chunks.GetChildMemberWithName("next").GetValueAsUnsigned()

    if next_ptr == head_ptr:
        print("\nchunk list is empty", file=result)
        return

    node = hyp_alloc.GetChildMemberWithName("chunks")
    next_ptr = node.GetChildMemberWithName("next").GetValueAsUnsigned()

    first_chunk = next_ptr - 8

    print_chunk_list(debugger, f"0x{first_chunk:x}",
                     result, internal_dict, head=chunks.AddressOf())


def cn_alloc(debugger, command, result, internal_dict):
    addr_str = read_argument(command)
    if not addr_str:
        print("error: Usage: cn_alloc <address>", file=result)
        return
    try:
        addr = int(addr_str, 0)
    except ValueError:
        print(f"error: Invalid address '{addr_str}'", file=result)
        return

    target = debugger.GetSelectedTarget()
    if not target:
        print("error: no target loaded", file=result)
        return

    record_type = target.FindFirstType(
        "struct Cn_hyp_allocator_only_record").GetCanonicalType()
    rec = target.CreateValueFromAddress(
        "rec", lldb.SBAddress(addr, target), record_type)
    if not rec.IsValid():
        print(
            f"error: Could not read Cn_hyp_allocator_only_record at 0x{addr:x}", file=result)
        return

    def read_thunk(field_name, thunk_type_name, member_name):
        field = rec.GetChildMemberWithName(field_name)
        ptr = field.GetValueAsUnsigned()
        if ptr == 0:
            return None
        thunk_ty = target.FindFirstType(thunk_type_name).GetCanonicalType()
        thunk_val = target.CreateValueFromAddress(
            field_name + "_val", lldb.SBAddress(ptr, target), thunk_ty)
        if not thunk_val.IsValid():
            return None
        return thunk_val.GetChildMemberWithName(member_name).GetValueAsUnsigned()

    first = read_thunk("first",   "struct cn_pointer",  "ptr")
    head = read_thunk("head",    "struct cn_pointer",  "ptr")
    last = read_thunk("last",    "struct cn_pointer",  "ptr")
    size = read_thunk("size",    "struct cn_bits_u32",  "val")
    start = read_thunk("start",   "struct cn_bits_u64",  "val")

    print(f"Cn_hyp_allocator_only_record at 0x{addr:x}:", file=result)

    def fmt(val, is_ptr=False):
        if val is None:
            return "NULL"
        return f"0x{val:x}" if is_ptr else str(val)

    print(f"  first = {fmt(first, True)}", file=result)
    print(f"  head  = {fmt(head,  True)}", file=result)
    print(f"  last  = {fmt(last,  True)}", file=result)
    print(f"  size  = {fmt(size)} (uint32)", file=result)
    print(f"  start = {fmt(start, True)} (uint64)", file=result)


def cn_pointer(debugger, command, result, internal_dict):
    addr_str = read_argument(command)
    if not addr_str:
        print("error: Usage: cn_pointer <address>", file=result)
        return
    try:
        addr = int(addr_str, 0)
    except ValueError:
        print(f"error: Invalid address '{addr_str}'", file=result)
        return

    target = debugger.GetSelectedTarget()
    if not target:
        print("error: no target loaded", file=result)
        return

    ptr_type = target.FindFirstType(
        "struct cn_pointer") or target.FindFirstType("cn_pointer")
    if not ptr_type.IsValid():
        print("error: type 'cn_pointer' not found", file=result)
        return
    ptr_type = ptr_type.GetCanonicalType()

    # Read the struct from memory
    cp = target.CreateValueFromAddress(
        "cp", lldb.SBAddress(addr, target), ptr_type)
    if not cp.IsValid():
        print(f"error: Could not read cn_pointer at 0x{addr:x}", file=result)
        return

    # Extract and print the 'ptr' field
    ptr_val = cp.GetChildMemberWithName("ptr").GetValueAsUnsigned()
    if ptr_val == 0:
        print(f"cn_pointer at 0x{addr:x}: ptr = NULL", file=result)
    else:
        print(f"cn_pointer at 0x{addr:x}: ptr = 0x{ptr_val:x}", file=result)


def __lldb_init_module(debugger, internal_dict):
    commands = [("print_chunk_list", "pcl"), ("hyp", "hyp"),
                ("print_chunk_list", "print_chunk_list"),
                ("cn_alloc", "cn_alloc"), ("cn_pointer", "cn_ptr")]
    for cmd, alias in commands:
        debugger.HandleCommand(
            f'command script add -f lldb_lib.{cmd} {alias}')
    print(f"Loaded commands: {', '.join(cmd for cmd, _ in commands)}")
