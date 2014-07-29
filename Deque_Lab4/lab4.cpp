//*************************************************************************
// TITLE: 			   	STL Deque Lab
// FILENAME:            lab4.cpp
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
//
//=================================================================
//   			PROGRAM DESCRIPTION
//
// This application analyzes 3 hairdressers, one for the dudes, one for the ladies,
// and one that handles both sexes "the overflow guy". The program calculates the amount of
// customers processed, total income for the day, and how many customers were left standing
// in line at the end of the day.
//
// INPUTS: NONE
//
// OUTPUTS:  Hair customer processing analysis
//
//=================================================================
//                          INCLUDE FILES
#include "HairPlace.h"
//
//=================================================================
//                        CONSTANT DEFINITIONS
//                             NONE
//
//=================================================================
//                      EXTERNAL CLASS VARIABLES
//                          NONE
//=================================================================
//
//*************************************************************************
//                     BEGINNING OF PROGRAM CODE
//*************************************************************************
int main(int argc, const char * argv[])
{
    HairPlace hairplace;
    hairplace.hairCutAnalysis();
    return 0;
}

/* <<<<< PROGRAM OUTPUT >>>>>
 The Lady who arrived at 0 is now being served by the female hairdresser at time 0.
 The female hairdresser is busy
 The Dude who arrived at 10 is now being served by the male hairdresser at time 10.
 The male hairdresser is busy
 The male hairdresser is idle at 25
 The Dude who arrived at 40 is now being served by the male hairdresser at time 40.
 The male hairdresser is busy
 The Lady who arrived at 20 is now being served by the female hairdresser at time 45.
 The female hairdresser is on the next customer at 45
 The male hairdresser is idle at 55
 The Dude who arrived at 60 is now being served by the male hairdresser at time 60.
 The male hairdresser is busy
 The Dude who arrived at 70 is now being served by the male hairdresser at time 75.
 The male hairdresser is on the next customer at 75
 The Dude who arrived at 80 is now being served by the male hairdresser at time 90.
 The male hairdresser is on the next customer at 90
 The Lady who arrived at 30 is now being served by the female hairdresser at time 90.
 The female hairdresser is on the next customer at 90
 The Dude who arrived at 100 is now being served by the male hairdresser at time 105.
 The male hairdresser is on the next customer at 105
 The Dude who arrived at 110 is now being served by the male hairdresser at time 120.
 The male hairdresser is on the next customer at 120
 The Dude who arrived at 120 is now being served by the male hairdresser at time 135.
 The male hairdresser is on the next customer at 135
 The Lady who arrived at 50 is now being served by the female hairdresser at time 135.
 The female hairdresser is on the next customer at 135
 The Dude who arrived at 140 is now being served by the male hairdresser at time 150.
 The male hairdresser is on the next customer at 150
 The Dude who arrived at 150 is now being served by the male hairdresser at time 165.
 The male hairdresser is on the next customer at 165
 The Dude who arrived at 160 is now being served by the male hairdresser at time 180.
 The male hairdresser is on the next customer at 180
 The Lady who arrived at 90 is now being served by the female hairdresser at time 180.
 The female hairdresser is on the next customer at 180
 The Dude who arrived at 170 is now being served by the male hairdresser at time 195.
 The male hairdresser is on the next customer at 195
 A chick who arrived at 210 was transferred to the mixed line!
 The Dude who arrived at 200 is now being served by the male hairdresser at time 210.
 The male hairdresser is on the next customer at 210
 The Lady who arrived at time 210 is now being served by the unisex hairdresser at time 210.
 The unisex hairdresser is busy
 A chick who arrived at 220 was transferred to the mixed line!
 The male hairdresser is idle at 225
 The Lady who arrived at 130 is now being served by the female hairdresser at time 225.
 The female hairdresser is on the next customer at 225
 The Dude who arrived at 230 is now being served by the male hairdresser at time 230.
 The male hairdresser is busy
 The male hairdresser is idle at 245
 A chick who arrived at 250 was transferred to the mixed line!
 The Lady who arrived at time 220 is now being served by the unisex hairdresser at time 255.
 The unisex hairdresser is on the next customer at 255
 The Dude who arrived at 260 is now being served by the male hairdresser at time 260.
 The male hairdresser is busy
 A chick who arrived at 270 was transferred to the mixed line!
 The Lady who arrived at 180 is now being served by the female hairdresser at time 270.
 The female hairdresser is on the next customer at 270
 The male hairdresser is idle at 275
 The Dude who arrived at 290 is now being served by the male hairdresser at time 290.
 The male hairdresser is busy
 A chick who arrived at 300 was transferred to the mixed line!
 The Lady who arrived at time 270 is now being served by the unisex hairdresser at time 300.
 The unisex hairdresser is on the next customer at 300
 The male hairdresser is idle at 305
 A chick who arrived at 310 was transferred to the mixed line!
 The Lady who arrived at 190 is now being served by the female hairdresser at time 315.
 The female hairdresser is on the next customer at 315
 The Dude who arrived at 330 is now being served by the male hairdresser at time 330.
 The male hairdresser is busy
 A chick who arrived at 340 was transferred to the mixed line!
 The male hairdresser is idle at 345
 The Lady who arrived at time 310 is now being served by the unisex hairdresser at time 345.
 The unisex hairdresser is on the next customer at 345
 The Dude who arrived at 350 is now being served by the male hairdresser at time 350.
 The male hairdresser is busy
 The Lady who arrived at 240 is now being served by the female hairdresser at time 360.
 The female hairdresser is on the next customer at 360
 The Dude who arrived at 360 is now being served by the male hairdresser at time 365.
 The male hairdresser is on the next customer at 365
 A chick who arrived at 380 was transferred to the mixed line!
 The male hairdresser is idle at 380
 A chick who arrived at 390 was transferred to the mixed line!
 The Lady who arrived at time 380 is now being served by the unisex hairdresser at time 390.
 The unisex hairdresser is on the next customer at 390
 The Dude who arrived at 400 is now being served by the male hairdresser at time 400.
 The male hairdresser is busy
 The Lady who arrived at 280 is now being served by the female hairdresser at time 405.
 The female hairdresser is on the next customer at 405
 The male hairdresser is idle at 415
 A chick who arrived at 420 was transferred to the mixed line!
 The Dude who arrived at 430 is now being served by the male hairdresser at time 430.
 The male hairdresser is busy
 The Lady who arrived at time 380 is now being served by the unisex hairdresser at time 435.
 The unisex hairdresser is on the next customer at 435
 The Dude who arrived at 440 is now being served by the male hairdresser at time 445.
 The male hairdresser is on the next customer at 445
 A chick who arrived at 450 was transferred to the mixed line!
 The Lady who arrived at 320 is now being served by the female hairdresser at time 450.
 The female hairdresser is on the next customer at 450
 The Dude who arrived at 460 is now being served by the male hairdresser at time 460.
 The male hairdresser is on the next customer at 460
 The male hairdresser is idle at 475
 
 These are the stats at the end of the day:
 The total stats for the male hairdresser was: 23 customers served for a total of $483 with 0 customers remaining in line at the end of the day.
 
 The total stats for the female hairdresser was: 10 customers served for a total of $552 with 4 customers remaining in line at the end of the day.
 
 The total stats for the unisex hairdresser was: 5 customers served for a total of $552 with 6 customers remaining in line at the end of the day.
*/