//
// Created by Huhe on 3/24/2025.
//
#include <iostream>
#include <cstring>
using namespace std;
class MobilePhone{

    char model[20];
    int year;
    int serialNumber;
public:
    MobilePhone(){}
    MobilePhone(char *model,int serialNumber,int year){
        strcpy(this->model,model);
        this->year=year;
        this->serialNumber =serialNumber;
    }
    ~MobilePhone(){}

    char *getmodel(){
        return this->model;
    }
    int getseriski(){
        return this->serialNumber;
    }
    int getgodina(){
        return this->year;
    }
    void show(){
        cout<<model<<" "<<serialNumber<<" release year: "<<year;
    }
};

class Owner{
    char name[20],surname[20];
    MobilePhone tel;
public:
    Owner(){}
    Owner(char *name,char *surname,MobilePhone tel){
        strcpy(this->name,name);
        strcpy(this->surname,surname);
        this->tel=tel;
    }
    ~Owner(){}
    char *getname(){
        return this->name;
    }
    char *getprezime(){
        return this->surname;
    }
    MobilePhone gettel(){
        return this->tel;
    }
    void print(){
        cout<< this->name<<" "<<this->surname<<" has a mobile phone:"<<endl;
        tel.show();
    }
};
//DO NOT CHANGE THE MAIN FUNCTION
int main() {
    char model[20];
    int modelNumber;
    int year;
    char name[20];
    char surname[20];

    int testCase;

    cin>>testCase;

    cin>>model;
    cin>>modelNumber;
    cin>>year;
    cin>>name;
    cin>>surname;

    if(testCase==1){
        MobilePhone mobilePhone(model,modelNumber,year);

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }
    if(testCase==2){
        MobilePhone mobilePhone(MobilePhone(model,modelNumber,year));

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }

};