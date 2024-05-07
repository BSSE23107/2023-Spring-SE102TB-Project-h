#include "Candidate.h"

// Default constructor
Candidate::Candidate() {}

// Getter method to retrieve candidate's win status
bool Candidate::getWonStatus() {
    return isWon;
}

// Getter method to retrieve candidate's vote count
const int Candidate::getVoteCount() const {
    return voteCount;
}

// Getter method to retrieve candidate's position
int Candidate::getPosition() {
    return position;
}

// Setter method to set candidate's vote count
void Candidate::setVoteCount(int count) {
    voteCount = count;
}

// Setter method to set candidate's win status
void Candidate::setWonStatus(bool status) {
    isWon = status;
}

// Setter method to set candidate's position
void Candidate::setPosition(int canPos) {
    position = canPos;
}
