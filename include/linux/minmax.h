/* SPDX-License-Identifier: GPL-2.0 */
/*
 * This is a cutdown version of include/linux/minmax.h
 */
#ifndef _LINUX_MINMAX_H
#define _LINUX_MINMAX_H

#define __cmp_op_min <
#define __cmp_op_max >

#define __cmp(op, x, y)	((x) __cmp_op_##op (y) ? (x) : (y))

#ifdef __cerb__
#define __builtin_constant_p(x) 0
#endif

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

#ifdef NO_STATEMENT_EXPRS
static inline u32 min_u32(u32 x, u32 y)
/*@
	ensures return == (x < y ? x : y);
@*/
{
	return __cmp(min, x , y);
}

static inline u64 min_u64(u64 x, u64 y)
/*@
	ensures return == (x < y ? x : y);
@*/
{
	return __cmp(min, x , y);
}

static inline u64 max_u64(u64 x, u64 y)
/*@
	ensures return == (x > y ? x : y);
@*/
{
	return __cmp(max, x , y);
}
#else /* NO_STATEMENT_EXPRS */
#define min(x, y)	__careful_cmp(min, x, y)
#define max(x, y)	__careful_cmp(max, x, y)
#endif /* NO_STATEMENT_EXPRS */

#endif	/* _LINUX_MINMAX_H */
