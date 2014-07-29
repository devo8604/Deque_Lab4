//
//  HairPlace.cpp
//  Deque_Lab4
//
//  Created by Devon Smith on 7/28/14.
//  Copyright (c) 2014 Devon Smith. All rights reserved.
//

#include "HairPlace.h"
#include "Patron.h"
#include <deque>
#include <string>

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
        
        //Male Hairdresser
        if (manBusy == false && !menLine.empty())
        {
            manStartCut(menLine, timeOfDay);
            startManHaricutTime = timeOfDay;
            manBusy = true;
        }
        else if (manBusy == true && timeOfDay == (startManHaricutTime + 15))
        {
            menLine.pop_front();
            menHairTotalCustomers += 1;
            menHairTotalIncome += 21;
            
            if (!menLine.empty()) {
                manStartCut(menLine, timeOfDay);
                startManHaricutTime = timeOfDay;
            }
            else
            {
                manBusy = false;
            }
        }
        
        //Female Hairdresser
        if (womanBusy == false && !womenLine.empty())
        {
            womanStartCut(womenLine, timeOfDay);
            startWomanHaircutTime = timeOfDay;
            womanBusy = true;
        }
        else if (womanBusy == true && timeOfDay == (startWomanHaircutTime + 45))
        {
            womenLine.pop_front();
            womenHairTotaCustomers += 1;
            womenHairTotaIncome += 55.20;
            
            if (!womenLine.empty()) {
                womanStartCut(womenLine, timeOfDay);
                startWomanHaircutTime = timeOfDay;
            }
            else
            {
                womanBusy = false;
            }
        }
        
        //Unisex Hairdresser
        if (uniBusy == false && !bothLine.empty())
        {
            endUniHaircutTime = bothStartCut(bothLine, timeOfDay);
            startUniHaircutTime = timeOfDay;
            uniBusy = true;
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
                bothStartCut(bothLine, timeOfDay);
                endUniHaircutTime = bothStartCut(bothLine, timeOfDay);
                startUniHaircutTime = timeOfDay;
            }
            else
            {
                uniBusy = false;
            }
        }
        timeOfDay += 5;
    }
    
    cout << endl << "These are the stats at the end of the day: " << endl;
    
    cout << "The total stats for the male hairdresser was: " << menHairTotalCustomers << " customers served for a total of $" << menHairTotalIncome << " with " << menLine.size() << " customers remaining in line at the end of the day." << endl;
    
    cout << endl << "The total stats for the female hairdresser was: " << womenHairTotaCustomers << " customers served for a total of $" << womenHairTotaIncome << " with " << womenLine.size() << " customers remaining in line at the end of the day." << endl;
    
    cout << endl << "The total stats for the unisex hairdresser was: " << bothHairTotalCustomers << " customers served for a total of $" << womenHairTotaIncome << " with " << bothLine.size() << " customers remaining in line at the end of the day." << endl;
 }

void HairPlace::manStartCut(deque<Patron>& menLine, int timeOfDay)
{
    cout << menLine.front().getName() << " who arrived at " << menLine.front().getTimeIn() << " is now being served by the male hairdresser at time " << timeOfDay << "." << endl;
}

void HairPlace::womanStartCut(deque<Patron>& womenLine, int timeOfDay)
{
    cout << womenLine.front().getName() << " who arrived at " << womenLine.front().getTimeIn() << " is now being served by the female hairdresser at time " << timeOfDay << "." << endl;
}

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
}
