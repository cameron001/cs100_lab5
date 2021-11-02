#ifndef __DIV_HPP__
#define __DIV_HPP__
#pragma once
#include "base.hpp"
//using namespace std;
class Div : public Base{

        public:
                Div(Base* val1, Base* val2) :Base(){
                        x = val1;
                        y = val2;
		}
                virtual double evaluate(){
                        return (x->evaluate() / y->evaluate());
                }
                virtual std::string stringify(){
                        return "(" + x->stringify() + "/" + y->stringify() + ")";
                }
        private:
                Base* x;
                Base* y;

};

#endif
