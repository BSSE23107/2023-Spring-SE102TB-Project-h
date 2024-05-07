#include "Result.h"



Result* Result::instance = nullptr;

Result::Result() : presidentVotes(0), vicePresidentVotes(0), secretaryVotes(0), treasurerVotes(0) {}

Result* Result::getInstance() {
    if (instance == nullptr) {
        instance = new Result();
    }
    return instance;
}

void Result::updatePresidentVotes(int votes) {
    presidentVotes += votes;
}

void Result::updateVicePresidentVotes(int votes) {
    vicePresidentVotes += votes;
}

void Result::updateSecretaryVotes(int votes) {
    secretaryVotes += votes;
}

void Result::updateTreasurerVotes(int votes) {
    treasurerVotes += votes;
}

int Result::getPresidentVotes() const {
    return presidentVotes;
}

int Result::getVicePresidentVotes() const {
    return vicePresidentVotes;
}

int Result::getSecretaryVotes() const {
    return secretaryVotes;
}

int Result::getTreasurerVotes() const {
    return treasurerVotes;
}

void Result::incrementVoteCount(const string& position) {
    if (position == "President") {
        updatePresidentVotes(1);
    } else if (position == "Vice President") {
        updateVicePresidentVotes(1);
    } else if (position == "Secretary") {
        updateSecretaryVotes(1);
    } else if (position == "Treasurer") {
        updateTreasurerVotes(1);
    }
}

void Result::showResult() const {
    cout << "Election Results:\n";
    cout << "President: " << presidentVotes << " votes\n";
    cout << "Vice President: " << vicePresidentVotes << " votes\n";
    cout << "Secretary: " << secretaryVotes << " votes\n";
    cout << "Treasurer: " << treasurerVotes << " votes\n";
}
