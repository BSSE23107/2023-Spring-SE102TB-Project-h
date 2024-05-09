#include "PartyRegistration.h"

 PartyRegistration *PartyRegistration::instance=nullptr;
PartyRegistration::PartyRegistration(){}
 PartyRegistration *PartyRegistration::getInstance() {
     if(instance== nullptr){
         instance=new PartyRegistration;
     }
     return instance;
 }

void PartyRegistration::addParty(Party *party) {
     parties.push_back(party);

     ofstream inputAdmindata("PartyAdmins.txt");
     inputAdmindata<<party->getAdminName()<<endl;
     inputAdmindata.close();

     string filename=party->getPartyName()+".json";
     json partyData;
     ofstream partyNameFile(filename);
     partyNameFile<<partyData<<endl;
     partyNameFile.close();

     ofstream inputPartyRegId("partyRegistrationIDs");
     inputPartyRegId<<party->getRegistrationID()<<endl;
     inputPartyRegId.close();

     string passwordFile =  party->getAdminName()+ ".json";
     ofstream partyPassword(passwordFile);
     json admin;
     admin[party->getAdminName()]={
        {"Password",party->getPassword()},
        {"Party ID",party->getRegistrationID()},
        {"Party Name",party->getPartyName()}
     };
     partyPassword<<admin<<endl;


 }
void PartyRegistration::loginAdmin(std::string admin, std::string password) {
    string adminFile = admin + ".json";
    string admins;
    ifstream checkAdmin("partyAdmins.txt");
    while (getline(checkAdmin, admins)) {
        if (admins == admin) {
            ifstream loginAdmin(adminFile);

            json adminData;
            loginAdmin >> adminData;
            loginAdmin.close();

            if (adminData.contains(admin)) {
                json adminInfo = adminData[admin];


                if (adminInfo["Password"] == password) {
                    string partyName = adminInfo["Party Name"];
                    string registrationID = adminInfo["Party ID"];

                    exeaddCandidate(partyName, registrationID);

                    return;
                } else {
                    std::cout << "Incorrect password. Please try again." << std::endl;
                    return;
                }
            } else {
                cout << "Admin username not found." << std::endl;
                return;
            }


        }
    }
}
void PartyRegistration::exeaddCandidate(std::string partyName, std::string partyRegID) {
    int choice;
    char stop;
    do{
        system("clear");
        cout << "Your Party Registration ID is " << partyRegID << endl;
        cout << "_______________________________________________" << endl;
        cout << "                                               " << endl;
        cout << "              Welcome to Home Screen           " << endl;
        cout << "_______________________________________________" << endl;
        cout << "1-> Add Candidates." << endl;
        cout << "2-> Nominate Candidates." << endl;
        cout << "3-> Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
      //  PartyRegistration *partyRegistration = PartyRegistration::getInstance();
        switch (choice) {
            case 1:{
                string canName,gender,dateOfBirth,CNIC,district,town,block;
                int house,street;
                cout << "Enter candidate name: ";
                cin >> canName;
                cout << "Enter candidate gender: ";
                cin >> gender;
                cout << "Enter candidate CNIC: ";
                cin >> CNIC;
                cout << "Enter candidate Date Of Birth: ";
                cin >> dateOfBirth;
                cout << "****** Address of Candidate ******" << endl;
                cout << "Enter candidate residential city: ";
                cin >> district;
                cout << "Enter candidate residential town: ";
                cin >> town;
                cout << "Enter candidate town's block code: ";
                cin >> block;
                cout << "Enter street number: ";
                cin >> street;
                cout << "Enter house number: ";
                cin >> house;
                Address address(district,town,block,street,house);
                auto *partyCandidate = new PartyCandidate(canName,CNIC,gender,dateOfBirth,partyName,address);
                addCandidate(partyCandidate,partyName);
                break;
            }
            case 2:{
                break;
            }
            default:{
                cout << "Invalid Input, Please enter valid input...." << endl;
                break;
            }
        }
        cout <<  "Do you want to continue(Y/N): ";
        cin >> stop;
    }while(stop == 'Y' || stop == 'y');




 }
void PartyRegistration::addCandidate(PartyCandidate *candidate, std::string &partyName) {
    for(int i=0;i<parties.size();i++){
        if(parties[i]->getPartyName() == partyName){
            parties[i]->addCandidates(candidate);
        }
    }
    string filename = partyName + ".json";
    ifstream partyFile(filename);

    json partyData;
    partyFile >> partyData;
    partyFile.close();

    json candidateData;
    candidateData[candidate->getPersonName()] = {
            {"CNIC",candidate->getCNIC()},
            {"Gender",candidate->getGender()},
            {"Date Of Birth",candidate->getDateOfBirth()},
            {"Address",candidate->getPersonAddress().getConcatenatedAddress()}
    };

    partyData.push_back(candidateData);

    ofstream putPartyCandidates(filename);
    putPartyCandidates << partyData.dump(4);
    putPartyCandidates.close();

}
