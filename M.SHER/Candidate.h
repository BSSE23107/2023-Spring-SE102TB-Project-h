#ifndef PROJECT_OOP_CANDIDATE_H
#define PROJECT_OOP_CANDIDATE_H
#include "Person.h"

class Candidate : public Person {
private:
    bool registrationStatus;
    string position;
    int voteCount;
    bool verified;
    int criminalRecord;

public:
    Candidate(const string& candidateName, int candidateAge, const string& candidateGender, int voteCount = 0);
    bool getRegistrationStatus() const;
    void setRegistrationStatus(bool status);
    const string& getPosition() const;
    void setPosition(const string& pos);
    int getVoteCount() const;
    void setVoteCount(int count);
    void incrementVoteCount();
    bool hasCriminalRecord();
    void generatePaymentSlip();
    void verifyPersonalDetails();
    void checkCriminalRecord();
};

#endif // CANDIDATE_H
