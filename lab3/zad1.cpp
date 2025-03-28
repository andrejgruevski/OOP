
//Да се дефинира класа MobilePhone во која ќе се чуваат податоци за еден мобилен телефон:
//
//модел (низа од карактери не подолга од 20 карактери)
//број на модел (цел број)
//година на издавање (цел број)
//За класата да се дефинира default конструктор, конструктор со аргументи, copy конструктор, деструктор и доколку има потреба get методи. Исто така да се дефинира и фунцкија за печатење на информации за класата која ќе печати во следниот формат „(модел) (број на модел) release year: (година на издавање)“.
//
//Потоа да се дефинира класа Owner во која се чуваат следните информации:
//
//име (низа од карактери не подолга од 20 карактери)
//презиме (низа од карактери не подолга од 20 карактери)
//мобилен телефон (објект од класа MobilePhone)
//Да се креира default конструктор, конструктор со аргументи, деструктор и доколку има потреба get методи. Исто така да се дефинира и функција за печатење на информации за класата која ќе печати во следниот формат:
//
//„(име) (презиме) has a mobile phone:
//
//(информации за мобилен телефон)“
//
//ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА!!!
#include "iostream"
#include "cstring"
using namespace std;
class MobilePhone{
private:
    char model[21];
    int brModel;
    int godina;
public:
    MobilePhone(char *model="", int brModel=0, int godina=0) {
        strcpy(this->model,model);
        this->brModel=brModel;
        this->godina=godina;
    }
    MobilePhone(const MobilePhone &m){
        strcpy(this->model,m.model);
        this->brModel=m.brModel;
        this->godina=m.godina;
    }
    void pechati(){
        cout<<model<<" "<<brModel<<" release year: "<<godina<<endl;
    }
};
class Owner{
private:
    char name[20];
    char surname[20];
    MobilePhone tel;
public:
    Owner(){

    }
    Owner(char *name, char *surname, MobilePhone tel) {
        strcpy(this->name,name);
        strcpy(this->surname,surname);
        this->tel=tel;
    }

    void print(){
        cout<<name<<" "<<surname<<" has a mobile phone: "<<endl;
        tel.pechati();
    }
};
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