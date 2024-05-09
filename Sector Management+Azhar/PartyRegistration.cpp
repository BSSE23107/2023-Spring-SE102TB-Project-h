#include "PartyRegistration.h"

PartyRegistration *PartyRegistration::instance = nullptr; // Initialize static member variable

// Constructor (private to prevent external instantiation)
PartyRegistration::PartyRegistration() {}

// Method to get the singleton instance of PartyRegistration
PartyRegistration *PartyRegistration::getInstance() {
    if(instance == nullptr){
        instance = new PartyRegistration;
    }
    return instance;
}

// Method to add a party to the registration system
void PartyRegistration::addParty(Party *party) {
    // Add the party to the vector of parties
    parties.push_back(party);

    // Create and write party data to a JSON file
    string partNameFile = party->getPartyName() + ".json";
    json partyData;
    ofstream partyFile(partNameFile);
    partyFile << partyData << endl;
    partyFile.close();

    // Update party administrators file
    ofstream putAdmins("partyAdmins.txt", ios::app);
    putAdmins << party->getAdminName() << endl;
    putAdmins.close();

    // Update party registration IDs file
    ofstream partyRegIDS("partyRegistrationIDs.txt", ios::app);
    partyRegIDS << party->getRegistrationID() << endl;
    partyRegIDS.close();

    string partyNominatedSectorsFile = party->getPartyName()  + "_nominated_sectors.txt";
    ofstream openPartyNominatedSectorsFile(partyNominatedSectorsFile);
    // Create and write admin data to a JSON file
    string passwordFile = party->getAdminName() + ".json";
    ofstream partyPassword(passwordFile);
    json admin;
    admin[party->getAdminName()] = {
            {"Password", party->getPassword()},
            {"Party ID", party->getRegistrationID()},
            {"Party Name", party->getPartyName()},
            {"Party Symbol", party->getPartySymbol()}
    };
    partyPassword << admin << endl;
}

// Method to add a candidate to a party
void PartyRegistration::addCandidate(PartyCandidate *candidate, std::string &partyName) {
    // Find the party and add the candidate to it
    for (int i = 0; i < parties.size(); i++) {
        if (parties[i]->getPartyName() == partyName) {
            parties[i]->addCandidates(candidate);
        }
    }

    // Update party data file with candidate information
    string filename = partyName + ".json";
    ifstream partyFile(filename);
    json partyData;
    partyFile >> partyData;
    partyFile.close();

    json candidateData;
    candidateData[candidate->getCNIC()] = {
            {"Name", candidate->getPersonName()},
            {"Gender", candidate->getGender()},
            {"Date Of Birth", candidate->getDateOfBirth()},
            {"Address", candidate->getPersonAddress().getConcatenatedAddress()}
    };

    partyData.push_back(candidateData);

    ofstream putPartyCandidates(filename);
    putPartyCandidates << partyData.dump(4);
    putPartyCandidates.close();
}

// Method to authenticate the admin login
void PartyRegistration::loginAdmin(std::string admin, std::string password) {
    // Check if admin exists in the admin list
    string adminFile = admin + ".json";
    string admins;
    ifstream checkAdmin("partyAdmins.txt");
    while (getline(checkAdmin, admins)) {
        if (admins == admin) {
            ifstream loginAdmin(adminFile);
            json adminData;
            loginAdmin >> adminData;
            loginAdmin.close();

            // Validate admin's password
            if (adminData.contains(admin)) {
                json adminInfo = adminData[admin];
                if (adminInfo["Password"] == password) {
                    string partyName = adminInfo["Party Name"];
                    string registrationID = adminInfo["Party ID"];
                    string partySymbol = adminInfo["Party Symbol"];
                    addCandidates(partyName, registrationID, partySymbol);
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

// Method to nominate a candidate from a party on a sector
void PartyRegistration::nominatedCandidate(PartyCandidate *partyCandidate, std::string &sectorCode) {
    // Read sectors data
    Provinces *provinces = Provinces::getInstance();
    vector<Sector*> sectorsInSystem = provinces->getSectors();
    for(auto& sector : sectorsInSystem){
        if(sector->getSectorCode() == sectorCode){
            sector->nominateCandidate(partyCandidate);
        }
    }
    string filename = "candidates.json";
    ifstream readSectors(filename);
    json sectors;
    readSectors >> sectors;
    readSectors.close();

    // Find the sector and add the nominated candidate
    for (auto &sec : sectors) {
        if (sec.contains(sectorCode)) {
            json &sector = sec[sectorCode];
            json candidate;
            candidate[partyCandidate->getPersonName()] = {
                    {"Party", partyCandidate->getCandidateParty()},
                    {"Symbol", partyCandidate->getCandidateSymbol()},
                    {"Vote Count", partyCandidate->getVoteCount()},
                    {"Position", partyCandidate->getPosition()},
                    {"Won Status", partyCandidate->getWonStatus()}
            };
            sector.push_back(candidate);
            ofstream putCandidateInSector("candidates.json");
            putCandidateInSector << sectors.dump(4);
            putCandidateInSector.close();
        }
    }

    string candidatePartyFile = partyCandidate->getCandidateParty() + "_nominated_sectors.txt";
    ofstream putNominatedSector(candidatePartyFile);
    putNominatedSector << sectorCode << endl;
    putNominatedSector.close();
}