#include "Voter.h"
#include "Login.h"

Voter::Voter(const string& personName, int personAge, const string& personGender, const string& voterId, const string& voterCnic, const string& voterPassword)
        : Person(personName, personAge, personGender), id(voterId), cnic(voterCnic), hasVoted(false), password(voterPassword) {}

const string& Voter::getId() const {
    return id;
}

const string& Voter::getCnic() const {
    return cnic;
}

bool Voter::getHasVoted() const {
    return hasVoted;
}

void Voter::setHasVoted(bool voted) {
    hasVoted = voted;
}

bool Voter::login(const string& inputPassword) {
    return Login::authenticate(inputPassword, password);
}
