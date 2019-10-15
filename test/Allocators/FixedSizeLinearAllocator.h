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
