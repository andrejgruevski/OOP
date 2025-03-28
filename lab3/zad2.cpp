//
// Created by Huhe on 3/24/2025.
//
//Да се дефинира класа Flight во која што ќе се чуваат податоци за лет:
//
//име на лет (низа од максимум 100 карактери)
//полетување од (низа од максимум 50 карактери)
//пристигнување во (низа од максимум 50 карактери)
//цена на лет (цел број)
//За класата да се дефинира copy конструктор, default конструктор и конструктор со аргументи.
//Доколку е потребно да се креираат и get методи.
//
//Потоа да се креира класа Airport во која што се чуваат следните податоци:
//
//име на аеродром (низа од максимум 50 карактери)
//број на летови на аеродромот(цел број)
//низа од летови на аеродромот(низа од објекти од Flight класата, max 100)
//Да се креира конструктор со аргументи за класата.
//Доколку е потребно да се креира и get методи.
//
//Во класата да се креира функција cheapestFlight што ќе го врати најевтиниот лет на аеродромот.
//
//ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА.
#include "iostream "
#include "cstring"
using namespace std;

class Flight {
private:
    char ime[30];
    char arrival[30];
    char departure[30];
    int cena;
public:
    Flight(const char* ime = "", const char* arr = "", const char* dep = "", int _ena = 0) {
        strcpy(this->ime, ime);
        strcpy(this->arrival, arr);
        strcpy(this->departure, dep);
        this->cena = cena;
    }

    ~Flight() {}

    const char* getFlightName() const{
        return ime;
    }



    int getCena() const {
        return cena;
    }

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

    Airport(const char* ia = "", int _brL = 0, Flight* ll = nullptr) {
        brLetovi = _brL;
        if (ll) {
            for (int i = 0; i < _brL; i++) {
                listaLetovi[i] = ll[i];
            }
        }
        strcpy(imeAerodrom, ia);
    }

};


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

    Flight f1("Flight 101", "Belgrade", "Paris", 250);
    Flight f2("Flight 102", "New York", "London", 150);
    Flight f3("Flight 103", "Berlin", "Dubai", 200);

    Flight flights[] = {f1, f2, f3};
    Airport airport("Nikola Tesla", 3, flights);


    cheapestFlight(flights, 3);

    return 0;
}