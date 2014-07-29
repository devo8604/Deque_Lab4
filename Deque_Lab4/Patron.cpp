//
//  Patron.cpp
//  Deque_Lab4
//
//  Created by Devon Smith on 7/28/14.
//  Copyright (c) 2014 Devon Smith. All rights reserved.
//

#include "Patron.h"
#include <string>

using namespace std;

string name;
string sex;
int timeIn;

Patron::Patron(string name,
               string sex,
               int timeIn)
{
    setName(name);
    setSex(sex);
    setTimeIn(timeIn);
}

void Patron::setName(string inName)
{
    name = inName;
}

void Patron::setSex(string inSex)
{
    sex = inSex;
}

void Patron::setTimeIn(int inTime)
{
    timeIn = inTime;
}

string Patron::getName()
{
    return name;
}

string Patron::getSex()
{
    return sex;
}

int Patron::getTimeIn()
{
    return timeIn;
}