#include "Person.h"

// Default constructor
Person::Person() {
    // Initialize member variables to empty strings
    personName = "";
    CNIC = "";
    Gender = "";
    dateOfBirth = "";
}

// Getter method for retrieving person's name
const string Person::getPersonName() const {
    return personName;
}

// Getter method for retrieving person's CNIC
const string Person::getCNIC() const {
    return CNIC;
}

// Getter method for retrieving person's date of birth
const string Person::getDateOfBirth() const {
    return dateOfBirth;
}

// Getter method for retrieving person's gender
const string Person::getGender() const {
    return Gender;
}

// Getter method for retrieving person's address
const Address Person::getPersonAddress() const {
    return personAddress;
}

// Setter method for setting person's name
void Person::setPersonName(std::string name) {
    personName = name;
}

// Setter method for setting person's gender
void Person::setPersonGender(std::string perGender) {
    Gender = perGender;
}

// Setter method for setting person's date of birth
void Person::setDateOfBirth(std::string dob) {
    dateOfBirth = dob;
}

// Setter method for setting person's CNIC
void Person::setPersonCNIC(std::string perCNIC) {
    CNIC = perCNIC;
}

// Setter method for setting person's address
void Person::setPersonAddress(Address &address) {
    personAddress = address;
}
