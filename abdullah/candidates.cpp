#include"candidates.h"
#include "nlohmann/json.hpp" 
#include <fstream>
#include <algorithm>
#include<unordered_map>



using json = nlohmann::json;

Candidates* Candidates::instance = nullptr;

void Candidates::addCandidates(const Candidate& cand){
    candidates.push_back(cand);
}


// void Candidates::searchCandidates(string sector){
//     auto it = find_if(candidates.begin(), candidates.end(), [sector](const Candidate &can) {
//             return can.getSector() == sector;
//         });

//         if (it != candidates.end()) {
            
//             it->display()
            

//         } else {
//             cerr<< "Person with ID " << cnic << " not found." << endl;
//             return "Not";
//         }
// }

void Candidates::changeVoteCount(string sign){
     auto it = find_if(candidates.begin(), candidates.end(), [sign](const Candidate &can) {
            return can.getSign() == sign;
        });

        if (it != candidates.end()) {
            
            int vc=it->getVotecount();
            vc++;
            it->setVotecount(vc);
            

        }
}

void Candidates::loadPersonsFromJsonFile(const string filename) {
        ifstream file(filename);
        if (file.is_open()) {
            json data;
            file >> data;
            file.close();

            // "NAME": "James",
            // "PARTY": "PPP",
            // "Gender": "M",
            // "Sector": "PP-19",
            // "VoteCount": "Null",
            // "SIGN": "T"
        for (const auto& personEntry : data["Candidates"]) {
            for (const auto& personData : personEntry.items()) {
                const auto& personDetails = personData.value()[0];
                string name = personDetails["NAME"];
                string sign = personDetails["SIGN"];
                string party = personDetails["PARTY"];
                string sector = personData.key();
                
                int votecount = stoi(personDetails["VoteCount"].get<std::string>()); 
                string genderStr = personDetails["Gender"];
                char gender = genderStr.empty() ? ' ' : genderStr[0];
                
                // Candidate(string name,string sign,string party,string sector,int votecount,char gender);
                Candidate candidate(name, sign, party, sector, votecount, gender);
                addCandidates(candidate);
                }
            }
        } else {
            cerr << "Failed to open file: " << filename << std::endl;
        }
    }



void Candidates::searchCandidates(string sector){
    
        cout << " Candidates in "<<sector<<" sector are : " << endl;
        for (const auto &can : candidates) {
            if(can.getSector()==sector){
                can.display();
            }
        }
    
}
bool Candidates::searchSelectedCandidate(string sector,string sign){
    for (const auto &can : candidates) {
            if(can.getSector()==sector){
                if(can.getSign()==sign){
                    return true;
                }
            }
        }
        return false;
}
void Candidates::display() const {
        cout << " cadiadates Informations : " << endl;
        for (const auto &can : candidates) {
            can.display();
        }
    }

void Candidates::calculateResults() {
    unordered_map<string, Candidate> sectorWinners;

    for (const Candidate& candidate : candidates) {
        const string& sector = candidate.getSector();
        auto it = sectorWinners.find(sector);
        if (it == sectorWinners.end() || candidate > it->second) {
            sectorWinners[sector] = candidate;
        }
    }

    for (const auto& entry : sectorWinners) {
        cout << "Winner in Sector " << entry.first << ":" << endl;
        entry.second.displayre();
    }
}
