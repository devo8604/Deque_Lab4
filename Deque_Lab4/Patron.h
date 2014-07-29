//
//  Patron.h
//  Deque_Lab4
//
//  Created by Devon Smith on 7/28/14.
//  Copyright (c) 2014 Devon Smith. All rights reserved.
//

#ifndef __Deque_Lab4__Patron__
#define __Deque_Lab4__Patron__

#include <iostream>
#include <string>



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

#endif /* defined(__Deque_Lab4__Patron__) */