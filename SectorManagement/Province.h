#ifndef SECTORS_MODULE_PROVINCE_H
#define SECTORS_MODULE_PROVINCE_H
#include <iostream>
#include "District.h"
#include <vector>
using namespace std;

class Province {
private:
    string provinceName; // Name of the province
    vector<District*> provinceDistricts; // Vector to store districts within the province
public:
    // Constructor with parameter
    explicit Province(string &name);
    // Getter method to retrieve province's name
    const string getProvinceName() const;
    // Method to add a district to the province
    void addDistrict(District* district);
    // Method to remove a district from the province
    void removeDistrict(const string &name);
    // Getter method to retrieve the vector of districts
    vector<District*>& getDistricts();
    // Virtual destructor to ensure proper destruction of derived classes
    virtual ~Province();
};


#endif //SECTORS_MODULE_PROVINCE_H
