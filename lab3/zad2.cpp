//
// Created by Huhe on 3/24/2025.
//
#include "iostream " // За INT_MAX
#include "cstring"
using namespace std;

class Flight {
private:
    char ime[30];
    char arrival[30];
    char departure[30];
    int cena;
public:
    Flight(const char* _ime = "", const char* _arr = "", const char* _dep = "", int _cena = 0) {
        strcpy(ime, _ime);
        strcpy(arrival, _arr);
        strcpy(departure, _dep);
        cena = _cena;
    }

    ~Flight() {}

    const char* getFlightName() const { return ime; }
    const char* getArrival() const { return arrival; }
    const char* getDeparture() const { return departure; }
    int getCena() const { return cena; }

// Copy конструктор
    Flight(const Flight& copyFlight) {
        strcpy(ime, copyFlight.ime);
        strcpy(arrival, copyFlight.arrival);
        strcpy(departure, copyFlight.departure);
        cena = copyFlight.cena;
    }
};

class Airport {
private:
    char imeAerodrom[30];
    int brLetovi;
    Flight listaLetovi[100];
public:
// Конструктор за аеродром
    Airport(const char* ia = "", int _brL = 0, Flight* ll = nullptr) {
        brLetovi = _brL;
        if (ll) {
            for (int i = 0; i < _brL; i++) {
                listaLetovi[i] = ll[i]; // Копирање на летовите од низата ll
            }
        }
        strcpy(imeAerodrom, ia);
    }

};

// Функција за најевтиниот лет
void cheapestFlight(Flight f[], int n) {
    int cheapest = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (f[i].getCena() < cheapest) {
            cheapest = f[i].getCena();
            index = i;
        }
    }
    cout << "Najevtin let: " << f[index].getFlightName() << " Cena: " << f[index].getCena() << endl;
}

int main() {
// Примерни летови
    Flight f1("Flight 101", "Belgrade", "Paris", 250);
    Flight f2("Flight 102", "New York", "London", 150);
    Flight f3("Flight 103", "Berlin", "Dubai", 200);

    Flight flights[] = {f1, f2, f3}; // Масив со летови
    Airport airport("Nikola Tesla", 3, flights); // Креирање на аеродром

// Пребарување на најевтиниот лет
    cheapestFlight(flights, 3);

    return 0;
}