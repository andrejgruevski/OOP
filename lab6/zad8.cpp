//
// Created by Huhe on 4/22/2025.
//
//Да се напише класа Ingredient која ги содржи следните податоци за една состојка:
//name - име на состојката, динамички алоцирана низа од карактери;
//quantity - количина
//        calories - колку калории содржи состојката
//За класата да се напишат default конструктор, конструктор со аргументи, copy конструктор и десктруктор.
//Метод кој што ќе го враќа бројот на калории на состојката: quantity*calories
//Да се преоптовари операторот << за да ги печати објектите од класата во следниот формат: [name] [quantity]
//Да се преоптовари операторот = .
//Потоа да се дефинира класата Dish, која ги содржи следните податоци:
//ingredients - динамички алоцирана низа од Ingredient објекти
//dishName - динамички алоцирана низа од цели karakteri
//ingredientCount - број на состојки во јадењето
//        За класата да се дефинираат конструктор со параметри, copy конструктор, деструктор, како и следните методи:
//Метод getTotalCaloreis кој што ќе го враќа бројот на калории на специјалитетот за сите состојки
//        оператор + кој како резултат дава ново јадење со состојки од двете јадења
//        оператор += кој во јадењето ќе додава нови состојки
//        оператор == кој ќе проверува дали две јадења имаат ист број на калории
//        оператор << за печатење на објектот во следниот формат:
//Dish: Pizza
//        Tomato: 200g/ml
//        Cheese: 50g/ml
//        Total Calories: 6500
//Да не се менува main функцијата. Се признаваат и решенија без динамичка алокација на меморија.
#include <iostream>
#include <cstring>
using namespace std;
class Ingredient {
private:
    char *name;
    int quantity;
    double calories;
    void copy(const Ingredient &i) {
        name=new char[strlen(i.name)+1];
        strcpy(name,i.name);
        quantity=i.quantity;
        calories=i.calories;
    }
public:
    Ingredient(const char *name="", int quantity=0, double calories=0.0) {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->quantity = quantity;
        this->calories = calories;
    }
    Ingredient(const Ingredient &i) {
        copy(i);
    }
    Ingredient &operator=(const Ingredient &i) {
        if (this!=&i) {
            delete [] name;
            copy(i);
        }
        return *this;
    }
    ~Ingredient() {
        delete [] name;
    }
    double Calories() const {
        return calories*quantity;
    }
    friend ostream &operator<<(ostream &os, const Ingredient &i) {
        os << i.name << " " << i.quantity << endl;
        return os;
    }
};
class Dish{
private:
    Ingredient *ingredients;
    char *dishName;
    int n;
    void copy(const Dish &d) {
        n=d.n;
        ingredients = new Ingredient[d.n];
        for (int i=0;i<d.n;i++) {
            ingredients[i]=d.ingredients[i];
        }
        dishName = new char[strlen(d.dishName)+1];
        strcpy(dishName,d.dishName);
    }
public:
    Dish(const char *dishName="", Ingredient *ingredients=nullptr, int n=0) {
        this->dishName=new char[strlen(dishName)+1];
        strcpy(this->dishName,dishName);
        this->n=n;
        this->ingredients = new Ingredient[n];
        for (int i=0;i<n;i++) {
            this->ingredients[i]=ingredients[i];
        }
    }
    Dish(const Dish &d) {
        copy(d);
    }
    Dish &operator=(const Dish &d) {
        if (this!=&d) {
            delete [] ingredients;
            delete [] dishName;
            copy(d);
        }
        return *this;
    }
    ~Dish() {
        delete [] ingredients;
        delete [] dishName;
    }
    double getTotalCalories() const {
        double total=0.0;
        for (int i=0;i<n;i++) {
            total+=ingredients[i].Calories();
        }
        return total;
    }
    Dish operator+(const Dish &other) {
        Ingredient *res = new Ingredient[n+other.n];
        for (int i=0;i<n;i++) {
            res[i]=ingredients[i];
        }
        for (int i=0;i<other.n;i++) {
            res[n+i]=other.ingredients[i];
        }
        char * name = new char[strlen(dishName)+strlen(other.dishName)+6];
        name[0]='\0';
        strcat(name,dishName);
        strcat(name," and ");
        strcat(name,other.dishName);
        Dish d(name,res,n+other.n);
        return d;
    }
    Dish &operator+=(const Ingredient &i) {
        Ingredient *res = new Ingredient[n+1];
        for (int i=0;i<n;i++) {
            res[i]=ingredients[i];
        }
        res[n++]=i;
        delete [] ingredients;
        ingredients=res;
        return *this;
    }
    bool operator==(const Dish &other) {
        return getTotalCalories()==other.getTotalCalories();
    }
    friend ostream &operator<<(ostream &os, const Dish &d) {
        os<<"Dish: "<<d.dishName<<endl;
        for (int i=0;i<d.n;i++) {
            os<<d.ingredients[i];
        }
        os<<"Total calories: "<<d.getTotalCalories()<<endl;
        return os;
    }
};