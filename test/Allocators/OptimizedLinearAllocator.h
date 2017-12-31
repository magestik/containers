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

#ifndef ASSERT
#	define ASSERT(exp, msg)
#	define ALLOW_DEBUG 0
#else
#	define ALLOW_DEBUG 1
#endif // ASSERT

template<unsigned int DEFAULT, unsigned int FACTOR = 2>
class OptimizedLinearAllocator
{
public:

        OptimizedLinearAllocator(void) : m_size(0)
        {
            // ...
	}

	~OptimizedLinearAllocator(void)
	{
	    // ...
	}

        void * allocate(unsigned int size)
        {
            m_size = DEFAULT;

            while (m_size < size)
            {
                m_size *= FACTOR;
            }

            void * ptr = (void*)malloc(size);

	    return(ptr);
	}

	void release(void * ptr)
	{
	    free(ptr);
	    m_size = 0;
	}

	void * resize(void * ptr, unsigned int size)
	{
            if (size <= m_size)
            {
                return(ptr);
            }

            while (m_size < size)
            {
                m_size *= FACTOR;
            }

	    ptr = realloc(ptr, m_size);

            return(ptr);
	}

private:

	unsigned int	m_size;		// capacity
};
