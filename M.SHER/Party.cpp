#include "Party.h"
#include <iostream>
#include <fstream>

Party::Party(const string& partyName) : name(partyName) {
    loadFromFile("Members.txt", members);
    loadFromFile("Candidates.txt", candidates);
}

void Party::addMember(const Person& member) {
    members.push_back(member);
    saveToFile("Members.txt", members);
}

void Party::removeMember(const string& memberName) {
    auto it = find_if(members.begin(), members.end(), [&](const Person& p) { return p.getName() == memberName; });
    if (it != members.end()) {
        members.erase(it);
        saveToFile("Members.txt", members);
    } else {
        cout << "Member not found." << endl;
    }
}
void Party::storeMemberDetails(const string& memberName, int age, const string& gender) {
    members.emplace_back(memberName, age, gender);
    saveToFile("Members.txt", members);
}

void Party::manageCandidates() {
    int choice;
    do {
        displayCandidateManagementMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        handleCandidateManagementChoice(choice);
    } while (choice != 4);
}

void Party::displayCandidateManagementMenu() {
    cout << "\nCandidate Management Menu:" << endl;
    cout << "1. Add Candidate" << endl;
    cout << "2. Remove Candidate" << endl;
    cout << "3. Display Candidate List" << endl;
    cout << "4. Exit Candidate Management" << endl;
}
void Party::handleCandidateManagementChoice(int choice) {
    switch (choice) {
        case 1:
            addCandidate();
            break;
        case 2:
            removeCandidate();
            break;
        case 3:
            displayCandidates();
            break;
        case 4:
            cout << "Exiting Candidate Management." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

void Party::addCandidate() {
    string candidateName;
    int age;
    string gender;
    cout << "Enter candidate name: ";
    cin >> candidateName;
    cout << "Enter candidate age: ";
    cin >> age;
    cout << "Enter candidate gender (M/F): ";
    cin >> gender;
    Candidate* newCandidate = new Candidate(candidateName, age, gender, 0);
    candidates.push_back(newCandidate);
    saveToFile("Candidates.txt", candidates);
    cout << "Candidate added successfully." << endl;
}

void Party::removeCandidate() {
    if (candidates.empty()) {
        cout << "No candidates to remove." << endl;
    } else {
        string candidateName;
        cout << "Enter candidate name to remove: ";
        cin >> candidateName;
        auto it = find_if(candidates.begin(), candidates.end(), [&](const Candidate* c) { return c->getName() == candidateName; });
        if (it != candidates.end()) {
            candidates.erase(it);
            saveToFile("Candidates.txt", candidates);
            cout << "Candidate removed successfully." << endl;
        } else {
            cout << "Candidate not found." << endl;
        }
    }
}


void Party::displayCandidates() const {
    if (candidates.empty()) {
        cout << "No candidates to display." << endl;
    } else {
        cout << "Candidate List:" << endl;
        for (const auto &candidate: candidates) {
            cout << "Name: " << candidate->getName() << ", Age: " << candidate->getAge() << ", Gender: "
                 << candidate->getGender() << endl;
        }
    }
}
    void Party::loadFromFile(const string &filename, vector<Person> &data) {
        ifstream file(filename);
        if (file.is_open()) {
            string name, gender;
            int age;
            while (file >> name >> age >> gender) {
                data.emplace_back(name, age, gender);
            }
            file.close();
        }
    }

    void Party::loadFromFile(const string& filename, vector<Candidate*>& data) {
        ifstream file(filename);
        if (file.is_open()) {
            string name, gender;
            int age;
            while (file >> name >> age >> gender) {
                data.push_back(new Candidate(name, age, gender, 0));
            }
            file.close();
        }
    }
    void Party::saveToFile(const string& filename, const vector<Person>& data) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& item : data) {
                file << item.getName() << " " << item.getAge() << " " << item.getGender() << endl;
            }
            file.close();
        }
    }

    void Party::saveToFile(const string& filename, const vector<Candidate*>& data) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& item : data) {
                file << item->getName() << " " << item->getAge() << " " << item->getGender() << endl;
            }
            file.close();
        }
    }
