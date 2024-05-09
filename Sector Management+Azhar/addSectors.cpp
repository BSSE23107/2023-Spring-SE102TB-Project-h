#include "addSectors.h"

void addSector(string cityName,string provinceName){
    char stop;
    int sectorType;
    Provinces *provinces = Provinces::getInstance();
    do{

        cout << "__________________________________________________" << endl;
        cout << "                                         " << endl;
        cout << "  Add sectors in " << cityName << " of " << provinceName << endl;
        cout << "__________________________________________________" << endl;


        cout << "1. Provincial." << endl;
        cout << "2. Federal." << endl;
        cout << "Which type of sector you want to add :";
        cin >> sectorType;
        switch(sectorType){
            case 1:{
                string city = cityName;
                string province = provinceName;


                auto *provisionalSector = new ProvisionalSector(city,province);

                cout << "Sector with sector code " << provisionalSector->getSectorCode() << " has been created." << endl;
                provinces->addSectors(provisionalSector,provisionalSector->getDistrict(),province,0);
                break;
            }
            case 2:{
                string city = cityName;
                string province = provinceName;

                auto *federalSector = new FederalSector(city);

                provinces->addSectors(federalSector,federalSector->getDistrict(),province,1);
                cout << "Federal Sector with sector code " << federalSector->getSectorCode() << " has been created." << endl;
                break;
            }
            default:{
                cout << "Invalid Input. Please enter a valid input....." << endl;
                break;
            }
        }

        cout << "Do you want to continue(Y/N): ";
        cin >> stop;
    }while(stop=='y' || stop=='Y');

}