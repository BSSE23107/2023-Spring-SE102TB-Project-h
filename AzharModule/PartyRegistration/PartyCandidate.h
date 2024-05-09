
#ifndef PARTYREGISTRATION_BY_AZHAR_PARTYCANDIDATE_H
#define PARTYREGISTRATION_BY_AZHAR_PARTYCANDIDATE_H
#include "Candidate.h"
class PartyCandidate:public Candidate{
    string candidateParty;
public:
    PartyCandidate( string canName, string canCNIC, string canGender, string canDOB,string canParty,Address& address );
    const string getCandidateParty() const;
    void setCandidateParty(string canParty);
    void nominateOnSector(const string& secName);

};
#endif //PARTYREGISTRATION_BY_AZHAR_PARTYCANDIDATE_H
