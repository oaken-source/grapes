
/******************************************************************************
 *                                  Grapes                                    *
 *                                                                            *
 *    Copyright (C) 2013 - 2014  Andreas Grapentin                            *
 *                                                                            *
 *    This program is free software: you can redistribute it and/or modify    *
 *    it under the terms of the GNU General Public License as published by    *
 *    the Free Software Foundation, either version 3 of the License, or       *
 *    (at your option) any later version.                                     *
 *                                                                            *
 *    This program is distributed in the hope that it will be useful,         *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *    GNU General Public License for more details.                            *
 *                                                                            *
 *    You should have received a copy of the GNU General Public License       *
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 ******************************************************************************/


#pragma once

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <grapes/util.h>

#include <stdlib.h>

/* this macro create and typedef's a vector struct of the given name and type
 * to be used with the generic vector_* functions below. This is similar to
 * C++'s template classes.
 * The created struct will have the name vector_ ## NAME and be typedef's to
 * NAME.
 *
 * You are not supposed to alter the values inside the struct yourself, but
 * as long as the values are valid array pointers and length, it should not
 * break anything.
 */
#define vector_declare(NAME, TYPE) \
    struct vector_ ## NAME \
    { \
      TYPE *items; \
      size_t nitems; \
    }; \
    typedef struct vector_ ## NAME NAME;

/* initialize the fields of a vector instance (type agnostic)
 *
 * params:
 *   V - a pointer to a vector
 */
#define vector_init(V) \
    { \
      (V)->items = NULL; \
      (V)->nitems = 0; \
    }

/* clear the fields of a vector and free the associated resources
 * (type agnostic). note that resources associated with the pushed items are
 * not automatically freed. you need to iterate the vector to free the items
 * before calling vector_clear to avoid memory leaks
 *
 * params:
 *   V - a pointer to a vector
 */
#define vector_clear(V) \
    { \
      free((V)->items); \
      (V)->items = NULL; \
      (V)->nitems = 0; \
    }

/* add a new item to the vector, resize the vector if necessary.
 *
 * this macro expands to an expression, instead of a statement to create a
 * return value that can be used to determine wether the push succeeded,
 * for example:
 *
 *   int res = vector_push(vector, item);
 *   assert_inner(!res, "vector_push");
 *
 * params:
 *   V -  a pointer to a vector
 *   ITEM - an item of the type that matches the created vector
 *
 * errors:
 *   may fail and set errno for the same reasons as errno
 *
 * returns:
 *   -1 on failure, 0 on success
 */
#define vector_push(V, ITEM) \
    ( \
      _vector_resize((struct _vector_generic*)(V), sizeof(*((V)->items)), (V)->nitems + 1) \
        ? 1 \
        : (((V)->items[(V)->nitems - 1] = (ITEM)) \
          , 0) \
    )

/* this struct represents a typeless vector as a struct of the same size
 */
struct _vector_generic
{
  void *items;
  size_t nitems;
};

/* resize a generic vector to the given size, using the given item size
 * (internal function)
 *
 * params:
 *   v - a pointer to a vector of any type, cast to a generic vector pointer
 *   item_size - the size of an item in the original vector
 *   length - the number of items to resize to
 *
 * errors:
 *   may fail and set errno for the same reasons as realloc
 *
 * returns:
 *   -1 on failure, 0 on success
 */
int _vector_resize(struct _vector_generic *v, size_t item_size, size_t length) may_fail;

