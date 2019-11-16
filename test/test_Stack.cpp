#include "gtest/gtest.h"

#define ASSERT(assertion, message) EXPECT_TRUE(assertion) << message
#include "Stack.h"

#include "Allocators.h"

#include <iostream>

/**
 * @brief Test Stack implementation
 */
TEST(Stack, DefaultAllocator)
{
	Stack<int, DefaultAllocator> s;

	EXPECT_TRUE(s.empty());
	EXPECT_EQ(s.count(), 0u);

	s.push(10);
	s.push(42);
	s.pop();
	s.push(16);

	for (int i = 0; i < 2; ++i)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
}

/**
 * @brief Test Stack implementation
 */
TEST(Stack, FixedSizeAllocator)
{
	Stack<int, FixedSizeLinearAllocator<int, 6>> s;

	EXPECT_TRUE(s.empty());
	EXPECT_EQ(s.count(), 0u);

	s.push(10);
	s.push(0xdead);
	s.push(0xdead);
	s.push(0xdead);
	s.push(0xdead);
	s.push(0xdead);
}
