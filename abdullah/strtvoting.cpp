#include "strtvoting.h"
#include "persons.h"
#include "candidates.h"


int count = 0;

Persons *persons = Persons::getInstance();
Candidates *cand = Candidates::getInstance();

bool validateCNIC(const string &cnic) {
    
    if (cnic.length() != 15)
        return false;

    
    if (cnic[5] != '-' || cnic[13] != '-')
        return false;

    
    for (int i = 0; i < 15; ++i) {
        if (i != 5 && i != 13 && !isdigit(cnic[i]))
            return false;
    }

    return true;
}


void delay(int seconds) {
    
    int milliseconds = seconds * 1000;

    
    for (int i = 0; i < milliseconds * 1000; ++i) {
        
    }
}
void StartPolling::startPolling()const {
    
    while(true){
        cout<<"\t\t\tThanks for coming to vote!"<<endl;
        cout<<"\t\t\tTotal voter count in this polling station = "<< count  <<endl;
        string cnic;
        enter:
        cout<<"\n\nPlease Enter your cnic to caste your vote (00000-0000000-0): "<<endl;
        cin>>cnic;
        if(cnic=="Breaktheloop")
        break;
         if (validateCNIC(cnic)) {
            cout << "\n\nThank you for providing your CNIC." << endl;
        } else {
            cout << "\n\nInvalid CNIC format. Please enter again." << endl;
            goto enter;
        }
        

        string sec;
        sec=persons->searchPerson(cnic);
        if (sec=="Not"){
            delay(10000);
        getchar();
        system("cls");
        continue;}
        cout<<"Your Information: "<<endl;
        persons->displayperson(cnic);
     
        vote:
        cout<<"\n\nHere are the persons standing in your sector  "<< sec <<endl;
        cand->searchCandidates(sec);
        string ch;
        cout<<"\n\nEnter the sign whom you want to vote: "<<endl;
        cin>>ch;
        if(cand->searchSelectedCandidate(sec,ch)){
            cand->changeVoteCount(ch);
            persons->changeHasVoted(cnic);
            count += 1;
            cout<<"\n\nYou have casted your vote successfully! Thank You!"<<endl;
            cout<<"\nPress any key to continue..."<<endl;
             delay(10000);
            
            system("cls");
            getchar();
            
        }else{
            cout<<"The entered candidate is not available in this sector or has been eliminated from contestation."<<endl;
            goto vote;
        }

    }
}

