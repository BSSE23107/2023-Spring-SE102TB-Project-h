#ifndef PARTYREGISTRATION_PARTYREGISTRATION_H
#define PARTYREGISTRATION_PARTYREGISTRATION_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Party.h"
#include "PartyCandidate.h"
#include "Provinces.h"
#include "exeAddCandidate.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;


class PartyRegistration {
private:
    static PartyRegistration* instance; // Singleton instance of PartyRegistration
    vector<Party*> parties; // Vector to store registered parties
    PartyRegistration(); // Private constructor to prevent external instantiation
public:
    // Method to get the singleton instance of PartyRegistration
    static PartyRegistration* getInstance();
    // Method to add a party to the registration system
    void addParty(Party* party);
    // Method to add a candidate to a party
    void addCandidate(PartyCandidate* candidate, string& partyName);
    // Method to nominate a candidate from a party on a sector
    void nominatedCandidate(PartyCandidate* partyCandidate, string& sectorCode);
    // Method to authenticate the admin login
    void loginAdmin(string adminName, string password);
};




#endif //PARTYREGISTRATION_PARTYREGISTRATION_H
