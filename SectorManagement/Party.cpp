#include "Party.h"

int Party::ID = 0;

// Constructor with parameters
Party::Party(std::string parName, std::string parAdmin, std::string parPassword, string partySymbol) {
    // Get current time
    time_t now = time(0);
    tm* localTime = localtime(&now);
    string currentYear = to_string(localTime->tm_year + 1900);

    // Read existing registration IDs from file
    ifstream getPartyID("partyRegistrationIDs.txt");
    string IDs;
    int count = 0;
    while(getline(getPartyID, IDs)){
        count++;
    }

    // Increment ID based on existing count
    if(count == 0){
        ID++;
    } else if(count > 0){
        ID = count + 1;
    }

    // Generate registration ID
    registrationID = "PAR-" + currentYear + "-" + to_string(ID);

    // Set party attributes
    partyName = parName;
    adminName = parAdmin;
    password = parPassword;
    this -> partySymbol = partySymbol;
}

// Getter method to retrieve party's name
const string Party::getPartyName() const {
    return partyName;
}

// Getter method to retrieve party administrator's name
const string Party::getAdminName() const {
    return adminName;
}

// Getter method to retrieve party's password
const string Party::getPassword() const {
    return password;
}

// Getter method to retrieve party's registration ID
const string Party::getRegistrationID() const {
    return registrationID;
}

// Setter method to set party's name
void Party::setPartyName(std::string &name) {
    partyName = name;
}

// Setter method to set party administrator's name
void Party::setAdminName(std::string &admin) {
    adminName = admin;
}

// Setter method to set party's password
void Party::setPassword(std::string &pass) {
    password = pass;
}

// Method to add a candidate to the party
void Party::addCandidates(Candidate *candidate) {
    partyCandidates.push_back(candidate);
}

// Getter method to retrieve party's symbol
const string Party::getPartySymbol() const {
    return partySymbol;
}

// Setter method to set party's symbol
void Party::setPartySymbol(std::string &symbol) {
    partySymbol = symbol;
}