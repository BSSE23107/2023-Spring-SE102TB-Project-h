#ifndef PROJECT_OOP_PARTY_H
#define PROJECT_OOP_PARTY_H

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Person.h"
#include "Candidate.h"

class Party {
private:
    string name;
    vector<Person> members;
    vector<Candidate*> candidates;

public:
    Party(const string& partyName);
    void saveToFile(const string& filename, const vector<Person>& data)const;
    void saveToFile(const string& filename, const vector<Candidate*>& data)const;
    void loadFromFile(const string& filename, vector<Candidate*>& data);
    void loadFromFile(const string& filename, vector<Person>& data);
    void addMember(const Person& member);
    void removeMember(const string& memberName);
    void storeMemberDetails(const string& memberName, int age, const string& gender);
    void manageCandidates();
    void addCandidate();
    void removeCandidate();
    void displayCandidates()const;
    static void displayCandidateManagementMenu();
    void handleCandidateManagementChoice(int choice);
};


#endif // PARTY_H
