#include "userInterface.h"

void userInterface(string username){
    int input;
    bool c=true;
    system("clear");// Initialize to 'Y' to enter the loop initially
    while(c){
        cout << "           Individual Candidate Module         " << endl;
        cout << "1. Nominate Yourself." << endl;
        cout << "Enter your choice :";
        cin >> input;
        RegistrationIndividualCandidates *registrationIndividualCandidates = RegistrationIndividualCandidates::getInstance();
        switch(input){
            case 1:{
                string userFile = username + ".json";
                ifstream getUserData(userFile);
                json userData;
                getUserData >> userData;
                getUserData.close();

                string password,name,gender,address,cnic,dob;
                for(auto& candidate : userData){
                    if(candidate.contains(username)){
                        json& credentials = candidate[username];
                        password = credentials["Password"];
                        name = credentials["Name"];
                        gender = credentials["Gender"];
                        address = credentials["Address"];
                        dob = credentials["DOB"];

                    }
                }
                string sectorCode,symbol;
                cout << "Enter the sectorCode :";
                cin >> sectorCode;
                Address address1;
                address1.setConcatenatedAddress(address);
                auto *individualCandidate = new IndividualCandidate(username,password,name,cnic,dob,gender,address1);
                registrationIndividualCandidates->nominateOnSectors(individualCandidate,sectorCode);
                break;
            }
            case 2: {
                break;
            }
            default:{
                cout << "Invalid Input. Please enter valid input...." << endl;
                break;
            }
        }
    }
}
