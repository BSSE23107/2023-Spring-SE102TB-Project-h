
#include "Address.h"
Address::Address() {}

Address::Address(string districtName, string areaName, string blockCode, int street, int house)
:district(districtName),area(areaName),block(blockCode),streetNum(street),houseNum(house) {
    concatenatedAddress=district +", "+ area +", "+ block+ ", " + to_string(streetNum) +", "+ to_string(houseNum);

}

string Address::getConcatenatedAddress() const {
    return concatenatedAddress;
}
