//
//  auto.cpp
//  cpp11fun
//
//  Created by Fumihiko Tanuma on 11/19/13.
//  Copyright (c) 2013 ftanuma. All rights reserved.
//
#include "auto.h"
#include <vector>
#include <iostream>

namespace {
    class Foo{
    public:
        Foo()
		: m_foo(1000)
		{}

		int & fooRef(){
			return m_foo;
		}

		int * fooPointer(){
			return &m_foo;
		}

		const int * fooConstPointer() const {
			return &m_foo;
		}

		int m_foo;
    };
}

static void print_const(const std::vector<int> &vec)
{
    // following "auto it" should be const iterator.
    for(auto it = begin(vec); it != end(vec); ++it){
        std::cout << *it << std::endl;
    }
}

static void print_nonconst(std::vector<int> &vec)
{
    // following "auto it" is not const iterator.
    for(auto it = begin(vec); it != end(vec); ++it){
        std::cout << *it << std::endl;
    }
}

void TestAuto()
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

    //
    // auto is useful for template iterators.
    //
    std::vector<int> vec(10);
    for(auto it = begin(vec); it != end(vec); ++it){
        *it = 100;
    }

    print_const(vec);
    print_nonconst(vec);

	// References
	//
	{
		auto bar = foo->fooRef(); // int: in C++11, auto defaults to being by-value for references.
		auto& baz = foo->fooRef(); // int&

		const auto cbar = foo->fooRef();	// const int
		const auto &cbaz = foo->fooRef();	// const int &
	}

	// Pointerss
	//
	{
		auto bar = foo->fooPointer();	// int*
		auto *pBar = foo->fooPointer();	// int*

		const auto cbar = foo->fooPointer();	// int * const
		const auto *cpBar = foo->fooPointer();	// const int*
	}
	{
		auto bar = foo->fooConstPointer();	// cosnt int*
		auto *pBar = foo->fooConstPointer();	// const int*

		const auto cbar = foo->fooConstPointer();	// const int * const
		const auto *cpBar = foo->fooConstPointer();	// const int*
	}



	delete foo;
}
