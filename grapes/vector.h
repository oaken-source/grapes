
/******************************************************************************
 *                                  Grapes                                    *
 *                                                                            *
 *    Copyright (C) 2013 - 2015  Andreas Grapentin                            *
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

/* this macro creates and typedef's a vector struct of the given name and type
 * to be used with the generic vector_* functions below. This is similar to
 * C++'s template classes.
 * The created struct will have the name vector_ ## NAME and be typedef'd to
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
      void *_items; \
      size_t nitems; \
    }; \
    typedef struct vector_ ## NAME NAME

/* initialize the fields of a vector instance (type agnostic)
 *
 * params:
 *   V - a pointer to a vector
 */
#define vector_init(V) \
    do { \
      (V)->items = NULL; \
      (V)->_items = NULL; \
      (V)->nitems = 0; \
    } while (0)

/* clear the fields of a vector and free the associated resources
 * (type agnostic). note that resources associated with the pushed items are
 * not automatically freed. you need to iterate the vector to free the items
 * before calling vector_clear to avoid memory leaks
 *
 * params:
 *   V - a pointer to a vector
 */
#define vector_clear(V) \
    do { \
      free((V)->items); \
      vector_init(V); \
    } while(0)

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
 *   may fail and set errno for the same reasons as realloc
 *
 * returns:
 *   evluates to -1 on failure, 0 on success
 */
#define vector_push(V, ITEM) \
    ( \
      ((V)->_items = realloc((V)->items, sizeof(*((V)->items)) * ((V)->nitems + 1))) \
        ? ( \
          ((V)->items = (V)->_items), \
          ((V)->_items = NULL), \
          ((V)->nitems = (V)->nitems + 1), \
          ((V)->items[(V)->nitems - 1] = (ITEM)) \
          , 0 \
        ) : -1 \
    )

/* iterate a vector with the given logic
 *
 * example, to clear a vector of allocated pointers, use:
 *
 *   vector_map(v, ITEM,
 *     free(ITEM);
 *   );
 *   vector_clear(v);
 *
 * params:
 *   V - a pointer to a vector
 *   I - the name of the variable used to pass the item to the logic
 *   FUNC - user-defined source code
 */
#define vector_map(V, I, FUNC) \
    do { \
      size_t i; \
      for (i = 0; i < (V)->nitems; ++i) \
        { \
          typeof(*((V)->items)) I = (V)->items[i]; \
          FUNC \
        } \
    } while (0)
