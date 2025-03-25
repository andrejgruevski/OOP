//
// Created by Huhe on 3/24/2025.
//
#include "iostream " // За INT_MAX
#include "cstring"
using namespace std;
class Flight{
private:
    char name[100];
    char departure[50];
    char arrival[50];
    int cena;
public:
    Flight(char *name="", char *departure="", char *arrival="", int cena=0)  {
        strcpy(this->name,name);
        strcpy(this->departure,departure);
        strcpy(this->arrival,arrival);
        this->cena=cena;
    }
    Flight(const Flight &f){
        strcpy(this->name,f.name);
        strcpy(this->departure,f.departure);
        strcpy(this->arrival,f.arrival);
        this->cena=f.cena;
    }

    int getCena() const {
        return cena;
    }

    const char *getName() const {
        return name;
    }
};
class Airport{
    char ime[50];
    int letovi;
    Flight aer[100];
public:
    Airport(char *ime, int letovi, Flight *aer) {
        strcpy(this->ime,ime);
        this->letovi=letovi;
        for (int i = 0; i < letovi; ++i) {
            this->aer[i]=aer[i];
        }
    }


};
void cheapestFlight(Flight f[], int n){
    int najeftin = INT_MAX;
    int index=0;
    for (int i = 0; i < n; ++i) {
        if (f[i].getCena() < najeftin){
            najeftin = f[i].getCena();
            index = i;
        }
    }
    cout << "Najevtin let: " << f[index].getName() << " Cena: " << f[index].getCena() << endl;
};


int main() {

    Flight f1("Flight 101", "Belgrade", "Paris", 250);
    Flight f2("Flight 102", "New York", "London", 150);
    Flight f3("Flight 103", "Berlin", "Dubai", 200);

    Flight flights[] = {f1, f2, f3}; // Масив со летови
    Airport airport("Nikola Tesla", 3, flights); // Креирање на аеродром

// Пребарување на најевтиниот лет
    cheapestFlight(flights, 3);

    return 0;
}