#ifndef PARTYREGISTRATION_PARTY_H
#define PARTYREGISTRATION_PARTY_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Candidate.h"
using namespace std;

class Party {
private:
    string registrationID; // Registration ID of the party
    static int ID; // Static member to generate unique registration IDs
    string partyName; // Name of the party
    string adminName; // Name of the party's administrator
    string password; // Password for party authentication
    string partySymbol; // Symbol representing the party
    vector<Candidate*> partyCandidates; // Vector to store the candidates belonging to the party
public:
    // Constructor with parameters
    Party(string parName, string parAdmin, string parPassword, string partySymbol);
    // Getter method to retrieve party's name
    const string getPartyName() const;
    // Getter method to retrieve party administrator's name
    const string getAdminName() const;
    // Getter method to retrieve party's password
    const string getPassword() const;
    // Getter method to retrieve party's registration ID
    const string getRegistrationID() const;
    // Getter method to retrieve party's symbol
    const string getPartySymbol() const;
    // Setter method to set party's name
    void setPartyName(string &name);
    // Setter method to set party administrator's name
    void setAdminName(string &admin);
    // Setter method to set party's password
    void setPassword(string& pass);
    // Setter method to set party's symbol
    void setPartySymbol(string& symbol);
    // Method to add a candidate to the party
    void addCandidates(Candidate* candidate);
};


#endif //PARTYREGISTRATION_PARTY_H
