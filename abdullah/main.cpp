#include "person.h"
#include "persons.h"
#include"candidate.h"
#include "candidates.h"
#include"strtvoting.h"

int main(){
    Candidates *cand = Candidates::getInstance();
    
    Persons *persons = Persons::getInstance();
    persons->loadPersonsFromJsonFile("persons_data.json");
    
    cand->loadPersonsFromJsonFile("candidates.json");
    StartPolling strt;
    strt.startPolling();
    cand->calculateResults();

    return 0;
}