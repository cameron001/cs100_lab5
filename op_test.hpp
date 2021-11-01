#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateZero) {
	Op* test = new Op(0);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateNegative) {
	Op* test = new Op(-55);
	EXPECT_EQ(test->evaluate(), -55);
}

TEST(OpTest, OpStringifyNonZero) {
	Op* test = new Op(10);
	EXPECT_EQ(test->stringify(), "10.000000");
}

TEST(OpTest, OpStringifyZero) {
	Op* test = new Op(0);
	EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(OpTest, OpStringifyNegative) {
	Op* test = new Op(-88);
	EXPECT_EQ(test->stringify(), "-88.000000");
}

#endif //__OP_TEST_HPP__
