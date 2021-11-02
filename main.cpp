#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "exp.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "rand.hpp"

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
   
    Base* ad = new add(three, seven);
    Base* minus = new sub(three, seven);
    Base* expt = new exponent(three, seven);
    Base* d = new Div(three, seven);    
    Base* m = new mult(three, seven);
    Base* ran = new Rand();
    	

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    std::cout << ad->stringify() << " = " << ad->evaluate() << std::endl;
    std::cout << expt->stringify() << " = " << expt->evaluate() << std::endl;
    std::cout << d->stringify() << " = " << d->evaluate() << std::endl;
    std::cout << m->stringify() << " = " << m->evaluate() << std::endl;
    std::cout << ran->stringify() << " = " << ran->evaluate() << std::endl;
	
    Base* node = new add(expt, seven);
    std::cout << node->evaluate() << " = " << node->stringify() << std::endl;
    Base* node2 = new sub(node, three);
    std::cout << node2->evaluate() << " = " << node2->stringify() << std::endl;
    Base* node3 = new Div(node2, seven);
    std::cout << node3->evaluate() << " = " << node3->stringify() << std::endl;	
    Base* node4 = new mult(d, three);
    std::cout << node4->evaluate() << " = " << node4->stringify() << std::endl;

return 0;
}
