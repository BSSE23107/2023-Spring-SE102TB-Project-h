
#ifndef PARTYREGISTRATION_BY_AZHAR_PARTY_H
#define PARTYREGISTRATION_BY_AZHAR_PARTY_H
#include <string>
#include "Candidate.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Party{
    string registrationID;
    static int ID;
    string partyName;
    string adminName;
    string password;
    vector<Candidate*> partyCandidates;
public:
    Party(string parName, string parAdmin, string parPassword);
    const string getPartyName() const;
    const string getAdminName() const;
    const string getPassword() const;
    const string getRegistrationID() const;
    void setPartyName(string &name);
    void setAdminName(string &admin);
    void setPassword(string& pass);
    virtual void addCandidates(Candidate* candidate);

};
#endif //PARTYREGISTRATION_BY_AZHAR_PARTY_H
