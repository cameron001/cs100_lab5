#ifndef __RAND_HPP__
#define __RAND_HPP__
#pragma once
#include "base.hpp"
#include <cstdlib>
#include <ctime>
class Rand : public Base {
    public:
        Rand() : Base() { 
		srand(time(0));
		x = rand() % 100;
	 }
        virtual double evaluate() { return x; }
        virtual std::string stringify() { return std::to_string(x); }
    private:
	double x;
};

#endif
