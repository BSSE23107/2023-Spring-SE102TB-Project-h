
#include "Voter.h"
Voter::Voter() {}
Voter::Voter(string name, string dob,string gender,string sector,bool isalive,bool hasVoted):sector(sector),hasVoted(hasVoted),isAlive(isalive),
                                                                                             Person(name,dob,gender) {}