#pragma once
#include "base.hpp"

class exponent : public Base {
    public:
        exponent(Base* value1, Base* value2) : Base() {
                x = value1;
                y = value2; }
        virtual double evaluate() { return pow(x->evaluate(),y->evaluate()); }
        virtual std::string stringify() {
		std::string str = x->stringify();;
		//str.erase(str.find_last_not_of('0') + 1, std::string::npos);
		std::string str2 = y->stringify();;
                //str2.erase(str2.find_last_not_of('0') + 1, std::string::npos);
                        return "(" + str + "**" + str2 + ")"; }

	private:
        	Base* x;
        	Base* y;
};

