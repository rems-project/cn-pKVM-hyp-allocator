import lldb


def print_chunk_list(debugger, command, result, internal_dict, head=None):
    addr_str = command.strip()
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

    start = hyp_alloc.GetChildMemberWithName("start").GetValueAsUnsigned()
    size = hyp_alloc.GetChildMemberWithName("size").GetValueAsUnsigned()
    print(f"hyp_allocator metadata:\n"
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


def __lldb_init_module(debugger, internal_dict):
    commands = [("print_chunk_list", "pcl"), ("hyp", "hyp"),
                ("print_chunk_list", "print_chunk_list")]
    for cmd, alias in commands:
        debugger.HandleCommand(
            f'command script add -f lldb_lib.{cmd} {alias}')
    print(f"Loaded commands: {', '.join(cmd for cmd, _ in commands)}")
