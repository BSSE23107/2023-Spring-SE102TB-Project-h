#ifndef PROJECT_OOP_VOTER_H
#define PROJECT_OOP_VOTER_H
#include <string>
#include "Person.h"

class Voter : public Person {
private:
    string id;
    string cnic;
    bool hasVoted;
    string password;
    string selectedCandidate;

public:
    Voter(const string& personName, int personAge, const string& personGender, const string& voterId, const string& voterCnic, const string& voterPassword);
    const string& getId() const;
    const string& getCnic() const;
    bool getHasVoted() const;
    void setHasVoted(bool voted);
    bool login(const string& inputPassword);
    const string& getSelectedCandidate() const {
        return selectedCandidate;
    }
    void setSelectedCandidate(const string& candidateName) {
        selectedCandidate = candidateName;
    }
};

#endif // PROJECT_OOP_VOTER_H
