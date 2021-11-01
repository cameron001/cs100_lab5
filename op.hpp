#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() { x = value; }
        virtual double evaluate() { return x; }
        virtual std::string stringify() { return std::to_string(x); }
	
    private:
	double x;
};

#endif //__OP_HPP__
