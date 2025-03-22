//
// Created by Huhe on 3/16/2025.
//
#include<iostream>
#include<cstring>
using namespace std;
class Chocolate{
private:
    char name[100];
    int price;
public:
    Chocolate(char const *name="", int price=0) {
        strcpy(this->name,name);
        this->price=price;
    }

    friend ostream &operator<<(ostream &os, const Chocolate &chocolate) {
        os << chocolate.name << ": $" << chocolate.price;
        return os;
    }

    int getPrice() const {
        return price;
    }
};

class ChocolateFactory{
private:
    Chocolate *products;
    int *weeklyProduction;
    int numProducts;
public:
    ChocolateFactory(){

    }
    ChocolateFactory(Chocolate *products, int *weeklyProduction, int numProducts) {
        this->numProducts=numProducts;
        this->products = new Chocolate[numProducts];
        this->weeklyProduction = new int[numProducts];
        for (int i = 0; i < numProducts; ++i) {
            this->products[i] = products[i];
            this->weeklyProduction[i] = weeklyProduction[i];
        }

    }
    ~ChocolateFactory(){
        delete[]products;
        delete[]weeklyProduction;
    }
    int weeklyIncome()const{
        int suma = 0;
        for (int i = 0; i < numProducts; ++i) {
            suma+=products[i].getPrice() * weeklyProduction[i];
        }
        return suma;
    }

    bool operator<(const ChocolateFactory &rhs) const {
        return weeklyProduction < rhs.weeklyProduction;
    }

    bool operator>(const ChocolateFactory &rhs) const {
        return rhs < *this;
    }
    ChocolateFactory operator+(const ChocolateFactory &other) const {
        int newNumProducts = this->numProducts + other.numProducts;
        Chocolate *newProducts = new Chocolate[newNumProducts];
        int *newWeeklyProduction = new int[newNumProducts];

        for (int i = 0; i < this->numProducts; i++) {
            newProducts[i] = this->products[i];
            newWeeklyProduction[i] = this->weeklyProduction[i];
        }

        for (int i = 0; i < other.numProducts; i++) {
            newProducts[this->numProducts + i] = other.products[i];
            newWeeklyProduction[this->numProducts + i] = other.weeklyProduction[i];
        }

        ChocolateFactory result(newProducts, newWeeklyProduction, newNumProducts);
        delete[] newProducts;
        delete[] newWeeklyProduction;
        return result;
    }

    friend ostream &operator<<(ostream &os, const ChocolateFactory &factory) {
        for (int i = 0; i < factory.numProducts; ++i) {
            os<<factory.products[i] << " x " << factory.weeklyProduction[i] << endl;
        }
        os <<"$"<<factory.weeklyIncome()<<"/wk" <<endl;
        return os;
    }

};
int main() {
    int testCase;
    char name[100];
    int price;

    Chocolate products[100];
    int weeklyProduction[100];

    cin >> testCase;
    if (testCase == 0) {
        cout<<"Testing Chocolate print operator:"<<endl;
        for (int i = 0; i < 10; ++i) {
            cin>>name>>price;
            cout<<Chocolate(name,price)<<endl;
        }
    }
    else if (testCase == 1) {
        cout<<"Testing ChocolateFactory print operator:"<<endl;

        for (int i = 0; i < 10; ++i) {
            cin>>name>>price;
            products[i] = Chocolate(name, price);
            cin>>weeklyProduction[i];
        }

        ChocolateFactory cf(products,weeklyProduction,10);
        cout<<cf<<endl;
    }
    else if (testCase == 2) {
        cout<<"Testing ChocolateFactory comparison operators:"<<endl;

        for (int i = 0; i < 3; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf1 = ChocolateFactory(products,weeklyProduction,3);

        for (int i = 0; i < 4; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf2 = ChocolateFactory(products,weeklyProduction,4);

        cout<<cf1<<cf2;

        cout<<"< operator: "<< (cf1<cf2 ? "PASS" : "FAIL") <<endl;
        cout<<"> operator: "<< (cf2>cf1 ? "PASS" : "FAIL") <<endl;
    }
    else if (testCase == 3) {
        cout<<"Testing ChocolateFactory sum operator:"<<endl;

        for (int i = 0; i < 5; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf1 = ChocolateFactory(products,weeklyProduction,5);
        for (int i = 0; i < 5; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf2 = ChocolateFactory(products,weeklyProduction,5);

        cout<<cf1+cf2;
    }
}