#include <assert.h>
#define ASSERT(exp, msg) assert(exp)

// Data Structures
#include <Array.h>
#include <List.h>

// Abstract Data Types
#include <Stack.h>

#include "Allocators.h"

#include <iostream>

/**
 * @brief Test Array implementation
 * @return true in case of success
 */
static bool test_Array(void)
{
	Array<int, HeapAllocator> a;

	if (!a.empty() || a.count() != 0)
	{
		std::cerr << "Array is not empty" << std::endl;
		return(false);
	}

	a.add(12);

	if (a.empty() || a.count() != 1)
	{
		std::cerr << "Array does not contain the expected number of element(s)" << std::endl;
		return(false);
	}
	else if (a[0] != 12)
	{
		std::cerr << "Array does not contain the expected value(s)" << std::endl;
		return(false);
	}

	a.add(15);

	if (a.empty() || a.count() != 2)
	{
		std::cerr << "Array does not contain the expected number of element(s)" << std::endl;
		return(false);
	}
	else if (a[0] != 12 || a[1] != 15)
	{
		std::cerr << "Array does not contain the expected value(s)" << std::endl;
		return(false);
	}

	for (int e : a)
	{
		std::cout << e << std::endl;
	}

	a[0] += 1;

	if (a[0] != 13 || a[1] != 15)
	{
		std::cerr << "Array does not contain the expected value(s)" << std::endl;
		return(false);
	}

	a.clear();

	if (!a.empty() || a.count() != 0)
	{
		std::cerr << "Array does not contain the expected number of element(s)" << std::endl;
		return(false);
	}

	return(true);
}

/**
 * @brief Test List implementation
 * @return true in case of success
 */
static bool test_List(void)
{
	List<int> l;

	l.insertAtHead(1);
	l.insertAtHead(2);
	l.insertAtHead(3);
	l.insertAtHead(4);
	l.insertAtHead(5);

	for (int e : l)
	{
		std::cout << e << std::endl;
	}

	return(true);
}

/**
 * @brief Test Stack implementation
 * @return true in case of success
 */
static bool test_Stack(void)
{
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

	Stack<int, FixedSizeAllocator<6*sizeof(int)>> f;

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
	test_Array();
	test_List();

	test_Stack();

	return 0;
}
