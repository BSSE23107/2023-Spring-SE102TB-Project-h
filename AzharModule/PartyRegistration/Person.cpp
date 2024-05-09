
#include "Person.h"


Person::Person() {
    personName = "";
    CNIC = "";
    gender = "";
    dateOfBirth = "";
}

const string Person::getPersonName() const {
    return personName;
}

const string Person::getCNIC() const {
    return CNIC;
}

const string Person::getDateOfBirth() const {
    return dateOfBirth;
}

const string Person::getGender() const {
    return gender;
}

const Address Person::getPersonAddress() const {
    return personAddress;
}

void Person::setPersonName(std::string name) {
    personName = name;
}

void Person::setPersonGender(std::string perGender) {
    gender = perGender;
}

void Person::setDateOfBirth(std::string dob) {
    dateOfBirth = dob;
}

void Person::setPersonCNIC(std::string perCNIC) {
    CNIC = perCNIC;
}

void Person::setPersonAddress(Address &address) {
    personAddress = address;
}