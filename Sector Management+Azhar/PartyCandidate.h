#ifndef PARTYREGISTRATION_PARTYCANDIDATE_H
#define PARTYREGISTRATION_PARTYCANDIDATE_H
#include <iostream>
#include "Candidate.h"
using namespace std;

class PartyCandidate : public Candidate {
private:
    string candidateParty; // Party affiliation of the party candidate
    string candidateSymbol; // Symbol representing the party candidate
public:
    // Constructor with parameters
    PartyCandidate(string canName, string canCNIC, string canGender, string canDOB, string canParty, string canSymbol, Address& address);
    // Getter method to retrieve candidate's party affiliation
    const string getCandidateParty() const;
    // Getter method to retrieve candidate's symbol
    const string getCandidateSymbol() const;
    // Setter method to set candidate's party affiliation
    void setCandidateParty(string canParty);
    // Setter method to set candidate's symbol
    void setCandidateSymbol(const string& canSymbol);
    // Method to nominate a sector (override from base class)
    void nominateOnSector(const string& secName);
};


#endif //PARTYREGISTRATION_PARTYCANDIDATE_H
