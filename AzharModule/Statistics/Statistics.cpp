
#include "Statistics.h"

Statistics *Statistics::Instance = nullptr;
Statistics::Statistics() {}

Statistics *Statistics::getInstance() {
    if (Instance == nullptr) {
        Instance = new Statistics;
    }
    return Instance;
}

void Statistics::isEligible(string DOB) {
    system("clear");
    float Eligilble_count = 0,alive_count=0,dead_count=0;
    string dobString;
    json data;
    ifstream file("persons_data.json");
    if (!file.is_open()) {
        cerr << "Error opening file!" << std::endl;
        return;
    }
    file >> data;
    int ttlcount = 0;
    int dob;
    for (auto &person: data["Persons"]) {
        for (auto &details: person.items()) {
            auto &personData = details.value()[0];
            dobString = personData["DOB"];
            string is_alive=personData["Isalive"];
            dob = stoi(dobString);
            if (stoi(DOB) - dob >= 18 && is_alive=="True") {
                Eligilble_count++;
            }
            if (is_alive=="True") {
                alive_count++;
            } else {
                dead_count++;
            }
            ttlcount++;
        }
    }

    cout << "The Total number of Persons eligible for year "<<"\033[32m" << DOB <<"\033[0m"<< " are :" <<"\033[1m"<<"\033[32m"<< Eligilble_count << "\033[0m"<<endl;
    cout << "Total Persons: " << ttlcount<<endl;
    cout << "\033[34m"<<"Alive Person :"<< "\033[0m"<< alive_count <<endl;
    cout << "\033[31m"<<"Dead Persons: "<< "\033[0m"<< dead_count<< endl;
    int option,select;
    file.close();
    string color;
    float dead_percent=dead_count/ttlcount*100;
    float alive_percent=alive_count/ttlcount*100;
    float eligible_percent=Eligilble_count/ttlcount*100;
    static int radius=18;
    for (int i=0;i<=2*radius;i++){
        cout << "                        ";
        for(int j=0;j<=2*radius;++j) {
            int x = i - radius;
            int y = j - radius;
            int distance = sqrt((x * x) + (y * y));
            if (distance <= radius) {
                float angle = atan2(x, y) * 180 / M_PI;
                if (angle < 0) {
                    angle += 360;
                }
                float cumulative_eligible_percent = eligible_percent / 100 * 360;
                float cumulative_alive_percent = cumulative_eligible_percent + alive_percent / 100 * 360;
                float cumulative_dead_percent = cumulative_alive_percent + dead_percent / 100 * 360;

                if (angle <= cumulative_eligible_percent) {
                    color = "\033[32m";//green
                } else if (angle <= cumulative_alive_percent) {
                    color = "\033[34m";//blue
                } else if (angle <= cumulative_dead_percent) {
                    color = "\033[31m";//red
                }
                cout << color << " #" << "\033[0m";
            } else {
                cout << "  ";
            }
        } cout << endl;
        }
    cout<<"                          "<< "\033[31m"<< "Dead Percent    :"<<"\033[0m"<<dead_percent<<"%"<<endl;
    cout<<"                          "<< "\033[34m"<< "Alive Percent   :"<<"\033[0m"<<alive_percent <<"%" <<endl;
    cout<<"                          "<< "\033[32m"<< "Eligible Percent:"<<"\033[0m"<<eligible_percent <<"%" <<endl;



cout<<"Choose an Option :\n1.Adjust Pi-Chart Settings\n2.Go Back\n";
    cin>>option;
    switch (option) {
        case 1:
            system("clear");
            cout << "Select an Option:\n"
                    "1. Set Radius to 5\n"
                    "2. Set Radius to 10\n"
                    "3. Set Radius to 15\n"
                    "4. Set Radius to 20\n"
                    "5. Set Radius to 25\n"
                    "0. Save\n";
            cin >> select;
            if (select >= 1 && select <= 5) {
                radius = select * 5;
            }
            cout << "Success" << endl;
            isEligible(DOB);
            break;
        case 2:
            break;
        default:
            cout << "Invalid Option" << endl;
            break;
    }
}

