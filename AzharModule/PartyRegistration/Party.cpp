
#include "Party.h"

int Party::ID = 0;

Party::Party(string parName, string parAdmin, string parPassword)
:partyName(parName),adminName(parAdmin),password(parPassword)
{
    time_t now = time(0);
    tm* localTime = localtime(&now);
    string currentYear = to_string(localTime->tm_year + 1900);
    ifstream getPartyID("partyRegistrationIDs.txt");
    string IDs;
    int count=0;
    while(getline(getPartyID,IDs)){
        count++;
    }
    if (count==0){
        ID++;
    } else if(count>0){
        ID=count+1;
    }
    registrationID="PAR-"+currentYear+"-"+ to_string(ID);

}

const string Party::getPartyName() const {
    return partyName;
}

const string Party::getAdminName() const {
    return adminName;
}

const string Party::getPassword() const {
    return password;

}

const string Party::getRegistrationID() const {
    return registrationID;
}

void Party::setPartyName(string &name) {
    partyName = name;
}

void Party::setAdminName(string &admin) {
    adminName = admin;
}


void Party::setPassword(string &pass) {
    password = pass;
}

void Party::addCandidates(Candidate *candidate) {
    partyCandidates.push_back(candidate);
}