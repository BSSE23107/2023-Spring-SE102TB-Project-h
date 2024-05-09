#include "Province.h"

// Constructor with parameter
Province::Province(std::string &name) {
    provinceName = name; // Initialize the province name
}

// Method to add a district to the province
void Province::addDistrict(District *district) {
    provinceDistricts.push_back(district); // Add the district to the vector of districts
}

// Getter method to retrieve province's name
const string Province::getProvinceName() const {
    return provinceName; // Return the province name
}

// Method to remove a district from the province
void Province::removeDistrict(const std::string &name) {
    for(int i=0;i<provinceDistricts.size();i++){ // Iterate through the vector of districts
        if(provinceDistricts[i]->getDistrictName() == name){ // Check if the district name matches the specified name
            provinceDistricts.erase(provinceDistricts.begin()+i); // Remove the district from the vector
        }
    }
}

// Getter method to retrieve the vector of districts
vector<District *> &Province::getDistricts() {
    return provinceDistricts; // Return the vector of districts
}

// Destructor
Province::~Province() {
    // Destructor is empty as there is no dynamic memory allocation to release
}