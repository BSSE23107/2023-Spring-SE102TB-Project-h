#include "Person.h"

Person::Person(const string& personName, int personAge, const string& personGender)
        : name(personName), age(personAge), gender(personGender) {}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

string Person::getGender() const {
    return gender;
}
