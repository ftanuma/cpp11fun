//
//  main.cpp
//  cpp11fun
//
//  Created by Fumihiko Tanuma on 11/19/13.
//  Copyright (c) 2013 ftanuma. All rights reserved.
//

#include <iostream>
#include "auto.h"

int main(int argc, const char * argv[])
{
    std::cout << "Hello, C++11!\n";

    TestAuto();
	TestDeclType();
	return 0;
}


// TODO
//
///////////////////////////// Core Language
// decltype
// static_assert
// nullptr
// range-based for loops
// override and final
// strongly typed enums
// Lambdas
// rvalue reference and move semantics

///////////////////////////// STL support
//
// smart pointers
// non-member begin() and end()
//
//
