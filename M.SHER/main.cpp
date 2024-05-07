#include <iostream>
#include <vector>
#include "Party.h"
#include "Voter.h"
#include "Candidate.h"
#include "ElectionMachine.h"
#include "Result.h"

using namespace std;

int main() {
    // Variables for user inputs
    string partyName;
    int numVoters, numCandidatesPresident, numCandidatesChairman, numCandidatesVC, numCandidatesGeneralSecretary;

    // Get party name
    cout << "Enter the name of the party: ";
    cin >> partyName;
    Party party(partyName);

    // Party Management Menu
    int partyChoice;
    do {
        cout << "\nParty Management Menu:";
        cout << "\n1. Add Member";
        cout << "\n2. Remove Member";
        cout << "\n3. Store Member Details";
        cout << "\n4. Manage Candidates";
        cout << "\n5. Exit Party Management";
        cout << "\nEnter your choice: ";
        cin >> partyChoice;

        switch (partyChoice) {
            case 1: {
                // Add Member
                string memberName;
                cout << "Enter member name: ";
                cin >> memberName;
                party.addMember(Person(memberName, 0, ""));
                break;
            }
            case 2: {
                // Remove Member
                string memberName;
                cout << "Enter member name to remove: ";
                cin >> memberName;
                party.removeMember(memberName);
                break;
            }
            case 3: {
                // Store Member Details
                string memberName, gender;
                int age;
                cout << "Enter member name: ";
                cin >> memberName;
                cout << "Enter member age: ";
                cin >> age;
                cout << "Enter member gender: ";
                cin >> gender;
                party.storeMemberDetails(memberName, age, gender);
                break;
            }
            case 4: {
                // Manage Candidates
                party.manageCandidates();
                break;
            }
            case 5:
                cout << "Exiting Party Management.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (partyChoice != 5);

    // Get the number of voters
    cout << "Enter the number of voters: ";
    cin >> numVoters;

    // Vector to store voters
    vector<Voter*> voters;

    // Get voter details
    for (int i = 0; i < numVoters; ++i) {
        string personName, personGender, voterID, CNIC, voterPassword;
        int personAge;
        cout << "\nEnter details for voter " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> personName;
        cout << "Age: ";
        cin >> personAge;
        cout << "Gender: ";
        cin >> personGender;
        cout << "Voter ID: ";
        cin >> voterID;
        cout << "CNIC: ";
        cin >> CNIC;
        cout << "Password: ";
        cin >> voterPassword;

        // Create new voter object and add to vector
        voters.push_back(new Voter(personName, personAge, personGender, voterID, CNIC, voterPassword));
    }

    // Add party members
    for (const auto& voter : voters) {
        party.addMember(*voter);
    }

    // Get number of candidates for each position
    cout << "\nEnter the number of candidates for President position: ";
    cin >> numCandidatesPresident;
    cout << "Enter the number of candidates for Chairman position: ";
    cin >> numCandidatesChairman;
    cout << "Enter the number of candidates for Vice Chairman position: ";
    cin >> numCandidatesVC;
    cout << "Enter the number of candidates for General Secretary position: ";
    cin >> numCandidatesGeneralSecretary;

    // Vector to store candidates
    vector<Candidate*> candidates;

    // Add candidates for each position
    cout << "\nEnter details for candidates:\n";
    for (int i = 0; i < numCandidatesPresident + numCandidatesChairman + numCandidatesVC + numCandidatesGeneralSecretary; ++i) {
        string name, gender, personalDetails;
        int age;
        string position;
        if (i < numCandidatesPresident)
            position = "President";
        else if (i < numCandidatesPresident + numCandidatesChairman)
            position = "Chairman";
        else if (i < numCandidatesPresident + numCandidatesChairman + numCandidatesVC)
            position = "Vice Chairman";
        else
            position = "General Secretary";

        cout << "\nDetails for " << position << " candidate " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        cin >> gender;
        cout << "Personal Details: ";
        cin.ignore(); // Clear newline character from previous input
        getline(cin, personalDetails); // Create new candidate object
        Candidate* candidate = new Candidate(name, age, gender, 0);

        // Register and verify candidate
        candidate->generatePaymentSlip();
        candidate->verifyPersonalDetails();
        candidate->checkCriminalRecord();

        // Nominate candidate
        candidates.push_back(candidate);
    }

    // Create ElectionMachine object
    ElectionMachine electionMachine(voters, candidates);

    // Conduct election phase
    electionMachine.conductElectionPhase();

    // Record votes
    for (auto& voter : voters) {
        cout << "\nCandidates for voting:" << endl;
        electionMachine.displayCandidatesForVoting(); // Display candidate names
        cout << "\nVoter: " << voter->getName() << " - Cast your vote:\n";
        string candidateName;
        cout << "Enter the name of the candidate you want to vote for: ";
        cin >> candidateName;
        cout << "Selected candidate name: " << candidateName << endl; // Debugging statement
        // Find the candidate object with the given name
        Candidate* selectedCandidate = nullptr;
        for (auto& candidate : candidates) {
            if (candidate->getName() == candidateName) {
                selectedCandidate = candidate;
                break;
            }
        }
        if (selectedCandidate != nullptr) {
            electionMachine.recordVote(voter, candidateName);
        } else {
            cout << "Candidate not found. Vote not recorded.\n";
        }
    }

    // Count votes
    electionMachine.countVotes();

    // Display results
    Result::getInstance()->showResult();

    // Deallocate memory for voters and candidates
    for (auto voter : voters) {
        delete voter;
    }
    for (auto candidate : candidates) {
        delete candidate;
    }

    return 0;
}
