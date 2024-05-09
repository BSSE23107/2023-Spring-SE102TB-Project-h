
#ifndef PARTYREGISTRATION_CANDIDATE_H
#define PARTYREGISTRATION_CANDIDATE_H
#include <iostream>
#include "Person.h"
#include <vector>
#include "Voter.h"
using namespace std;

#include "Voter.h" // Assuming Voter class is defined and included
 // Using std namespace for convenience

class Candidate : public Voter {
private:
    bool isWon; // Flag to indicate whether the candidate has won the election
    int voteCount; // Count of votes received by the candidate
    int position; // Position of the candidate in the election
protected:
    vector<string> nominatedSectors; // Vector to store the sectors nominated by the candidate
public:
    // Default constructor
    Candidate();
    // Getter method to retrieve candidate's position
    int getPosition();
    // Getter method to retrieve candidate's vote count
    const int getVoteCount() const;
    // Getter method to retrieve candidate's win status
    bool getWonStatus();
    // Setter method to set candidate's vote count
    void setVoteCount(int count);
    // Setter method to set candidate's win status
    void setWonStatus(bool status);
    // Setter method to set candidate's position
    void setPosition(int canPos);
    // Virtual method to nominate a sector (to be implemented by derived classes)
    virtual void nominateOnSector(const string &sectorName) = 0;
};



#endif //PARTYREGISTRATION_CANDIDATE_H
