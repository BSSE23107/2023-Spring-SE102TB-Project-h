#ifndef SECTORS_MODULE_PROVINCES_H
#define SECTORS_MODULE_PROVINCES_H
#include <iostream>
#include "Province.h"
#include "Sector.h"
#include <fstream>
#include "nlohmann/json.hpp"
#include "addCities.h"
#include "addSectors.h"
using json = nlohmann::json;
using namespace std;

class Provinces {
private:
    static int candidatesMade; // Static member to track the number of candidates made
    static Provinces* instance; // Singleton instance of Provinces
    vector<Province*> provinces; // Vector to store provinces
    vector<Sector*> totalSectors; // Vector to store all sectors
    Provinces(); // Private constructor to prevent external instantiation
public:
    // Method to get the singleton instance of Provinces
    static Provinces* getInstance();
    // Method to add a province to the list of provinces
    void addProvince(Province* province);
    // Method to add districts to a province
    void addDistricts(District* district, const string& provinceName);
    // Method to add sectors to a district
    void addSectors(Sector* sector, const string& districtName, const string& provinceName, bool isFederal);
    // Method to get all sectors
    vector<Sector*> getSectors();
    // Method to display all provinces
    void displayProvinces();
    // Method to display districts of a province
    void displayDistricts(string& provinceName);
    // Method to display sectors of a district
    void displaySectors(string& districtName);
};




#endif //SECTORS_MODULE_PROVINCES_H
