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

#ifndef ASSERT
#	define ASSERT(exp, msg)
#endif // ASSERT

/**
 * Default constructor
 */
template<typename T, class Allocator>
inline Array<T, Allocator>::Array(void) : m_allocator(), m_count(0)
{
	// ...
}

/**
 * Pointer-copy constructor
 */
template<typename T, class Allocator>
inline Array<T, Allocator>::Array(T * data, unsigned int size) : m_allocator(data, size), m_count(size)
{
	ASSERT(nullptr != data, "data is null");
}

/**
 * Destructor
 */
template<typename T, class Allocator>
inline Array<T, Allocator>::~Array(void)
{
	// ...
}

/**
 * Add an element on the top
 */
template<typename T, class Allocator>
inline void Array<T, Allocator>::add(const T & elmt)
{
	unsigned int count = m_count++;
	bool result = m_allocator.require(m_count * sizeof(T));
	ASSERT(result, "allocation failed");
	((T*)m_allocator.data())[count] = elmt;
}

/**
 * Access any element
 */
template<typename T, class Allocator>
inline const T & Array<T, Allocator>::operator [] (unsigned int n) const
{
	ASSERT(n < m_count, "index out of bounds");
	return(((T*)m_allocator.data())[n]);
}

/**
 * Access any element
 */
template<typename T, class Allocator>
inline T & Array<T, Allocator>::operator [] (unsigned int n)
{
	ASSERT(n < m_count, "index out of bounds");
	return(((T*)m_allocator.data())[n]);
}

/**
 * Test whether the container is empty
 */
template<typename T, class Allocator>
inline bool Array<T, Allocator>::empty(void) const
{
	return(0 == m_count);
}

/**
 * Return the number of element
 */
template<typename T, class Allocator>
inline unsigned int Array<T, Allocator>::count(void) const
{
	return(m_count);
}

/**
 * Remove all elements
 */
template<typename T, class Allocator>
inline void Array<T, Allocator>::clear(void)
{
	m_count = 0;
	m_allocator.clear();
}
