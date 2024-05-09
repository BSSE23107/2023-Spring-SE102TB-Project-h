//
// Created by azhar on 21/04/2024.
//

#ifndef STATISTICS_VOTER_H
#define STATISTICS_VOTER_H
#include "Person.h"
class Voter:public Person{
string sector;
bool isAlive{};
bool hasVoted{};
public:
    Voter();
    Voter(string name, string dob,string gender,string sector,bool isalive,bool hasVoted);
};
#endif //STATISTICS_VOTER_H
