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
class Stack
{

public:

	typedef T type;

	// Constructors / Destructor
				Stack		(void);
	explicit	Stack		(T * data, unsigned int size);
				~Stack		(void);

	// Add methods
	void		push		(const T & elmt);

	// Remove methods
	void		pop			(void);

	// Element accessors
	const T &	top			(void) const;
	T &			top			(void);

	// Remove methods
	void            clear   (void);

	// Size accessors
	bool			empty	(void) const;
	unsigned int	count	(void) const;

private:

	Allocator		m_allocator;
	T *				m_pData;	// continuous memory block
	unsigned int	m_count;	// number of element

};

#include "Stack.inl"
