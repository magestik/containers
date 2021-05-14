#include "gtest/gtest.h"

#define ASSERT(assertion, message) EXPECT_TRUE(assertion) << message
#include "Array.h"

#include "Allocators.h"

#include <iostream>

/**
 * @brief Test Array implementation
 */
TEST(Array, DefaultAllocator)
{
	Array<int, DefaultAllocator> a;

	EXPECT_TRUE(a.empty());
	EXPECT_EQ(a.count(), 0u);

	a.add(12);

	EXPECT_FALSE(a.empty());
	EXPECT_EQ(a.count(), 1u);
	EXPECT_EQ(a[0], 12);

	a.add(15);

	EXPECT_FALSE(a.empty());
	EXPECT_EQ(a.count(), 2u);
	EXPECT_EQ(a[0], 12);
	EXPECT_EQ(a[1], 15);

	for (int e : a)
	{
		std::cout << e << std::endl;
	}

	a[0] += 1;

	EXPECT_EQ(a[0], 13);
	EXPECT_EQ(a[1], 15);

	a.add(2);
	a.removeElementAtIndex(1);

	EXPECT_FALSE(a.empty());
	EXPECT_EQ(a.count(), 2u);
	EXPECT_EQ(a[0], 13);
	EXPECT_EQ(a[1], 2);

	a.clear();

	EXPECT_TRUE(a.empty());
	EXPECT_EQ(a.count(), 0u);
}

/**
 * @brief Test Array implementation
 */
TEST(Array, LargeAllocator)
{
	Array<int, LargeLinearAllocator<512*1024*1024>> a; // max 512 MB

	EXPECT_TRUE(a.empty());
	EXPECT_EQ(a.count(), 0u);

	constexpr int nElements = 1000000; // 1 million elements

	for (int i = 0; i < nElements; ++i)
	{
		a.add(i);
	}

	EXPECT_FALSE(a.empty());
	EXPECT_EQ(a.count(), (unsigned int)nElements);

	EXPECT_EQ(a[500], 500);
	EXPECT_EQ(a[4444], 4444);
	EXPECT_EQ(a[105632], 105632);
	EXPECT_EQ(a[999999], 999999);
}
