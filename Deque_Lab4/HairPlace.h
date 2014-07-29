//
//  HairPlace.h
//  Deque_Lab4
//
//  Created by Devon Smith on 7/28/14.
//  Copyright (c) 2014 Devon Smith. All rights reserved.
//

#ifndef __Deque_Lab4__HairPlace__
#define __Deque_Lab4__HairPlace__

#include "Patron.h"
#include <iostream>
#include <deque>

class HairPlace
{
public:
    void hairCutAnalysis();
    
private:
    void manStartCut(std::deque<Patron>& menLine, int timeOfDay);
    void womanStartCut(std::deque<Patron>& womenLine, int timeOfDay);
    int bothStartCut(std::deque<Patron>& bothLine, int timeOfDay);
};


#endif /* defined(__Deque_Lab4__HairPlace__) */
