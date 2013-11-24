//
//  auto.cpp
//  cpp11fun
//
//  Created by Fumihiko Tanuma on 11/19/13.
//  Copyright (c) 2013 ftanuma. All rights reserved.
//
#include <vector>
#include "decltype.h"
#include <iostream>

namespace {
    class Foo{
    public:
        Foo(){}
    };
}

void print(const std::vector<int> &vec)
{
    // following "auto it" should be const iterator.
    for(auto it = begin(vec); it != end(vec); ++it){
        std::cout << *it << std::endl;
    }
}

void TestDeclType()
{
    auto i = 0; // signed int
    auto u = 0U;    // unsigned int
    auto f = 1.0f;  // float
    auto d = 2.0;   // double
    auto foo = new Foo; // Foo

    printf("%d, %u, %f, %f\n", i, u, f, d);

    // C++ is not dynamic type language.
    i = f;  // Cast happens.
//    foo = i;  // Of course NG.

    delete foo;

    //
    // auto is useful for template iterators.
    //
    std::vector<int> vec(10);
    for(auto it = begin(vec); it != end(vec); ++it){
        *it = 100;
    }

    print(vec);
}
