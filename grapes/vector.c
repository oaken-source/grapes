
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


#include "vector.h"

#include <string.h>

void
_vector_init_impl (struct _vector_generic *v)
{
  v->items = NULL;
  v->nitems = 0;
}

void
_vector_clear_impl (struct _vector_generic *v)
{
  free(v->items);
  v->items = NULL;
  v->nitems = 0;
}

int
_vector_push_impl(struct _vector_generic *v, void *item, size_t size)
{
  ++(v->nitems);
  void *new = realloc(v->items, v->nitems * size);
  assert_inner(new, "realloc");

  v->items = new;
  memcpy(v->items + (v->nitems - 1) * size, item, size);

  return 0;
}
