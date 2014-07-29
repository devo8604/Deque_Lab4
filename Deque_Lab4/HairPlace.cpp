//*************************************************************************
// TITLE: 			   	STL Deque Lab
// FILENAME:            HairPlace.cpp
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
#include "HairPlace.h"
#include "Patron.h"
#include <deque>
#include <string>
//*******************************************************************************
//             Definition of member functions for class Entry
//*******************************************************************************
using namespace std;

void HairPlace::hairCutAnalysis()
{
    //Variables
    int menHairTotalIncome = 0;
    int menHairTotalCustomers = 0;
    int startManHaricutTime = 0;
    bool manBusy = false;
    
    double womenHairTotaIncome = 0;
    int womenHairTotaCustomers = 0;
    int startWomanHaircutTime = 0;
    bool womanBusy = false;
    
    int bothHairTotalIncome = 0;
    int bothHairTotalCustomers = 0;
    int startUniHaircutTime = 0;
    int endUniHaircutTime = 0;
    bool uniBusy = false;
    
    int timeOfDay = 0;
    
    //Queues
    deque<Patron> menLine;
    deque<Patron> womenLine;
    deque<Patron> bothLine;
    
    srand((unsigned) 12345);
    while (timeOfDay < (8*60))
    {
        //The human object builder
        if (timeOfDay%10 == 0) //Manufactures humans every 10 minutes
        {
            int patronPicker = rand() % 10;
            if (patronPicker > 4) {
                womenLine.emplace_back(Patron("The Lady", "Female", timeOfDay));
            }
            else
            {
                menLine.emplace_back(Patron("The Dude", "Male", timeOfDay));
            }
        
            //Shuffles overcrowded lines to the bothline deque
            if (menLine.size() > 4)
            {
                cout << "A dude who arrived at " << menLine.back().getTimeIn() << " was transferred to the mixed line!" << endl;
                bothLine.emplace_front(menLine.back());
                menLine.pop_back();
            }
            else if (womenLine.size() > 4)
            {
                cout << "A chick who arrived at " << womenLine.back().getTimeIn() << " was transferred to the mixed line!" << endl;
                bothLine.emplace_front(womenLine.back());
                womenLine.pop_back();
            }
        }
        //Male Hairdresser
        if (manBusy == false && !menLine.empty())
        {
            manStartCut(menLine, timeOfDay);
            startManHaricutTime = timeOfDay;
            manBusy = true;
            cout << "The male hairdresser is busy" << endl;
        }
        else if (manBusy == true && timeOfDay == (startManHaricutTime + 15))
        {
            menLine.pop_front();
            menHairTotalCustomers += 1;
            menHairTotalIncome += 21;
            
            if (!menLine.empty()) {
                manStartCut(menLine, timeOfDay);
                startManHaricutTime = timeOfDay;
                cout << "The male hairdresser is on the next customer at " << timeOfDay << endl;
            }
            else
            {
                manBusy = false;
                cout << "The male hairdresser is idle at " << timeOfDay << endl;
            }
        }
        
        //Female Hairdresser
        if (womanBusy == false && !womenLine.empty())
        {
            womanStartCut(womenLine, timeOfDay);
            startWomanHaircutTime = timeOfDay;
            womanBusy = true;
            cout << "The female hairdresser is busy" << endl;
        }
        else if (womanBusy == true && timeOfDay == (startWomanHaircutTime + 45))
        {
            womenLine.pop_front();
            womenHairTotaCustomers += 1;
            womenHairTotaIncome += 55.20;
            
            if (!womenLine.empty()) {
                womanStartCut(womenLine, timeOfDay);
                startWomanHaircutTime = timeOfDay;
                cout << "The female hairdresser is on the next customer at " << timeOfDay << endl;
            }
            else
            {
                womanBusy = false;
                cout << "The female hairdresser is idle at " << timeOfDay << endl;
            }
        }
        
        //Unisex Hairdresser
        if (uniBusy == false && !bothLine.empty())
        {
            endUniHaircutTime = bothStartCut(bothLine, timeOfDay);
            startUniHaircutTime = timeOfDay;
            uniBusy = true;
            cout << "The unisex hairdresser is busy" << endl;
        }
        else if (uniBusy == true && timeOfDay == (startUniHaircutTime + endUniHaircutTime))
        {
            bothLine.pop_front();
            bothHairTotalCustomers += 1;
            
            if (endUniHaircutTime == 15)
            {
                bothHairTotalIncome += 25;
            }
            else if (endUniHaircutTime == 45)
            {
                bothHairTotalIncome += 57;
            }
            
            if (!bothLine.empty()) {
                endUniHaircutTime = bothStartCut(bothLine, timeOfDay);
                startUniHaircutTime = timeOfDay;
                cout << "The unisex hairdresser is on the next customer at " << timeOfDay << endl;
            }
            else
            {
                uniBusy = false;
                cout << "The unisex hairdresser is idle at " << timeOfDay << endl;
            }
        }
        timeOfDay += 5;
    } // END While loop
    
    //Outputs the stats after the while loop is done
    cout << endl << "These are the stats at the end of the day: " << endl;
    
    cout << "The total stats for the male hairdresser was: " << menHairTotalCustomers << " customers served for a total of $" << menHairTotalIncome << " with " << menLine.size() << " customers remaining in line at the end of the day." << endl;
    
    cout << endl << "The total stats for the female hairdresser was: " << womenHairTotaCustomers << " customers served for a total of $" << womenHairTotaIncome << " with " << womenLine.size() << " customers remaining in line at the end of the day." << endl;
    
    cout << endl << "The total stats for the unisex hairdresser was: " << bothHairTotalCustomers << " customers served for a total of $" << womenHairTotaIncome << " with " << bothLine.size() << " customers remaining in line at the end of the day." << endl;
 } // END hairCutAnalysis





void HairPlace::manStartCut(deque<Patron>& menLine, int timeOfDay)
{
    cout << menLine.front().getName() << " who arrived at " << menLine.front().getTimeIn() << " is now being served by the male hairdresser at time " << timeOfDay << "." << endl;
} // END manStartCut





void HairPlace::womanStartCut(deque<Patron>& womenLine, int timeOfDay)
{
    cout << womenLine.front().getName() << " who arrived at " << womenLine.front().getTimeIn() << " is now being served by the female hairdresser at time " << timeOfDay << "." << endl;
} // END womanStartCut





int HairPlace::bothStartCut(deque<Patron>& bothLine, int timeOfDay)
{
    
    int returnTime = 0;
    
        cout << bothLine.front().getName() << " who arrived at time " << bothLine.front().getTimeIn() << " is now being served by the unisex hairdresser at time " << timeOfDay << "." << endl;
    if (bothLine.front().getSex() == "Male")
    {
        returnTime = 15;
    }
    else if (bothLine.front().getSex() == "Female")
    {
        returnTime = 45;
    }
    return returnTime;
} // END bothStartCut
