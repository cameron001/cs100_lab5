#pragma once

#include "base.hpp"

class sevenMultMock: public Base {
	public:
		sevenMultMock(double x, double y) { x = 7, y = 2; }
		virtual double evaluate() { return 14; }
		virtual std::string stringify() { return "14"; }


};
