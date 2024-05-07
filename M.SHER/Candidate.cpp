#include "Candidate.h"
#include <iostream>

Candidate::Candidate(const string& candidateName, int candidateAge, const string& candidateGender, int voteCount)
        : Person(candidateName, candidateAge, candidateGender), registrationStatus(false), voteCount(voteCount) {}

bool Candidate::getRegistrationStatus() const {
    return registrationStatus;
}

void Candidate::setRegistrationStatus(bool status) {
    registrationStatus = status;
}

const string& Candidate::getPosition() const {
    return position;
}

void Candidate::setPosition(const string& pos) {
    position = pos;
}

int Candidate::getVoteCount() const {
    return voteCount;
}
void Candidate::setVoteCount(int count) {
    voteCount = count;
}

void Candidate::incrementVoteCount() {
    ++voteCount;
}

bool Candidate::hasCriminalRecord() {
    return false;
}

void Candidate::generatePaymentSlip() {
    cout << "Payment slip generated for candidate: " << name << endl;
}

void Candidate::verifyPersonalDetails() {
    cout << "Personal details verified for candidate: " << name << endl;
    verified = true;
}

void Candidate::checkCriminalRecord() {
    if (criminalRecord > 0) {
        cout << "Candidate " << name << " has a criminal record." << endl;
    } else {
        cout << "Candidate " << name << " does not have a criminal record." << endl;
    }
}