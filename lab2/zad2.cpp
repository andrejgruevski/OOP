//
// Created by Huhe on 3/10/2025.
//
#include "iostream"
#include "cstring"
#include "algorithm"
using namespace std;
class Country{
private:
    char name[100];
    char capital[100];
    double area;
    double population;
public:
    Country(){

    }

    Country(char *name, char *capital, double area, double population){
        strcpy(this->name,name);
        strcpy(this->capital,capital);
        this->area=area;
        this->population=population;
    }
    void setName(char *n){
        strcpy(this->name,n);
    }
    void setCapital(char *c){
        strcpy(this->capital,c);
    }

    bool operator<(const Country &rhs) const {
        return area<rhs.area;
    }


    const char *getName() const {
        return name;
    }

    const char *getCapital() const {
        return capital;
    }

    double getArea() const {
        return area;
    }

    void setArea(double area) {
        Country::area = area;
    }

    double getPopulation() const {
        return population;
    }

    void setPopulation(double population) {
        Country::population = population;
    }
    void display(){
        cout<<"Country: "<<name<<endl;
        cout<<"Capital: "<<capital<<endl;
        cout<<"Area: "<<area<<endl;
        cout<<"Population: "<<population<<endl;
    }
};
//void sortCountries(Country *countries, int n){
//    sort(countries,countries+n);
//}
void sortCountries(Country *countries, int n) {
    for (int i = 0; i < n; i++) {
        for (int j=0;j<n-1-i;j++) {
            if (countries[j].getArea()>countries[j+1].getArea()) { //rastechki
                Country temp = countries[j];
                countries[j] = countries[j+1];
                countries[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        countries[i].display();
    }
}
int main() {
    int n;
    cin >> n;
    Country countries[100];

    char name[100];
    char capital[100];
    float area;
    float population;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin >> capital;
        cin >> area;
        cin>>population;

        // testing constructor with arguments
        countries[i] = Country(name, capital, area, population);

    }


    // testing set methods and display for last element
    cin>>name;
    cin >> capital;
    cin >> area;
    cin>>population;
    countries[n-1].setName(name);
    countries[n-1].setCapital(capital);
    countries[n-1].setArea(area);
    countries[n-1].setPopulation(population);

    cout<<"-->Testing set methods and display()"<<endl;
    countries[n-1].display();
    cout<<endl;

    cout<<"-->Testing sortCountries()"<<endl;
    sortCountries(countries,n);
    return 0;
}