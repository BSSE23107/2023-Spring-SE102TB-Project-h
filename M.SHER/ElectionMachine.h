#ifndef PROJECT_OOP_ELECTIONMACHINE_H
#define PROJECT_OOP_ELECTIONMACHINE_H


#include <vector>
#include <string>
using namespace std;

class Voter;
class Candidate;
class Result;

class ElectionMachine {
private:
    vector<int> voteCounts;
    string phase;
    vector<Voter*> voterList;
    vector<Candidate*> candidateList;
    Result* result;

public:
    ElectionMachine(const vector<Voter*>& voters, const vector<Candidate*>& candidates);
    void conductElectionPhase();
    void displayCandidatesForVoting();
    void recordVote(Voter* voter, const string& candidateName);
    void countVotes();
    void displayResults();
};



#endif // ELECTIONMACHINE_H
