/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2014 Felix Fietkau <nbd@nbd.name>
 * Copyright (C) 2004 - 2009 Ivo van Doorn <IvDoorn@gmail.com>
 */
/*
 * This is a cutdown version of include/linux/bitfield.h
 */
#ifndef _LINUX_BITFIELD_H
#define _LINUX_BITFIELD_H

#define __bf_shf(x) (__builtin_ffsll(x) - 1)
/**
 * FIELD_PREP() - prepare a bitfield element
 * @_mask: shifted mask defining the field's length and position
 * @_val:  value to put in the field
 *
 * FIELD_PREP() masks and shifts up the value.  The result should
 * be combined with other fields of the bitfield using logical OR.
 */
#ifdef NO_STATEMENT_EXPRS
#define FIELD_PREP(_mask, _val)						\
		(((typeof(_mask))(_val) << __bf_shf(_mask)) & (_mask))
#else /* NO_STATEMENT_EXPRS */
#define FIELD_PREP(_mask, _val)						\
	({								\
		((typeof(_mask))(_val) << __bf_shf(_mask)) & (_mask);	\
	})
#endif /* NO_STATEMENT_EXPRS */

/**
 * FIELD_GET() - extract a bitfield element
 * @_mask: shifted mask defining the field's length and position
 * @_reg:  value of entire bitfield
 *
 * FIELD_GET() extracts the field specified by @_mask from the
 * bitfield passed in as @_reg by masking and shifting it down.
 */
#ifdef NO_STATEMENT_EXPRS
#define FIELD_GET(_mask, _reg)						\
		((typeof(_mask))(((_reg) & (_mask)) >> __bf_shf(_mask)))
#else /* NO_STATEMENT_EXPRS */
#define FIELD_GET(_mask, _reg)						\
	({								\
		(typeof(_mask))(((_reg) & (_mask)) >> __bf_shf(_mask));	\
	})
#endif /* NO_STATEMENT_EXPRS */

#endif /* _LINUX_BITFIELD_H */
