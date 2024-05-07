#include "ElectionMachine.h"
#include "Voter.h"
#include "Candidate.h"
#include "Result.h"
#include <iostream>
#include <algorithm>

ElectionMachine::ElectionMachine(const vector<Voter*>& voters, const vector<Candidate*>& candidates)
        : phase(""), voterList(voters), candidateList(candidates), result(Result::getInstance()) {}

void ElectionMachine::conductElectionPhase() {
    cout << "Enter the phase of the election: ";
    cin >> phase;
    cout << "Election phase: " << phase << endl;
}

void ElectionMachine::displayCandidatesForVoting() {
    cout << "Candidates for voting in " << phase << " phase:" << endl;
    for (const auto& candidate : candidateList) {
        cout << candidate->getName() << " - Position: " << candidate->getPosition() << endl;
    }
}

void ElectionMachine::recordVote(Voter* voter, const string& candidateName) {
    Candidate* foundCandidate = nullptr;
    for (Candidate* candidate : candidateList) {
        if (candidate->getName() == candidateName) {
            foundCandidate = candidate;
            break;
        }
    }
    if (foundCandidate != nullptr) {
        foundCandidate->incrementVoteCount();
        voter->setSelectedCandidate(candidateName);
        voter->setHasVoted(true);
        cout << "Selected candidate name: " << voter->getSelectedCandidate() << endl;
        cout << "Vote recorded for " << foundCandidate->getName() << endl;
    } else {
        cout << "Candidate is not valid." << endl;
    }
}

void ElectionMachine::countVotes() {
    // Initialize voteCounts vector with each candidate's vote count set to 0
    voteCounts.assign(candidateList.size(), 0);
    // Count votes
    for (const auto& voter : voterList) {
        const string& candidateName = voter->getSelectedCandidate();
        if (!candidateName.empty()) {
            auto it = find_if(candidateList.begin(), candidateList.end(), [&](const Candidate* candidate) {
                return candidate->getName() == candidateName;
            });
            if (it != candidateList.end()) {
                int index = distance(candidateList.begin(), it);
                voteCounts[index]++;
            }
        }
    }
    // Optionally, you can display the vote counts for each candidate
    for (size_t i = 0; i < voteCounts.size(); ++i) {
        cout << candidateList[i]->getName() << ": " << voteCounts[i] << " votes" << endl;
    }
}

