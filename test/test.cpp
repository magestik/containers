#include <assert.h>
#define ASSERT(exp, msg) assert(exp)

#include <List.h>
#include <Array.h>
#include <Stack.h>

#include "Allocators.h"

#include <iostream>

int main()
{
	Array<int, HeapAllocator> a;

	a.add(12);
	a.add(15);

	for (int e : a)
	{
		std::cout << e << std::endl;
	}

	a.clear();

	Stack<int, HeapAllocator> s;

	s.push(10);
	s.push(42);
	s.pop();
	s.push(16);

	for (int i = 0; i < 2; ++i)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	Stack<int, FixedSizeAllocator<6>> f;

	f.push(10);
	f.push(0xdead);
	f.push(0xdead);
	f.push(0xdead);
	f.push(0xdead);
	f.push(0xdead);

	return 0;
}
