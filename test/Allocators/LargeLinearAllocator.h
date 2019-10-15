#pragma once

#if __linux__ || __APPLE__
#	include <sys/mman.h> // for mmap
#endif // __linux__ || __APPLE__

#if _WIN32
#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>
#endif // _WIN32

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

#if __linux__ || __APPLE__
		m_pMappedMemory = mmap(nullptr, MAX, PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED, -1, 0);
#endif // __linux__ || __APPLE__

#if _WIN32
		m_pMappedMemory = VirtualAlloc(NULL, MAX, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#endif // _WIN32

		ASSERT(m_pMappedMemory != nullptr, "memory allocation failed");

		return(m_pMappedMemory);
	}

	void release(void * ptr)
	{
		ASSERT(ptr != nullptr, "can't release NULL ptr");

#if __linux__ || __APPLE__
		munmap(m_pMappedMemory, MAX);
#endif // __linux__ || __APPLE__

#if _WIN32
		VirtualFree(ptr, MAX, MEM_RELEASE);
#endif // _WIN32

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
