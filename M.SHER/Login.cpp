#include "Login.h"

bool Login::authenticate(const string& inputPassword, const string& storedPassword) {
    return inputPassword == storedPassword;
}
