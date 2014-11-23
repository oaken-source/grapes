
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

#define vector_declare(NAME, TYPE) \
    struct vector_ ## NAME \
    { \
      TYPE *items; \
      size_t nitems; \
    }; \
    typedef struct vector_ ## NAME NAME;

#define vector_map(V, FUNC) \
    do { \
      size_t i; \
      for (i = 0; i < (V).nitems; ++i) \
        FUNC((V).items[i]); \
    } while (0)

#define vector_init(V) _vector_init_impl((struct _vector_generic*)(V))

#define vector_clear(V) _vector_clear_impl((struct _vector_generic*)(V))

#define vector_push(V, ITEM) _vector_push_impl((struct _vector_generic*)V, &(ITEM), sizeof(ITEM))

struct _vector_generic
{
  void *items;
  size_t nitems;
};

void _vector_init_impl(struct _vector_generic *v);

void _vector_clear_impl (struct _vector_generic *v);

int _vector_push_impl(struct _vector_generic *v, void *item, size_t size) may_fail;

