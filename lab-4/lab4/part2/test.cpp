#include "arraylist.h"
#include "gtest/gtest.h"

class ArrayListTest : public testing::Test {
protected:
	// You can remove any or all of the following functions if its body is empty.

	ArrayListTest() {
		// You can do set-up work for each test here.
	}

	virtual ~ArrayListTest() {
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
		list.add(1);
		list.add(2);
		list.add(3);
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
	ArrayList list;
};

TEST_F(ArrayListTest, GetNominal) {
	// Exepct 0th element to be 1, 1st elemnt to be 2, etc.
	for (int i = 0 ; i < 3; i++) {
		EXPECT_EQ(i + 1, list.get(i));
	}
}

TEST_F(ArrayListTest, AddNominal) {
	// Add 4, 5, 6 to the list
	for (int i = 4; i < 7; i++) {
		list.add(i);
	}

	// Expect 0th element to be 1, 1st elemnt to be 2, etc.
	for (int i = 0 ; i < 6; i++) {
		EXPECT_EQ(i + 1, list.get(i));
	}
}

TEST_F(ArrayListTest, RemoveNominal) {
	// Remove 2nd element
	list.remove(1);

	// Expect 0th element to be 1, 1st elemnt to be 3
	EXPECT_EQ(1, list.get(0));
	EXPECT_EQ(3, list.get(1));
}

TEST_F(ArrayListTest, SetOffNominal) {
	// Set 4th element to 4
	list.set(3, 4);

	// Expect 0th element to be 1, 1st elemnt to be 2, 2nd element to be 3, 3rd element to be 4
	EXPECT_EQ(1, list.get(0));
	EXPECT_EQ(2, list.get(1));
	EXPECT_EQ(3, list.get(2));
	EXPECT_EQ(4, list.get(3));
}
