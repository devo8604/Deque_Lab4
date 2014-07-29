//*************************************************************************
// TITLE: 			   	STL Deque Lab
// FILENAME:            Patron.h
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
//                        CLASS DESCRIPTION
//  This this the class where the people are created
//
//*******************************************************************************
//
//*******************************************************************************
//              PROCESS THIS FILE ONLY ONCE PER PROJECT
//
#ifndef __Deque_Lab4__Patron__
#define __Deque_Lab4__Patron__
//
//======================================================================
//                     CONSTANT DEFINITIONS
//
//*******************************************************************************
//                  STANDARD AND USER DEFINED INCLUDES
#include <iostream>
#include <string>
//*******************************************************************************
//                     USER DEFINED DATA TYPES
class Patron
{
public:
    //Constructor and getters
    Patron(std::string name,
           std::string sex,
           int timeIn);
    
    std::string getName();
    std::string getSex();
    int getTimeIn();
    
private:
    //Variables
    std::string name;
    std::string sex;
    int timeIn;
    
    //Setters
    void setName(std::string inName);
    void setSex(std::string inSex);
    void setTimeIn(int inTime);
};
//*******************************************************************************
//                    END OF CONDITIONAL BLOCK
#endif /* defined(__Deque_Lab4__Patron__) */
//*******************************************************************************
//                      END OF HEADER FILE
//*******************************************************************************