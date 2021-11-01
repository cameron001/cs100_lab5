#include "gtest/gtest.h"

#include "op_test.hpp"
#include "exp.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "SevenMultMock.hpp"

TEST(sub_class, correct_output) {
        Base* three = new Op(3);
        Base* seven = new Op(7);
        Base* subtraction = new sub(three, seven);
        EXPECT_DOUBLE_EQ(subtraction->evaluate(), -4);
        EXPECT_EQ(subtraction->stringify(), "(3.000000-7.000000)");
}

TEST(sub_class, subbing_zeros) {
        Base* zero = new Op(0);
        Base* zero2 = new Op(0);
        Base * s = new sub(zero, zero2);
        EXPECT_DOUBLE_EQ(s->evaluate(), 0);
        EXPECT_EQ(s->stringify(), "(0.000000-0.000000)");
}

TEST(sub_class, subbing_negative_values) {
        Base* neg = new Op(-10);
        Base* pos = new Op(-3);
        Base* s = new sub(neg, pos);
        EXPECT_DOUBLE_EQ(s->evaluate(), -7);
        EXPECT_EQ(s->stringify(), "(-10.000000--3.000000)");
}

TEST(sub_class, sub_decimal_values) {
        Base* neg = new Op(-3.03333);
        Base* pos = new Op(10.098);
        Base* s = new sub(pos, neg);
        EXPECT_DOUBLE_EQ(s->evaluate(), 13.13133);
        EXPECT_EQ(s->stringify(), "(10.098000--3.033330)");
}

TEST(sub_class, sub_mult) {
	Base* neg = new Op(2);
	Base* pos = new Op(2);
	Base* mult = new sevenMultMock(7,2); //return 14
	Base* s = new sub(neg, mult); //2 - 14 = -12
	EXPECT_DOUBLE_EQ(s->evaluate(), -12); 
	EXPECT_EQ(s->stringify(), "(2.000000-14)");	
}


TEST(add_class, correct_output) {
        Base* three = new Op(3);
        Base* seven = new Op(7);
        Base* addition = new add(three, seven);
        EXPECT_DOUBLE_EQ(addition->evaluate(), 10);
        EXPECT_EQ(addition->stringify(), "(3.000000+7.000000)");
}

TEST(add_class, adding_zeros) {
        Base* zero = new Op(0);
        Base* zero2 = new Op(0);
        Base * addition = new add(zero, zero2);
        EXPECT_DOUBLE_EQ(addition->evaluate(), 0);
        EXPECT_EQ(addition->stringify(), "(0.000000+0.000000)");
}

TEST(add_class, adding_negative_values) {
        Base* neg = new Op(-10);
        Base* pos = new Op(-3);
        Base* addition = new add(neg, pos);
        EXPECT_DOUBLE_EQ(addition->evaluate(), -13);
        EXPECT_EQ(addition->stringify(), "(-10.000000+-3.000000)");
}

TEST(add_class, add_decimal_values) {
        Base* neg = new Op(-3.03333);
        Base* pos = new Op(10.098);
        Base* addition = new add(pos, neg);
        EXPECT_DOUBLE_EQ(addition->evaluate(), 7.06467);
        EXPECT_EQ(addition->stringify(), "(10.098000+-3.033330)");
}

TEST(add_class, add_mult) {
        Base* neg = new Op(2);
        Base* pos = new Op(2);
        Base* mult = new sevenMultMock(7,2); //return 14
        Base* a = new add(neg, mult); //2 + 14 = 16
        EXPECT_DOUBLE_EQ(a->evaluate(), 16);
	EXPECT_EQ(a->stringify(), "(2.000000+14)");

}




TEST(exponent_class, correct_output) {
	Base* three = new Op(3);
	Base* seven = new Op(7);
	Base* EXPT = new exponent(three, seven);
	EXPECT_DOUBLE_EQ(EXPT->evaluate(), 2187);
	EXPECT_EQ(EXPT->stringify(), "(3.000000**7.000000)");
}

TEST(exponent_class, zero_power) {
	Base* zero = new Op(0);
	Base* zero2 = new Op(0);
	Base * EXPT = new exponent(zero, zero2);
	EXPECT_DOUBLE_EQ(EXPT->evaluate(), 1);
	EXPECT_EQ(EXPT->stringify(), "(0.000000**0.000000)");
}

TEST(exponent_class, two_negative_values) {
	Base* neg = new Op(-10);
	Base* pos = new Op(-3);
	Base* EXPT = new exponent(neg, pos);
	EXPECT_DOUBLE_EQ(EXPT->evaluate(), -.001);	
	EXPECT_EQ(EXPT->stringify(), "(-10.000000**-3.000000)");
}

TEST(exponent_class, to_the_negative_power) {
	Base* neg = new Op(-3.0);
	Base* pos = new Op(10.0);
	Base* EXPT = new exponent(pos, neg);
	EXPECT_DOUBLE_EQ(EXPT->evaluate(), .001);
	EXPECT_EQ(EXPT->stringify(), "(10.000000**-3.000000)");
}

TEST(exponent_class, decimal_values) {
        Base* neg = new Op(-3.03333);
        Base* pos = new Op(10.098);
        Base* EXPT = new exponent(pos, neg);
        EXPECT_DOUBLE_EQ(EXPT->evaluate(), 0.00089913051295086369);
        EXPECT_EQ(EXPT->stringify(), "(10.098000**-3.033330)");
}

TEST(exponent_class, exponent_mult) {
        Base* neg = new Op(2);
        Base* pos = new Op(2);
        Base* mult = new sevenMultMock(7,2); //return 14
        Base* ex = new exponent(neg, mult); //2 ** 14 = 16384
        EXPECT_DOUBLE_EQ(ex->evaluate(), 16384);
        EXPECT_EQ(ex->stringify(), "(2.000000**14)");
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
