#include "Person.h"
#ifndef PARTYREGISTRATION_BY_AZHAR_CANDIDATE_H
#define PARTYREGISTRATION_BY_AZHAR_CANDIDATE_H
#include <vector>
#include <string>
class Candidate :public Person{
    vector<string> nominatedSectors;
    bool isWon;
    int voteCount;
    int position;
public:
    Candidate();
    int getPosition();
    const int getVoteCount() const;
    bool getWonStatus();
    void setVoteCount(int count);
    void setWonStatus(bool status);
    void setPosition(int canPos);
    virtual void nominateOnSector(const string &sectorName) = 0;
};
#endif //PARTYREGISTRATION_BY_AZHAR_CANDIDATE_H