void Statistics::get_gender_info() {
    int choice;
    int select = 6;
    system("clear");
    float maleCount = 0, femaleCount = 0, otherGender = 0, totalCount = 0;
    string GENDER;
    json data;
    ifstream file("persons_data.json");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    file >> data;
    for (auto &person : data["Persons"]) {
        for (auto &details : person.items()) {
            auto &personData = details.value()[0];
            GENDER = personData["Gender"];
            if (GENDER == "M") {
                maleCount++;
            } else if (GENDER == "F") {
                femaleCount++;
            } else {
                otherGender++;
            }
            totalCount++;
        }
    }
    file.close();

    cout << "Gender Stats:" << endl;
    cout << "Total Persons: " << totalCount << endl;
    cout << "Male Voters: " << maleCount << endl;
    cout << "Female Voters: " << femaleCount << endl;
    cout << "Other Genders: " << otherGender << endl;
    static int radius = 15;
    static int diameter = 2 * radius;



   cout<< "\033[1m"<< "                        " << "\033[0";
    for (int i=0;i<=2 * radius;++i){
        cout <<"__";
    }
    cout<<endl;
    for(int i=0;i<radius -2;i++){
        cout<<"  ";
    }
    cout<< "\033[1m"<< "                        Pi Chart " << "\033[0"<< endl;
    cout<< "\033[1m"<< "                        " << "\033[0";
    for (int i=0;i<=2 * radius;++i){
        cout<<"__";
    }
cout<<endl;
    float malePercentage = maleCount / totalCount * 100;
    float femalePercentage = femaleCount / totalCount * 100;
    float otherPercentage = otherGender / totalCount * 100;
    float totalPercentage = malePercentage + femalePercentage + otherPercentage;


    string color;

    for (int i = 0; i <= 2 * radius; ++i) {
        cout << "                        ";
        for (int j = 0; j <= 2 * radius; ++j) {
            int x = i - radius;
            int y = j - radius;
            int distance = sqrt((x * x) + (y * y));
            if (distance <= radius) {
                float angle = atan2(x, y) * 180 / 3.14159;
                if (angle < 0) {
                    angle += 360;
                }
                float cir_male = malePercentage / totalPercentage * 360;
                float cir_female = cir_male + femalePercentage / totalPercentage * 360;
                float cir_other = cir_female + otherPercentage / totalPercentage * 360;
                if (angle <= cir_male) {
                    color = "\033[34m";
                } else if (angle <= cir_female) {
                    color = "\033[1;36m";
                } else if (angle <= cir_other) {
                    color = "\033[1;35m";
                }
                cout << color << " #" << "\033[0m";
            } else {
                cout << color << "\033[37m" << "..";
            }
        }
        cout << endl;
    }
    cout << "                        " << malePercentage << " %" << color << "\033[34m" << " Male " << color << "\033[0m" << endl;
    cout << "                        " << femalePercentage << " %" << color << "\033[36m" << " Female " << color << "\033[0m"<< endl;
    cout << "                        " << otherPercentage << " %" << color << "\033[35m" << " Other " << color << "\033[0m"<< endl;


    cout << "Select an Option :\n"
            "1. Change PI chart settings\n"
            "2. Go Back\n";
    cin >> choice;
    system("clear");
    if (choice == 1) {

            cout << "\033[33m Select an Option:\n"
                    "1. Set Radius to 5\n"
                    "2. Set Radius to 10\n"
                    "3. Set Radius to 15\n"
                    "4. Set Radius to 20\n"
                    "5. Set Radius to 25\n"
                    "6. Set Radius to 30\n"
                    "0. Save\n";
            cin >> select;
            if (select >= 1 && select <= 6) {
                radius = select * 5;
            }
            cout << "Success" << endl;
            get_gender_info();
            return;


    } else if (choice == 2) {
        // handle go back
    }
}
