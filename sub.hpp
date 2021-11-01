#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include <sstream>

class sub : public Base {
    public:
        sub(Base* value1, Base* value2) : Base() {
		x = value1;
		y = value2; }
        virtual double evaluate() { return x->evaluate() - y->evaluate(); }
        virtual std::string stringify() {
			return"(" + x->stringify() + "-" + y->stringify() + ")"; }   

private:
	Base* x;
	Base* y;
};

#endif //__SUB_HPP__
