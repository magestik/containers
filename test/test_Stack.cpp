#include <assert.h>
#define ASSERT(exp, msg) assert(exp)

#include <Stack.h>

#include "Allocators.h"

#include <iostream>

/**
 * @brief Test Stack implementation
 * @return true in case of success
 */
static bool test_Stack(void)
{
	Stack<int, DefaultAllocator> s;

	if (!s.empty() || s.count() != 0)
	{
		std::cerr << "Array is not empty" << std::endl;
		return(false);
	}

	s.push(10);
	s.push(42);
	s.pop();
	s.push(16);

	for (int i = 0; i < 2; ++i)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	Stack<int, FixedSizeAllocator<int, 6>> f;

	f.push(10);
	f.push(0xdead);
	f.push(0xdead);
	f.push(0xdead);
	f.push(0xdead);
	f.push(0xdead);

	return(true);
}

int main()
{
	if (!test_Stack())
	{
		return(-1);
	}

	return 0;
}
