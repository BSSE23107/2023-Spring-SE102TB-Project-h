#include "PartyCandidate.h"

// Constructor with parameters
PartyCandidate::PartyCandidate(std::string canName, std::string canCNIC, std::string canGender, std::string canDOB,
                               std::string canParty, string canSymbol, Address &address) {
    // Initialize person's information
    setPersonName(canName);
    setPersonCNIC(canCNIC);
    setDateOfBirth(canDOB);
    setPersonGender(canGender);
    setPersonAddress(address);

    // Initialize candidate's party and symbol
    candidateParty = canParty;
    candidateSymbol = canSymbol;

    // Initialize other attributes
    setWonStatus(false); // Candidate has not won yet
    setPosition(0); // Candidate's initial position
    setVoteCount(0); // Candidate's initial vote count
}

// Getter method to retrieve candidate's party affiliation
const string PartyCandidate::getCandidateParty() const {
    return candidateParty;
}

// Setter method to set candidate's party affiliation
void PartyCandidate::setCandidateParty(std::string canParty) {
    candidateParty = canParty;
}

// Method to nominate a sector (override from base class)
void PartyCandidate::nominateOnSector(const string &secName) {
    // Implementation to nominate a sector can be added here
    PartyRegistration *partyRegistration = PartyRegistration::getInstance();
    partyRegistration->nominatedCandidate(this,secName);
    nominatedSectors.push_back(secName);
}

// Getter method to retrieve candidate's symbol
const string PartyCandidate::getCandidateSymbol() const {
    return candidateSymbol;
}

// Setter method to set candidate's symbol
void PartyCandidate::setCandidateSymbol(const std::string &canSymbol) {
    candidateSymbol = canSymbol;
}
