#ifndef PARTYREGISTRATION_PERSON_H
#define PARTYREGISTRATION_PERSON_H
#include <iostream>
#include "Address.h"
using namespace std;

class Person {
private:
    string personName; // Name of the person
    string CNIC; // CNIC (Computerized National Identity Card) of the person
    string dateOfBirth; // Date of birth of the person
    string Gender; // Gender of the person
    Address personAddress; // Address of the person (assuming Address is a class)
public:
    // Default constructor
    Person();

    // Getter methods to retrieve private member variables
    const string getPersonName() const;
    const string getCNIC() const;
    const string getDateOfBirth() const;
    const string getGender() const;
    const Address getPersonAddress() const;

    // Setter methods to modify private member variables
    void setPersonName(string name);
    void setPersonCNIC(string perCNIC);
    void setDateOfBirth(string dob);
    void setPersonAddress(Address &address);
    void setPersonGender(string perGender);

    // Method to simulate casting a vote
    void castVote();
};

#endif //PARTYREGISTRATION_PERSON_H
