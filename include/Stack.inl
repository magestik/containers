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
inline Stack<T, Allocator>::Stack(void) : m_allocator(), m_pData(nullptr), m_count(0)
{
	// ...
}

/**
 * Pointer-copy constructor
 */
template<typename T, class Allocator>
inline Stack<T, Allocator>::Stack(T * data, unsigned int size) : m_allocator(data, size), m_pData(nullptr), m_count(size)
{
	ASSERT(nullptr != data, "data is null");
}

/**
 * Destructor
 */
template<typename T, class Allocator>
inline Stack<T, Allocator>::~Stack(void)
{
	clear();
}

/**
 * Add an element on the top
 */
template<typename T, class Allocator>
inline void Stack<T, Allocator>::push(const T & elmt)
{
	unsigned int count = m_count++;
	m_pData = (T*)m_allocator.resize(m_pData, m_count * sizeof(T));
	ASSERT(m_pData != nullptr, "allocation failed");
	m_pData[count] = elmt;
}

/**
 * Remove the top element
 */
template<typename T, class Allocator>
inline void Stack<T, Allocator>::pop(void)
{
	ASSERT(m_count > 0, "the stack is already empty");
	--m_count;
}

/**
 * Access the top element
 */
template<typename T, class Allocator>
inline const T & Stack<T, Allocator>::top(void) const
{
	ASSERT(m_count > 0, "the stack is empty");
	return(m_pData[m_count-1]);
}

/**
 * Access the top element
 */
template<typename T, class Allocator>
inline T & Stack<T, Allocator>::top(void)
{
	ASSERT(m_count > 0, "the stack is empty");
	return(m_pData[m_count-1]);
}

/**
 * Test whether the container is empty
 */
template<typename T, class Allocator>
inline bool Stack<T, Allocator>::empty(void) const
{
	return(0 == m_count);
}

/**
 * Return the number of element
 */
template<typename T, class Allocator>
inline unsigned int Stack<T, Allocator>::count(void) const
{
	return(m_count);
}

/**
 * Remove all elements
 */
template<typename T, class Allocator>
inline void Stack<T, Allocator>::clear(void)
{
	m_count = 0;
	m_allocator.release(m_pData);
	m_pData = nullptr;
}
