
#ifndef STATISTICS_STATISTICS_H
#define STATISTICS_STATISTICS_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#include <iostream>
#include <string>
//#include "Voter.h"
#include <fstream>
#include "nlohmann/json.hpp"
#include <unistd.h>
#include <termios.h>
#include <cmath>
using namespace std;
using json= nlohmann::json;


class Statistics{
    static Statistics* Instance;
    Statistics();
public:
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    static Statistics* getInstance();
void isEligible(string DOB);
void get_gender_info();
void print_circle_preview(int radius);
};
#endif
#endif //STATISTICS_STATISTICS_H
