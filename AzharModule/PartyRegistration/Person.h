
#ifndef PARTYREGISTRATION_BY_AZHAR_PERSON_H
#define PARTYREGISTRATION_BY_AZHAR_PERSON_H
#include <string>
#include "Address.h"
using namespace std;
class Person{
    string personName;
    string CNIC;
    string dateOfBirth;
    string gender;
    Address personAddress;
public:
    Person();
    const string getPersonName() const;
    const string getCNIC() const;
    const string getDateOfBirth() const;
    const string getGender() const;
    const Address getPersonAddress() const;
    void setPersonName(string name);
    void setPersonCNIC(string perCNIC);
    void setDateOfBirth(string dob);
    void setPersonAddress(Address &address);
    void setPersonGender(string perGender);
    void castVote();
};
#endif //PARTYREGISTRATION_BY_AZHAR_PERSON_H
