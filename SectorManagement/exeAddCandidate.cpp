#include "exeAddCandidate.h"

void addCandidates(string partyName, string partyRegID, string partySymbol) {
    int choice;
    char stop;
    do {
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
        Provinces *provinces = Provinces::getInstance();
        PartyRegistration *partyRegistration = PartyRegistration::getInstance();
        switch (choice) {
            case 1: {
                string canName, gender, dateOfBirth, CNIC, district, town, block;
                int house, street;
                cin.ignore();
                cout << "Enter candidate name: ";
                getline(cin,canName);
                cout << "Enter candidate gender: ";
                getline(cin,gender);
                cout << "Enter candidate CNIC: ";
                getline(cin,CNIC);
                cout << "Enter candidate Date Of Birth: ";
                getline(cin,dateOfBirth);
                cout << "****** Address of Candidate ******" << endl;
                cout << "Enter candidate residential city: ";
                getline(cin,district);
                cout << "Enter candidate residential town: ";
                getline(cin,town);
                cout << "Enter candidate town's block code: ";
                getline(cin,town);
                cout << "Enter street number: ";
                cin >> street;
                cout << "Enter house number: ";
                cin >> house;
                Address address(district, town, block, street, house);
                auto *partyCandidate = new PartyCandidate(canName, CNIC, gender, dateOfBirth, partyName, partySymbol,
                                                          address);
                partyRegistration->addCandidate(partyCandidate, partyName);
                break;
            }
            case 2: {
                provinces->displayProvinces();
                string provinceName, districtName, sectorCode, candidateName, CNIC;
                cout << "Enter province Name: ";
                cin >> provinceName;
                provinces->displayDistricts(provinceName);
                cout << "Enter the district name: ";
                cin >> districtName;
                provinces->displaySectors(districtName);
                cout << "Enter the sector code on which you want to nominate your candidate: ";
                cin >> sectorCode;

                string partyFile = partyName + "_nominated_sectors.txt";
                ifstream getNominatedSectors(partyFile);
                string nominatedSectors;

                while(getline(getNominatedSectors,nominatedSectors)){
                    if(nominatedSectors == sectorCode){
                        cout << "You have already nominated on this sector, Please chose another sector :";
                        cin >> sectorCode;
                        getNominatedSectors.clear();
                        getNominatedSectors.seekg(0, ios::beg);
                    }
                }

                getNominatedSectors.close();
                cout << "Enter the CNIC of member of your party: ";
                cin >> CNIC;
                cout << partyName << endl;
                string filename = partyName + ".json";
                ifstream getMemberData(filename);

                string name, gender, dateOfBirth, address;
                json candidates;
                getMemberData >> candidates;
                getMemberData.close();
                for (auto &candidate: candidates) {
                    if (candidate.contains(CNIC)) {
                        cout << "Member with CNIC " << CNIC << " found" << endl;
                        name = candidate[CNIC]["Name"];
                        dateOfBirth = candidate[CNIC]["Date Of Birth"];
                        address = candidate[CNIC]["Address"];
                        gender = candidate[CNIC]["Gender"];

                        break;
                    }

                }

                Address address1;
                address1.setConcatenatedAddress(address);


                auto *Candidate = new PartyCandidate(name, CNIC, gender, dateOfBirth, partyName, partySymbol, address1);

                partyRegistration->nominatedCandidate(Candidate, sectorCode);
                break;
            }
            default: {
                cout << "Invalid Input, Please enter valid input...." << endl;
                break;
            }
        }
        cout << "Do you want to continue(Y/N): ";
        cin >> stop;
    } while (stop == 'Y' || stop == 'y');


}