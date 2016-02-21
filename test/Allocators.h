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

#include <stdlib.h> // for malloc/free & realloc

class HeapAllocator
{
public:

	HeapAllocator(void) : m_pData(nullptr), m_size(0)
	{

	}

	~HeapAllocator(void)
	{
		clear();
	}

	unsigned int size(void) const
	{
		return(m_size);
	}

	bool require(unsigned int s)
	{
		if (s > m_size)
		{
			reserve(s);
		}

		return(nullptr != m_pData);
	}

	void clear(void)
	{
		free(m_pData);
		m_pData = nullptr;
		m_size = 0;
	}

	void * data(void)
	{
		return(m_pData);
	}

protected:

	void reserve(unsigned int size)
	{
		m_size = size;
		m_pData = realloc(m_pData, size);
	}

private:

	void *			m_pData;	// heap-allocated memory
	unsigned int	m_size;		// capacity
};

template<unsigned int S>
class FixedSizeAllocator
{
public:

	FixedSizeAllocator(void)
	{

	}

	~FixedSizeAllocator(void)
	{
		clear();
	}

	unsigned int size(void) const
	{
		return(S * sizeof(unsigned char));
	}

	bool require(unsigned int s)
	{
		return(s <= size());
	}

	void clear(void)
	{
		// ...
	}

	void * data(void)
	{
		return((void*)m_pData);
	}

private:

	unsigned char m_pData [S]; // statically-allocated memory
};
