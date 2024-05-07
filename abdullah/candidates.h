#ifndef CANDIDATES_H
#define CANDIDATES_H
#include  "candidate.h"
#include <vector>
class Candidates{
    private:
    vector<Candidate>* candidates;//dma
    static Candidates *instance;

    
    Candidates() {
        candidates = new std::vector<Candidate>(); // Using dma
    }

    public:
    ~Candidates() {
        delete candidates; //de allocateing mem
    }
    static Candidates *getInstance() {//getting inst of class
            if (instance == nullptr) {
                instance = new Candidates();
            }
            return instance;
        }
    void searchCandidates(string sector);
    void addCandidates(const Candidate & cand);
    void loadPersonsFromJsonFile(string file);
    void changeVoteCount(string sign);
    bool searchSelectedCandidate(string sector,string sign);
    void display() const ;
    void calculateResults();
	

};




#endif
