#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "exp.hpp"

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(10);
    Base* seven = new Op(-3);
   
    Base* ad = new add(three, seven);
   
	 Base* minus = new sub(three, seven);
    
	 Base* expt = new exponent(three, seven);
    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    std::cout << ad->stringify() << " = " << ad->evaluate() << std::endl;
	std::cout << expt->stringify() << " = " << expt->evaluate() << std::endl;
	Base* node = new add(expt, seven);
	std::cout << node->evaluate() << " = " << node->stringify() << std::endl;	
return 0;
}
