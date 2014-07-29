//*************************************************************************
// TITLE: 			   	STL Deque Lab
// FILENAME:            HairPlace.h
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
//
//  This class generates the people and puts them in line. It is also where
//  the all of the stats are collected at the end of the day and output.
//
//*******************************************************************************
//
//*******************************************************************************
//              PROCESS THIS FILE ONLY ONCE PER PROJECT
//
#ifndef __Deque_Lab4__HairPlace__
#define __Deque_Lab4__HairPlace__
//
//======================================================================
//                     CONSTANT DEFINITIONS
//
//*******************************************************************************
//                  STANDARD AND USER DEFINED INCLUDES
#include "Patron.h"
#include <iostream>
#include <deque>
//*******************************************************************************
//                     USER DEFINED DATA TYPES
class HairPlace
{
public:
    void hairCutAnalysis(); //Function that handles the majority of processing
    
private:
    //The following functions just assign customers to the hairdressers at the appropriate time
    void manStartCut(std::deque<Patron>& menLine, int timeOfDay);
    void womanStartCut(std::deque<Patron>& womenLine, int timeOfDay);
    int bothStartCut(std::deque<Patron>& bothLine, int timeOfDay);
};
//*******************************************************************************
//                    END OF CONDITIONAL BLOCK
#endif /* defined(__Deque_Lab4__HairPlace__) */
//*******************************************************************************
//                      END OF HEADER FILE
//*******************************************************************************