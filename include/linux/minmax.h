/* SPDX-License-Identifier: GPL-2.0 */
/*
 * This is a cutdown version of include/linux/minmax.h
 */
#ifndef _LINUX_MINMAX_H
#define _LINUX_MINMAX_H

#define __cmp_op_min <
#define __cmp_op_max >

#define __cmp(op, x, y)	((x) __cmp_op_##op (y) ? (x) : (y))


/*
 * TODO: commenting-out type checking (signedness compatibility). We should
 * bring it back.
 */
// #define __cmp_once(op, x, y, unique_x, unique_y) ({
// 	typeof(x) unique_x = (x);
// 	typeof(y) unique_y = (y);
// 	static_assert(__types_ok(x, y),
// 		#op "(" #x ", " #y ") signedness error, fix types or consider u" #op "() before " #op "_t()");
// 	__cmp(op, unique_x, unique_y); })
#define __cmp_once(op, x, y, unique_x, unique_y) ({	\
	typeof(x) unique_x = (x);			\
	typeof(y) unique_y = (y);			\
	__cmp(op, unique_x, unique_y); })


// This delays the concatenation to allow the expension of __COUNTER__
#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)

// From linux source at include/linux/compiler.h
/* Not-quite-unique ID. */
#ifndef __UNIQUE_ID
#define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __LINE__)
#endif

#define __careful_cmp(op, x, y)					\
	__builtin_choose_expr(__builtin_constant_p((x) - (y)),	\
		__cmp(op, x, y),				\
		__cmp_once(op, x, y, __UNIQUE_ID(__x), __UNIQUE_ID(__y)))

#define min(x, y)	__careful_cmp(min, x, y)
#define max(x, y)	__careful_cmp(max, x, y)

#endif	/* _LINUX_MINMAX_H */
