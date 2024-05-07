#ifndef PROJECT_OOP_PERSON_H
#define PROJECT_OOP_PERSON_H
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;
    string gender;

public:
    Person(const string& personName, int personAge, const string& personGender);
    string getName() const;
    int getAge() const;
    string getGender() const;
};

#endif // PERSON_H
