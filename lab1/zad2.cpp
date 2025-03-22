//
// Created by Huhe on 3/9/2025.
//
#include "iostream"
using namespace std;

struct Engine{
    int hp;
    int torque;
};
struct Car{
    char name[50];
    int year;
    Engine motor;
};

void print (Car car){
    cout << "Manufacturer: "<<car.name<<endl;
    cout<<"Horsepower: "<<car.motor.hp<<endl;
    cout<<"Torque: "<<car.motor.torque<<endl;
}

void read(Car car[], int n){
    for (int i = 0; i < n; ++i) {
        cin>>car[i].name >> car[i].year >> car[i].motor.hp >> car[i].motor.torque;
    }
}

void printCars(Car car[], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (car[i].motor.hp > car[j].motor.hp ){
                swap(car[i],car[j]);
            }
        }
    }
    if (car[0].motor.torque > car[1].motor.torque){
        print (car[0]);
    }else{
        print(car[1]);
    }
}
int main (){
    int n;
    cin>>n;
    Car cars[100];
    read(cars,n);
    printCars(cars,n);
    return 0;
}