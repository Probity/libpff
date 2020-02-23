/*
 * Python object definition of the sequence and iterator object of record sets
 *
 * Copyright (C) 2008-2020, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _PYPFF_RECORD_SETS_H )
#define _PYPFF_RECORD_SETS_H

#include <common.h>
#include <types.h>

#include "pypff_libpff.h"
#include "pypff_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pypff_record_sets pypff_record_sets_t;

struct pypff_record_sets
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The parent object
	 */
	PyObject *parent_object;

	/* The get item by index callback function
	 */
	PyObject* (*get_item_by_index)(
	             PyObject *parent_object,
	             int index );

	/* The current index
	 */
	int current_index;

	/* The number of items
	 */
	int number_of_items;
};

extern PyTypeObject pypff_record_sets_type_object;

PyObject *pypff_record_sets_new(
           PyObject *parent_object,
           PyObject* (*get_item_by_index)(
                        PyObject *parent_object,
                        int index ),
           int number_of_items );

int pypff_record_sets_init(
     pypff_record_sets_t *record_sets_object );

void pypff_record_sets_free(
      pypff_record_sets_t *record_sets_object );

Py_ssize_t pypff_record_sets_len(
            pypff_record_sets_t *record_sets_object );

PyObject *pypff_record_sets_getitem(
           pypff_record_sets_t *record_sets_object,
           Py_ssize_t item_index );

PyObject *pypff_record_sets_iter(
           pypff_record_sets_t *record_sets_object );

PyObject *pypff_record_sets_iternext(
           pypff_record_sets_t *record_sets_object );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYPFF_RECORD_SETS_H ) */

