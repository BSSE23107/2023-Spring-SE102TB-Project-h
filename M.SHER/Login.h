#ifndef PROJECT_OOP_LOGIN_H
#define PROJECT_OOP_LOGIN_H
#include <string>
#include "Voter.h"
class Login {
public:
    static bool authenticate(const string& inputPassword, const string& storedPassword);
};



#endif //PROJECT_OOP_LOGIN_H
