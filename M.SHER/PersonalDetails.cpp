#include "PersonalDetails.h"
#include <iostream>
using namespace std;
PersonalDetails::PersonalDetails(int car, int house, int balance, int land)
        : carValue(car), houseValue(house), bankBalance(balance), landValue(land) {}

bool PersonalDetails::operator>(int value) const {
    // Calculate total asset value
    int totalAssets = carValue + houseValue + bankBalance + landValue;
    return totalAssets > value;
}

void PersonalDetails::displayDetails() const {
    cout << "Car Value: " << carValue << endl;
    cout << "House Value: " << houseValue << endl;
    cout << "Bank Balance: " << bankBalance <<endl;
    cout << "Land Value: " << landValue << endl;
}

int PersonalDetails::getTotalAssets() const {
    // Calculate and return total asset value
    return carValue + houseValue + bankBalance + landValue;
}

void PersonalDetails::updateCarValue(int value) {
    // Update car value
    carValue = value;
}

void PersonalDetails::updateHouseValue(int value) {
    // Update house value
    houseValue = value;
}

void PersonalDetails::updateBankBalance(int value) {
    // Update bank balance
    bankBalance = value;
}

void PersonalDetails::updateLandValue(int value) {
    // Update land value
    landValue = value;
}
