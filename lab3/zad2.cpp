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
//
// Created by Huhe on 3/28/2025.
//
#include "iostream"
#include "cstring"
using namespace std;
class Flight {
private:
    char name[100];
    char departure[50];
    char arrival[50];
    int price;
public:
    Flight(char *name="", char *departure="", char *arrival="", int price=0) {
        strcpy(this->name,name);
        strcpy(this->departure,departure);
        strcpy(this->arrival,arrival);
        this->price=price;
    }
    Flight(const Flight &f){
        strcpy(this->name,f.name);
        strcpy(this->departure,f.departure);
        strcpy(this->arrival,f.arrival);
        this->price=f.price;
    }

    int getPrice() const {
        return price;
    }

    const char *getName() const {
        return name;
    }

};
class Airport{
private:
    char nameAirport[50];
    int numFlights;
    Flight flights[100];
public:
    Airport(char *nameAirport=" ", int numFlights=0) {
        strcpy(this->nameAirport,nameAirport);
        this->numFlights=numFlights;
        for (int i = 0; i < numFlights; ++i) {
            this->flights[i] = flights[i];
        }
    }
};

void cheapestFlight(Flight arr[], int n){
    int cheapest = 0;
    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i].getPrice() < cheapest){
            cheapest = arr[i].getPrice();
            index = i;
        }
    }
    cout<<"Cheapest flight: "<<arr[index].getName()<<" with price: "<<arr[index].getPrice()<<endl;
}

int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        char name[100], departure[50], arrival[50];
        int price;
        cin >> name >> departure >> arrival >> price;
        Flight flight(name, departure, arrival, price);
        cout << "Flight created: " << flight.getName() << " with price: " << flight.getPrice() << endl;
    }
    else if (testCase == 2) {
        char name[100], departure[50], arrival[50];
        int price;
        cin >> name >> departure >> arrival >> price;
        Flight flight1(name, departure, arrival, price);
        Flight flight2(flight1);
        cout << "Copied flight: " << flight2.getName() << " with price: " << flight2.getPrice() << endl;
    }
    else {
        int numFlights;
        cin >> numFlights;
        Flight flights[10];
        for (int i = 0; i < numFlights; i++) {
            char name[100], departure[50], arrival[50];
            int price;
            cin >> name >> departure >> arrival >> price;
            flights[i] = Flight(name, departure, arrival, price);
        }
        cheapestFlight(flights, numFlights);
    }
    return 0;
}
