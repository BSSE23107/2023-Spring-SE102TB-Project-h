#ifndef STARTPOLLING_H
#define STARTPOLLING_H
#include<iostream>
#include"polling.h"

using namespace std;

class StartPolling:public PollingStation{

    public:
    void startPolling() const;
    void showresults() const;
    void calculateResults() ;
};




#endif