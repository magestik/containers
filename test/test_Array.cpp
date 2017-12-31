#include <assert.h>
#define ASSERT(exp, msg) assert(exp)

#include <Array.h>

#include "Allocators.h"

#include <iostream>

/**
 * @brief Test Array implementation
 * @return true in case of success
 */
static bool test_Array_DefaultAllocator(void)
{
	Array<int, DefaultAllocator> a;

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

	a.add(2);
	a.removeElementAtIndex(1);

	if (a.empty() || a.count() != 2)
	{
		std::cerr << "Array does not contain the expected number of element(s)" << std::endl;
		return(false);
	}
	else if (a[0] != 13 || a[1] != 2)
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
 * @brief Test Array implementation
 * @return true in case of success
 */
static bool test_Array_LargeAllocator(void)
{
	Array<int, LargeLinearAllocator<512*1024*1024>> a; // max 512 MB

	for (int i = 0; i < 1000000; ++i) // add 1 million elements
	{
		a.add(i);
	}

	if (a[500] != 500)
	{
		std::cerr << "Array does not contain the expected value(s)" << std::endl;
		return(false);
	}
	else if (a[4444] != 4444)
	{
		std::cerr << "Array does not contain the expected value(s)" << std::endl;
		return(false);
	}
	else if (a[105632] != 105632)
	{
		std::cerr << "Array does not contain the expected value(s)" << std::endl;
		return(false);
	}
	else if (a[999999] != 999999)
	{
		std::cerr << "Array does not contain the expected value(s)" << std::endl;
		return(false);
	}

	return(true);
}

int main()
{
	if (!test_Array_DefaultAllocator())
	{
		return(-1);
	}

	if (!test_Array_LargeAllocator())
	{
		return(-1);
	}

	return 0;
}
