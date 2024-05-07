#ifndef PROJECT_OOP_RESULT_H
#define PROJECT_OOP_RESULT_H
#include <iostream>
using namespace std;
#include <string>
class ElectionMachine;

class Result {
private:
    static Result* instance;
    int presidentVotes;
    int vicePresidentVotes;
    int secretaryVotes;
    int treasurerVotes;

    Result(); // Private constructor to enforce singleton pattern

public:
    static Result* getInstance();

    void updatePresidentVotes(int votes);
    void updateVicePresidentVotes(int votes);
    void updateSecretaryVotes(int votes);
    void updateTreasurerVotes(int votes);

    int getPresidentVotes() const;
    int getVicePresidentVotes() const;
    int getSecretaryVotes() const;
    int getTreasurerVotes() const;

    void incrementVoteCount(const string& position);
    void showResult() const;
};

#endif // RESULT_H
