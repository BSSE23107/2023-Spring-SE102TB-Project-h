#ifndef PROJECT_OOP_PERSONALDETAILS_H
#define PROJECT_OOP_PERSONALDETAILS_H

class PersonalDetails {
private:
    int carValue;
    int houseValue;
    int bankBalance;
    int landValue;

public:
    PersonalDetails(int car, int house, int balance, int land);

    bool operator>(int value) const;
    void displayDetails() const;
    int getTotalAssets() const;

    void updateCarValue(int value);
    void updateHouseValue(int value);
    void updateBankBalance(int value);
    void updateLandValue(int value);
};

#endif // PERSONALDETAILS_H
