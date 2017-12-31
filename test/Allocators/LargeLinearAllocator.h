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

#include <sys/mman.h> // for mmap

#ifndef ASSERT
#	define ASSERT(exp, msg)
#	define ALLOW_DEBUG 0
#else
#	define ALLOW_DEBUG 1
#endif // ASSERT

template<unsigned int MAX>
class LargeLinearAllocator
{
public:

        LargeLinearAllocator(void) : m_pMappedMemory(nullptr)
        {
            // ...
	}

	~LargeLinearAllocator(void)
	{
	    // ...
	}

        void * allocate(unsigned int size)
        {
	    if (size > MAX)
	    {
		return(nullptr);
	    }

	    m_pMappedMemory = mmap(nullptr, MAX, PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED, -1, 0);

	    return(m_pMappedMemory);
	}

	void release(void * ptr)
	{
	    munmap(m_pMappedMemory, MAX);
	    m_pMappedMemory = nullptr;
	}

	void * resize(void * ptr, unsigned int size)
	{
	    if (size > MAX)
	    {
		return(nullptr);
	    }

	    if (ptr == nullptr)
	    {
		return(allocate(size));
	    }

            return(ptr);
	}

private:

	void * m_pMappedMemory;
};
