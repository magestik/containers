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

template<typename T, unsigned int S>
class FixedSizeLinearAllocator
{
public:

        FixedSizeLinearAllocator(void)
	{
		// ...
	}

	~FixedSizeLinearAllocator(void)
	{
		// ...
	}

	void * allocate(unsigned int size)
        {
            if (size > sizeof(T) * S)
            {
                return(nullptr);
            }

            return(m_pData);
	}

	void release(void * ptr)
        {
            ASSERT(ptr == m_pData, "Bad pointer");
	}

	void * resize(void * ptr, unsigned int size)
	{
            ASSERT(ptr == nullptr || ptr == m_pData, "Bad pointer");

            if (size > sizeof(T) * S)
            {
                return(nullptr);
            }

            return(m_pData);
	}

private:

        T m_pData [S]; // statically-allocated memory
};
