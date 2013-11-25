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

//
//
//
class Person
{
public:
	enum PersonType { ADULT, CHILD, SENIOR };

	void setPersonType (PersonType person_type){
		_person_type = person_type;
	}

	PersonType getPersonType ();
private:
	PersonType _person_type;
};

#if 0	// old
Person::PersonType Person::getPersonType ()
{
    return _person_type;
}
#else	// with trailing return type
auto Person::getPersonType () -> PersonType
{
    return _person_type;
}
#endif

//
//
//
class A{};
class B{};

class BuilderA
{
public:
	BuilderA(){}
	A Build(){
		return A();
	}
};

class BuilderB
{
public:
	BuilderB(){}
	B Build(){
		return B();
	}
};

template <typename Builder>
auto BuildSomething(Builder builder) -> decltype(builder.Build())
{
	return builder.Build();
}

}

auto TestDeclType() -> void
{
	// Trailing return type sample.
	Person person;
	person.getPersonType();


	// decltype sample.
	int x = 3;
	decltype(x) y = x; // same thing as auto y = x;

	//decltype(Person::getPersonType()) type1;	// NG
	decltype(person.getPersonType()) type2 = person.getPersonType();

	auto A = BuildSomething(BuilderA());
	auto B = BuildSomething(BuilderB());
	
}
