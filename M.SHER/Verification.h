#ifndef PROJECT_OOP_VERIFICATION_H
#define PROJECT_OOP_VERIFICATION_H

#include "Candidate.h"
#include <vector>
#include <string>

class Verification {
private:
    Candidate* candidate;
    bool personalDetailsVerification;
    bool registrationFeeStatus;
    bool taxPaymentStatus;
    vector<string> criminalRecords;

public:
    Verification(Candidate* cand);

    void checkRegistrationFeePayment();
    void verifyPersonalDetails();
    void checkTaxPayment();
    void checkCriminalRecord(Candidate* candidate);
    bool isVerified() const;
};

#endif // VERIFICATION_H
