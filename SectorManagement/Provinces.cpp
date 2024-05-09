#include "Provinces.h"

Provinces *Provinces::instance = nullptr; // Initialize the static member instance to nullptr

Provinces::Provinces() = default; // Default constructor for the Provinces class

// Method to get the singleton instance of Provinces
Provinces *Provinces::getInstance() {
    if(instance == nullptr){ // Check if instance is null
        instance = new Provinces; // Create a new instance if it's null
    }
    return instance; // Return the instance
}

// Method to add a province to the list of provinces
void Provinces::addProvince(Province *province) {
    provinces.push_back(province); // Add the province to the vector of provinces

    // Write the province name to a file named provinces.txt
    ofstream provinceName("provinces.txt",ios::app);
    provinceName << province->getProvinceName() << endl;
    provinceName.close();

    // Create a JSON file for the province and write the province data to it
    string filename = province->getProvinceName() + ".json";
    ofstream province1(filename);
    json provinceData;
    provinceData[province->getProvinceName()] = json::array();
    province1 << provinceData.dump(4) << endl;
    province1.close();

    // Execute the addCities function
    executeAddCities(province->getProvinceName());
}

// Method to add districts to a province
void Provinces::addDistricts(District *district,const string& provinceName) {
    // Loop through the provinces to find the matching province by name
    for (auto &province: provinces) {
        if (province->getProvinceName() == provinceName) {
            province->addDistrict(district); // Add the district to the province
        }
    }

    // Update the JSON file with the district data
    string filename = provinceName + ".json";
    ifstream provinceFile(filename);
    json provinceData;
    provinceFile >> provinceData;
    provinceFile.close();

    if (provinceData.contains(provinceName)) {
        json &districtArray = provinceData[provinceName];

        // Check if the district already exists
        for (auto &existingDistrict: districtArray) {
            if (existingDistrict["District Name"] == district->getDistrictName()) {
                cout << "District " << district->getDistrictName() << " already exists in " << provinceName << "." << endl;
            }
        }

        // Add district data to the JSON object
        json districtData;
        districtData["District Name"] = district->getDistrictName();
        districtArray.push_back(districtData);

        // Write the updated JSON object back to the file
        ofstream putDistrictData(filename);
        putDistrictData << provinceData << endl;
        putDistrictData.close();
    } else {
        cout << "Province with " << provinceName << " does not exist." << endl;
    }

    // Create files to store district sectors
    string districtSectorsFile = district->getDistrictName() + "Sectors.txt";
    ofstream districtSectors(districtSectorsFile, ios::app);
    districtSectors.close();

    // If no candidates are made yet, create a JSON file for sectors

    // Add the sector to the JSON file
    addSector(district->getDistrictName(),provinceName);
}

// Method to add sectors to a district
void Provinces::addSectors(Sector* provisionalSector, const std::string& districtName, const string& provinceName, bool isFederal) {
    // Loop through the provinces to find the matching province and district by name
    for(int i=0;i<provinces.size();i++){
        if(provinces[i]->getDistricts()[i]->getDistrictName() == districtName){
            provinces[i]->getDistricts()[i]->getSectors().push_back(provisionalSector); // Add the sector to the district
        }
    }

    totalSectors.push_back(provisionalSector); // Add the sector to the total sectors list

    // Write the sector data to appropriate files based on whether it's a federal sector or not
    if(isFederal == 1) {
        string districtFederalSectorFile = districtName + "_federal_sector.txt";
        ofstream districtFederalSectors(districtFederalSectorFile,ios::app);
        districtFederalSectors << provisionalSector->getSectorCode() << endl;
        districtFederalSectors.close();
    } else if(isFederal == 0){
        string districtSectorsFile = districtName + "Sectors.txt";
        ofstream districtSectors(districtSectorsFile,ios::app);
        districtSectors << provisionalSector->getSectorCode() << endl;
        districtSectors.close();
    }

    // Write the sector data to the province sectors file
    string provinceSectorsFile = provinceName + "Sectors.txt";
    ofstream provinceSectors(provinceSectorsFile,ios::app);
    provinceSectors << provisionalSector->getSectorCode() << endl;
    provinceSectors.close();

    // Update the JSON file with the sector data
    ifstream getSectorsData("candidates.json");
    json sectors;
    getSectorsData >> sectors;
    getSectorsData.close();

    json sector;
    sector[provisionalSector->getSectorCode()] = json::array();
    sectors.push_back(sector);

    ofstream putSectorsBack("candidates.json");
    putSectorsBack << sectors.dump(4) << endl;
    putSectorsBack.close();
}

// Method to display all provinces
void Provinces::displayProvinces(){
    ifstream displayProvinces("provinces.txt");

    int i = 0;
    string province;
    while(getline(displayProvinces,province)){
        cout << i + 1 << ". " << province << endl;
        i++;
    }
}

// Method to display districts of a province
void Provinces::displayDistricts(std::string &provinceName) {
    string filename = provinceName + ".json";
    ifstream displayDistricts(filename);

    json districts;
    displayDistricts >> districts;
    displayDistricts.close();

    cout << "Districts of " << provinceName << ": " << endl;
    if(districts.contains(provinceName)){
        json &districtsArray = districts[provinceName];
        int i = 1;
        for(auto &district : districtsArray){
            string districtName = district["District Name"];
            cout << i << ". "<< districtName << endl;
            i++;
        }
    }
}

// Method to display sectors of a district
void Provinces::displaySectors(std::string &districtName) {
    string filename = districtName + "Sectors.txt";
    ifstream readSectors(filename);
    string sectors;
    int sectorCount = 0;
    while(getline(readSectors,sectors)){
        cout << sectorCount + 1 << ". " << sectors << endl;
        sectorCount++;
    }
    readSectors.close();
}

// Method to get all sectors
vector<Sector *> Provinces::getSectors() {
    return totalSectors;
}