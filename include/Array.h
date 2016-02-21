/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.
 */

#pragma once

template<typename T, class Allocator>
class Array
{

public:

	typedef T type;

	struct iterator
	{
		explicit        iterator        (T * first) : current(first) { /* ... */ }
		T &				operator *		(void) { return *current; }
		iterator		operator ++		(void) { return iterator(current++); }
		bool			operator !=		(const iterator & it) { return(current != it.current); }

	private:
		T * current;
	};

	// Constructors / Destructor
				Array   (void);
	explicit    Array   (T * data, unsigned int size);
				~Array  (void);

	// Add methods
	void            add             (const T & elmt);

	// Element accessors
	T &				operator []		(unsigned int index);
	const T &		operator []		(unsigned int index) const;

	// Remove methods
	void            clear           (void);

	// Size accessors
	bool			empty			(void) const;
	unsigned int	count			(void) const;

	// Iterators access
	iterator		begin			(void) { return iterator((T*)m_allocator.data()); }
	iterator		end				(void) { return iterator((T*)m_allocator.data()+m_count); }

private:

	Allocator		m_allocator;
	unsigned int	m_count;	// number of element

};

#include "Array.inl"
