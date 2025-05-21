//
// Created by Huhe on 5/21/2025.
//
//Да се креира класа VehicleRegistration во кој се чува податоци за едно возило. Класата треба да ги содржи следните аргументи:
//
//string registration_number;
//string manufacture_date;
//int mileage;
//int engine_power;
//int vehicle_age;
//double emission_level;
//Потребно е да се имплементираат:
//
//Default конструктор
//Конструктор со параметри
//        Copy конструктор
//        Оператор =
//        Оператор за читање istream>>
//Оператор за печатење ostream<< во следниот формат
//        Vehicle Reg: <registration_number> <manufacture_date> | Mileage <mileage>km Power <engine_power>hp Age <vehicle_age>y Emission <emission_level>g/km
//        Функцијата string VehicleCategory() која ги категоризира возилата во три категории: Restricted, Limited и Approved:
//Restricted - mileage > 250000 или vehicle_age > 20 или emission_level > 120.0 или engine_power < 60
//Limited - mileage > 150000 или vehicle_age > 15 или emission_level > 90.0 или engine_power < 80
//Approved - сите останати
//Да се напише глобалната функција FilterByVehicleCategory() која прима низа од VehicleRegistration, број на елементи и string категорија. Како резултат функцијата враќа нова динамички алоцирана низа која ги содржи само возилата од дадената категорија.
//
//Податоците се дадени во датотеката text.txt во форматот: прв ред - број на test case, втор ред - број на елементи, секој следен ред содржи податоци за едно возило (за читање на податоци за едно возило користете го istream операторот од класата).
//
//На почетокот во main() каде што има TODO да се вчитаат потребните податоци од датотека.
//
//*/
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

void writeToFile() {
    ofstream file("text.txt");
    char c;
    while ((c = cin.get()) != '#') {
        file.put(c);
    }
    file.close();
}

class VehicleRegistration {
private:
    string registration_number;
    string manufacture_date;
    int mileage;
    int engine_power;
    int vehicle_age;
    double emission_level;

public:




};

int main() {
    writeToFile();

    ifstream fin("text.txt");
    if (!fin) {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    // TODO: Вчитајте податоци од датотека (број на тест примери (testCase), број на записи (n) и податоци)
    int testCase, n;

    // Остатокот од кодот останува непроменет

    VehicleRegistration *records = new VehicleRegistration[n];
    for (int i = 0; i < n; i++) {
        fin >> records[i];
    }

    if (testCase == 1) {
        cout << "===== Testing Constructor, Istream Operator & Ostream Operator =====" << endl;
        for (int i = 0; i < n; i++) {
            cout << records[i];
        }
    }

    if (testCase == 2) {
        cout << "===== Testing VehicleCategory Function =====" << endl;
        for (int i = 0; i < n; i++) {
            cout << records[i].VehicleCategory() << endl;
        }
    }

    if (testCase == 3) {
        cout << "===== Testing FilterByVehicleCategory Global Function =====" << endl;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (records[i].VehicleCategory() == "Approved") {
                count++;
            }
        }
        VehicleRegistration *filtered = FilterByVehicleCategory(records, n, "Approved");
        cout << "Approved Vehicles:" << endl;
        for (int i = 0; i < count; i++) {
            cout << filtered[i];
        }
        delete[] filtered;
    }

    if (testCase == 4) {
        cout << "===== Testing FilterByVehicleCategory Global Function =====" << endl;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (records[i].VehicleCategory() == "Limited") {
                count++;
            }
        }
        VehicleRegistration *filtered = FilterByVehicleCategory(records, n, "Limited");
        cout << "Limited Vehicles:" << endl;
        for (int i = 0; i < count; i++) {
            cout << filtered[i];
        }
        delete[] filtered;
    }

    if (testCase == 5) {
        cout << "===== Testing FilterByVehicleCategory Global Function =====" << endl;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (records[i].VehicleCategory() == "Restricted") {
                count++;
            }
        }
        VehicleRegistration *filtered = FilterByVehicleCategory(records, n, "Restricted");
        cout << "Restricted Vehicles:" << endl;
        for (int i = 0; i < count; i++) {
            cout << filtered[i];
        }
        delete[] filtered;
    }

    delete[] records;
    return 0;
}

//Input	Result
//1
//4
//ABC123 2020-05-15 85000 150 3 85.5
//XYZ789 2015-03-22 180000 120 8 95.2
//DEF456 2010-01-10 280000 90 13 130.8
//GHI999 2022-11-08 25000 200 1 45.3
//#
//===== Testing Constructor, Istream Operator & Ostream Operator =====
//Vehicle Reg: ABC123 2020-05-15 | Mileage 85000km Power 150hp Age 3y Emission 85.5g/km
//        Vehicle Reg: XYZ789 2015-03-22 | Mileage 180000km Power 120hp Age 8y Emission 95.2g/km
//        Vehicle Reg: DEF456 2010-01-10 | Mileage 280000km Power 90hp Age 13y Emission 130.8g/km
//        Vehicle Reg: GHI999 2022-11-08 | Mileage 25000km Power 200hp Age 1y Emission 45.3g/km