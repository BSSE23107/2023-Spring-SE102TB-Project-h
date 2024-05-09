#include <iostream>
#include "Statistics.h"
#include <unistd.h>
#include <termios.h>

using namespace std;
 int main(){
     system("clear");
     cout<<"\033[3m"<<"\033[32m"<<endl<<endl;
     cout<<"______________________________________________________________________ \n"
           "                   "<<"\033[1m"<<"\033[4m"<<"Welcome To Statistics Section\n"
           "_______________________________________________________________________\n"<<"\033[0m"<<"\033[33m"
           "     Choose An Option:\n   1.Check Voter Eligibility\n   2.Gender Statistics\n";
     Statistics *stat=Statistics::getInstance();
     int choice=0;
     cin>>choice;
     switch (choice) {
         case 1: {
             string year ;
             cout<< "\033[0m" << "Enter the Year For Which You Want to Check the Vote Eligibility :";
             cin >> year;
             stat->isEligible(year);
             main();
             break;
         }
         case 2:
             stat->get_gender_info();
             main();
         break;
         case 3:
             cout<<"Exiting,,,";
             break;
         default:
             cerr<< "\033[31m "<<"Please Choose A Valid Option!\nExiting...\n";
             break;


     }



     return 0;
 }