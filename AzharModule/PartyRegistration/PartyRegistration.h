#ifndef PARTYREGISTRATION_BY_AZHAR_PARTYREGISTRATION_H
#define PARTYREGISTRATION_BY_AZHAR_PARTYREGISTRATION_H
#include <iostream>
#include <fstream>
#include "Party.h"
#include "Candidate.h"
#include "PartyCandidate.h"
#include "nlohmann/json.hpp"
#include <vector>
using json=nlohmann::json;
class PartyRegistration{
static PartyRegistration* instance;
vector <Party*> parties;
PartyRegistration();
public:
    void exeaddCandidate(string partyName,string partyRegID);
    void addCandidate(PartyCandidate *candidate, std::string &partyName);
    static PartyRegistration* getInstance();
    void loginAdmin(string Adminname,string password);
    void addParty(Party* party);

};
#endif //PARTYREGISTRATION_BY_AZHAR_PARTYREGISTRATION_H
