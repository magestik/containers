#pragma once

#include <stdlib.h> // for malloc/free & realloc

#ifndef ASSERT
#	define ASSERT(exp, msg)
#	define ALLOW_DEBUG 0
#else
#	define ALLOW_DEBUG 1
#endif // ASSERT

class DefaultAllocator
{
public:

	DefaultAllocator(void)
	{
		// ...
	}

	~DefaultAllocator(void)
	{
		// ...
	}

	void * allocate(unsigned int size)
	{
		void * ptr = malloc(size);
		return(ptr);
	}

	void release(void * ptr)
	{
		free(ptr);
	}

	void * resize(void * ptr, unsigned int size)
	{
		ptr = realloc(ptr, size);
		return(ptr);
	}

private:

	// ...
};
