#pragma once

#include "base.hpp"

class add : public Base {
    public:
        add(Base* value1, Base* value2) : Base() {
                x = value1;
                y = value2; }
        virtual double evaluate() { return x->evaluate() + y->evaluate(); }
        virtual std::string stringify() {
                        return "(" + x->stringify() + "+" + y->stringify() + ")"; }

private:
        Base* x;
        Base* y;
};

