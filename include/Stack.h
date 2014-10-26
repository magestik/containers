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

#include <stdlib.h>

template <typename T>
class Stack
{

public:

	typedef T type;

	/**
	 * Default constructor
	 */
	inline explicit Stack(void) : m_data(nullptr), m_count(0), m_size(0) { /* ... */ }

	/**
	 * Pointer-copy constructor
	 */
	inline explicit Stack(T * data, unsigned int size) : m_data(data), m_count(size), m_size(size)
    {
    	ASSERT(nullptr != m_data);
    }

	/**
	 * Destructor
	 */
	inline ~Stack(void)
	{
		if (NULL != m_data)
		{
			free(m_data);
		}
	}

    /**
     * Add an element on the top
     */
	inline void push(const T & elmt)
	{
		if (m_count >= m_size)
		{
			reserve((m_size + 1) * 2);
		}

		m_data[m_count++] = elmt;
	}

    /**
     * Remove the top element
     */
	inline void pop(void)
	{
		ASSERT(m_count > 0);
		--m_count;
	}

    /**
     * Access the top element
     */
    inline const T & top(void) const
    {
    	ASSERT(m_count > 0);
    	return m_data[m_count-1];
    }

    /**
     * Access the top element
     */
    inline T & top(void)
    {
    	ASSERT(m_count > 0);
    	return m_data[m_count-1];
    }

    /**
     * Test whether the container is empty
     */
    inline bool empty(void) const
    {
    	return(0 == m_count);
    }

    /**
     * Return the number of element
     */
    inline unsigned int count(void) const
    {
    	return(m_count);
    }

    /**
     * Preallocate memory
     */
    inline void reserve(unsigned int count)
    {
    	if (count > m_size)
    	{
			m_size = count;
			m_data = (T *)realloc(m_data, count * sizeof(T));
			ASSERT(nullptr != m_data);
    	}
    }

private:

    T *				m_data;		// elements
    unsigned int	m_count;	// number of element
    unsigned int	m_size;		// capacity

};
