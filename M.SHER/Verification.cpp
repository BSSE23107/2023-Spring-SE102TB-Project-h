#include "Verification.h"
#include <iostream>
#include <algorithm>

Verification::Verification(Candidate* cand) : candidate(cand), personalDetailsVerification(false), registrationFeeStatus(false), taxPaymentStatus(false) {}

void Verification::checkRegistrationFeePayment() {
    if (!candidate->getRegistrationStatus()) {
        registrationFeeStatus = true;
        cout << "Registration fee payment verified for candidate: " << candidate->getName() << endl;
    } else {
        cout << "Registration fee payment pending for candidate: " << candidate->getName() << endl;
    }
}

void Verification::verifyPersonalDetails() {
    if (!candidate->getName().empty() && candidate->getAge() != 0 && !candidate->getGender().empty()) {
        personalDetailsVerification = true;
        cout << "Personal details verified for candidate: " << candidate->getName() << endl;
    } else {
        cout << "Incomplete personal details for candidate: " << candidate->getName() << endl;
    }
}
void Verification::checkTaxPayment() {
    bool taxPaid = true; // Assuming tax payment is verified
    if (taxPaid) {
        taxPaymentStatus = true;
        cout << "Tax payment verified for candidate: " << candidate->getName() << endl;
    } else {
        cout << "Tax payment pending for candidate: " << candidate->getName() << endl;
    }
}

void Verification::checkCriminalRecord(Candidate* candidate) {
    vector<string> criminalRecords = {"John Doe", "Jane Smith"}; // Sample criminal records
    if (find(criminalRecords.begin(), criminalRecords.end(), candidate->getName()) != criminalRecords.end()) {
        candidate->setRegistrationStatus(false);
        cout << "Candidate has a criminal record. Registration status set to false." << endl;
    } else {
        cout << "Candidate has no criminal record." << endl;
    }
}
bool Verification::isVerified() const {
    return personalDetailsVerification && registrationFeeStatus && taxPaymentStatus && !candidate->hasCriminalRecord();
}

