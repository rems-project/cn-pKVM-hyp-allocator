/* SPDX-License-Identifier: GPL-2.0 */
/*
 * This is a cutdown version of include/linux/container_of.h
 */
#ifndef _LINUX_CONTAINER_OF_H
#define _LINUX_CONTAINER_OF_H

#include <assert.h>

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:    the pointer to the member.
 * @type:   the type of the container struct this is embedded in.
 * @member: the name of the member within the struct.
 *
 * WARNING: any const qualifier of @ptr is lost.
 */
#ifdef NO_STATEMENT_EXPRS
// hack suggested by Kayvan: https://rems-chat.cl.cam.ac.uk/rems/pl/iarhiqj8dfrzujo3m1zysssoir
#define container_of(ptr, type, member) \
	((type *)((unsigned char *)(ptr) + (0UL - offsetof(type, member))))
#else /* NO_STATEMENT_EXPRS */
#define container_of(ptr, type, member) ({				\
	void *__mptr = (void *)(ptr);					\
	static_assert(__same_type(*(ptr), ((type *)0)->member) ||	\
		__same_type(*(ptr), void),				\
		"pointer type mismatch in container_of()");		\
	((type *)(__mptr - offsetof(type, member))); })
#endif /* NO_STATEMENT_EXPRS */

#endif /* _LINUX_CONTAINER_OF_H */
