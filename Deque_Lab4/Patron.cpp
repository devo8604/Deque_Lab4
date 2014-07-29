//*************************************************************************
// TITLE: 			   	STL Deque Lab
// FILENAME:            Patron.cpp
// PREPARED FOR:        CS230
// PROGRAMMER(S):       Devon J. Smith
// DEVELOPMENT DATE:    07/28/14
// COMPILER USED:       Apple LLVM Version 5.1
// TARGET PLATFORM:     Mac OS X i386 & x86_64
//=================================================================
//                           PROJECT FILES
//    <LIST ALL PROGRAM AND HEADER FILES IN THE PROJECT HERE>
//		lab4.cpp (main)
//		Patron.h
//		Patron.cpp
//		HairPlace.h
//		HairPlace.cpp
//=================================================================
//   		REVISION HISTORY
//   List revisions made to the Program
//
//   DATE     PROGRAMMER            DESCRIPTION OF CHANGES MADE
//	 07/28/14 Devon J. Smith        Original
//
//=================================================================
//                          INCLUDE FILES
#include "Patron.h"
#include <string>

using namespace std;
//*******************************************************************************
//             Definition of member functions for class Entry
//*******************************************************************************
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