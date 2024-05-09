
#ifndef PARTYREGISTRATION_BY_AZHAR_ADDRESS_H
#define PARTYREGISTRATION_BY_AZHAR_ADDRESS_H
#include <string>
using namespace std;
class Address{
    string district;
    string area;
    string block;
    int streetNum;
    int houseNum;
    string concatenatedAddress;
public:
    Address();
    Address(string districtName, string areaName, string blockCode, int street, int house);
    string getConcatenatedAddress() const;
};
#endif //PARTYREGISTRATION_BY_AZHAR_ADDRESS_H
