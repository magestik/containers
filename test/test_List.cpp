#include "gtest/gtest.h"

#include "List.h"

#include "Allocators.h"

#include <iostream>

/**
 * @brief Test List implementation
 */
TEST(List, DefaultAllocator)
{
	List<int, DefaultAllocator> l;

	EXPECT_TRUE(l.empty());
	EXPECT_TRUE(l.count() > 0);

	l.insertAtHead(1);
	l.insertAtHead(2);
	l.insertAtHead(3);
	l.insertAtHead(4);
	l.insertAtHead(5);

	for (int e : l)
	{
		std::cout << e << std::endl;
	}
}
