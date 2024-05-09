#include <iostream>
#include "Party.h"
#include "PartyRegistration.h"
#include "Person.h"
#include "Candidate.h"
#include "PartyCandidate.h"
#include "Address.h"

using namespace std;

int main() {

    int choice;
    char stop;
    do {
        system("clear");
        cout << "____________________________________________" << endl;
        cout << "                                            " << endl;
        cout << "     Welcome to Party Registration Module   " << endl;
        cout << "____________________________________________" << endl;
        cout << "1. Register." << endl;
        cout << "2. Login." << endl;
        cout << "3. Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        PartyRegistration *partyRegistration = PartyRegistration::getInstance();
        switch (choice) {
            case 1: {
                string partyName, partyAdmin, pass;
                cout << "Enter the name of Party: ";
                cin >> partyName;
                ifstream checkAdmin("partyAdmins.txt");
                string adminName;

                cout << "Enter your Name: ";
                cin >> partyAdmin;
                while (getline(checkAdmin, adminName)) {
                    if (adminName == partyAdmin) {
                        cout << "Username already exists. Please enter a different username: ";
                        cin >> partyAdmin;

                        checkAdmin.clear();
                        checkAdmin.seekg(0, ios::beg);
                    }
                }
                checkAdmin.close();

                cout << "Enter your password: ";
                cin >> pass;
                auto *party = new Party(partyName, partyAdmin, pass);
                partyRegistration->addParty(party);
                partyRegistration->exeaddCandidate(party->getPartyName(), party->getRegistrationID());

                break;
            }
            case 2: {
                string userName, password;
                cout << "Enter username: ";
                cin >> userName;
                cout << "Enter password: ";
                cin >> password;
                partyRegistration->loginAdmin(userName, password);
                break;
            }
            default: {
                cout << "Invalid Input, Please enter a valid input...." << endl;
                break;
            }
        }
        cout << "Do you want to continue(Y/N): ";
        cin >> stop;
    } while (stop == 'y' || stop == 'Y');


return 0;
}
