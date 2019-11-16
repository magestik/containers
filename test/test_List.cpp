#include <assert.h>
#define ASSERT(exp, msg) assert(exp)

#include "List.h"

#include "Allocators.h"

#include <iostream>

/**
 * @brief Test List implementation
 * @return true in case of success
 */
static bool test_List(void)
{
	List<int, DefaultAllocator> l;

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

int main()
{
	if (!test_List())
	{
		return(-1);
	}

	return 0;
}
