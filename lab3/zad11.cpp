//
// Created by Huhe on 3/28/2025.
//
//Да се дефинира класа Employee во која ќе се чуваат информации за:
//
//name(низа од максимум 100 карактери) -име на вработениот
//
//        surname(низа од максимум 100 карактери) - презиме
//
//salary(цел број) - колку му е платата
//
//методи кои што класата треба да ги има:
//
//print()
//
//-Принта во формат:
//Employee name:
//
//Employee surname:
//
//Employee salary:
//
//Да се дефинира класа TechCompany во која ќе се чуваат информации за:
//
//name(низа од максимум 100 карактери) -име на фирмата
//
//        employees(низа од вработени)
//
//numOfEmployees(цел број) - колку вработени има во фирмата
//
//        методи кои што класата треба да ги има:
//
//print()
//
//-Принта во формат:
//Tech company name:
//
//Number of employees:
//
//double getAverageOfEmployeeсSalary()
//
//-Враќа средна врендност од платите на секој вработен во таа фирма
//
//
//        Сите променливи внатре во класите треба да бидат приватни. Соодветно во рамките на класите да се дефинираат:
//
//конструктор (без и со параметри)
//
//деструктор
//
//        set методи
//
//        get методи
//
//        copy constructor
//
//        Функции надвор од класата:
//
//printCompanyWithHighestAverageSalary(TechCompany companies[], int numCompanies)
//
//-Го враќа TechCompany објектот што има најголема средна вредност за плати на неговите вработени
//printCompanyWithHighestStdSalary(TechCompany companies[], int numCompanies)
//
//-Го враќа TechCompany објектот што има најголема стандардна девијација за плати на неговите вработени
//VAR=∑for each Employee e[(e.salary−AVG)2]n−1STD=(√VAR)
//
//-Помош: AVG е средната вредност на платите на сите вработен во таа фирма, STD е стандардна девијација, VAR  е помошна променлива. И прво квадрирајте го изразот па потоа додадете го во сумата!
//isSameCompany(TechCompany company1, TechCompany company2)
//
//-Враќа boolean вредност: две фирми се исти ако имаат исто име. Треба само да се првери дали им е исто името!
//ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА.
#include <iostream>
#include <cstring>
#include <cmath>
#include <string.h>
using namespace std;
class Employee{
    char name[50],surname[50];
    int salary;
public:
    Employee(){}
    Employee(char *name, char *surname,int salary){
        strcpy(this->name,name);
        strcpy(this->surname,surname);
        this->salary=salary;
    }
    Employee(const Employee &s){
        this->salary=s.salary;
        ::strcpy(this->name,s.name);
        strcpy(this->surname,s.surname);
    }
    ~Employee(){}
    void setName(char *name){
        ::strcpy(this->name,name);
    }
    void setSalary(int s){
        this->salary=s;
    }
    void setSurname(char *s){
        ::strcpy(this->surname,s);
    }
    int getSalary(){
        return this->salary;
    }
    char *getSurname(){
        return this->surname;
    }
    char *getName(){
        return this->name;
    }
    void printEmployee(){
        cout<<"Employee name: "<<this->name<<endl;
        cout<<"Employee surname: "<< this->surname<<endl;
        cout<<"Employee salary: "<<this->salary<<endl;
    }

};

class TechCompany{
    char name[50];
    Employee employees[100];
    int numOfEmployees;
public:
    TechCompany(char *name=" "){
        ::strcpy(this->name,name);
        numOfEmployees=0;
        //this->employees=new Employee [numOfEmployees];
    }
    TechCompany(const TechCompany &s){
        strcpy(this->name,s.name);
        this->numOfEmployees=s.numOfEmployees;
        for (int i = 0; i <numOfEmployees ; ++i) {
            employees[i]=s.employees[i];
        }
    }
    /*TechCompany &operator=(TechCompany &s){
        if(this!=&s){
            delete[]employees;
            strcpy(this->name,s.name);
            this->numOfEmployees=s.numOfEmployees;
            for (int i = 0; i <numOfEmployees ; ++i) {
                employees[i]=s.employees[i];
            }
            return *this;
        }
    }*/
    ~TechCompany(){
        // delete[]employees;
    }
    void addEmployee(Employee other){
        employees[numOfEmployees]=other;
        numOfEmployees++;
    }
    void setNumOfEmployees(int n){
        this->numOfEmployees=n;
    }
    void setName(char *name){
        strcpy(this->name,name);
    }
    /*void setEmployees(Employee *e){
        this->employees=e;
    }*/
    Employee getEmployee(int i){
        return this->employees[i];
    }
    char *getName(){
        return this->name;
    }
    int getNumEmployees(){
        return this->numOfEmployees;
    }
    double getAverageOfEmployeesSalary(){
        int sum=0,br=0;
        for (int i = 0; i <numOfEmployees; ++i) {
            sum+=employees[i].getSalary();
            br++;
        }
        return (double)sum/br;
    }
    /*int getSalaryOfEmployee(Employee e,int n){

        return e.getSalary();
    }*/
    void print(){
        cout<<"Tech company name: "<< this->name<<endl<<"Number of employees: "<<numOfEmployees<<endl;
    }
    friend TechCompany printCompanyWithHighestStdSalary(TechCompany *companies, int n);
};

TechCompany printCompanyWithHighestAverageSalary(TechCompany *companies,int n){
    double max=0;
    TechCompany najdobra;
    for (int i = 0; i <n ; ++i) {
        if(companies[i].getAverageOfEmployeesSalary()>max){
            max=companies[i].getAverageOfEmployeesSalary();
            najdobra=companies[i];
        }
    }
    return najdobra;
}
TechCompany printCompanyWithHighestStdSalary(TechCompany *companies, int n){
    double VAR,STD,max=0;
    TechCompany najdobra;
    for (int i = 0; i < n; ++i) {
        int sum=0;
        for (int j = 0; j <companies[i].numOfEmployees ; ++j) {
            sum+= pow(companies[i].employees[j].getSalary()-companies[i].getAverageOfEmployeesSalary(),2);
        }
        VAR=sum/(companies[i].numOfEmployees-1);
        STD= ::sqrt(VAR);
        if(STD>max){
            max=STD;
            najdobra=companies[i];
        }
    }
    return najdobra;
}

bool isSameCompany(TechCompany n1,TechCompany n2){
    if (::strcmp(n1.getName(),n2.getName())==0)
        return true;
    else return false;
}
int main() {
    const int MAX_COMPANIES = 10;
    const int MAX_EMPLOYEES = 20;

    TechCompany companies[MAX_COMPANIES];

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        char name[100];
        std::cin >> name;

        TechCompany company(name);

        int m;
        std::cin >> m;

        for (int j = 0; j < m; j++) {
            char name[100];
            char surname[100];
            int salary;

            std::cin >> name;

            std::cin >> surname;

            std::cin >> salary;

            Employee employee(name, surname, salary);

            company.addEmployee(employee);
        }

        companies[i] = company;
    }

    TechCompany copy = companies[0];

    std::cout<<"-->Testing get and set methods for one object and copy constructor"<<std::endl;
    copy.setName("copy");
    std::cout << copy.getName() << std::endl;


    std::cout<<"-->Testing addEmployee function"<<std::endl;
    Employee newEmployee("John", "Doe", 5000);
    copy.addEmployee(newEmployee);
    std::cout << "Number of employees in copy: " << copy.getNumEmployees() << std::endl;


    std::cout<<"-->Testing copy of first employee"<<std::endl;
    Employee firstEmployee = copy.getEmployee(0);
    firstEmployee.printEmployee();


    std::cout<<"-->Testing methods"<<std::endl;
    TechCompany t = printCompanyWithHighestAverageSalary(companies, n);
    TechCompany t1 = printCompanyWithHighestStdSalary(companies, n);

    std::cout << "Tech company with the highest average salary: " << t.getName() << std::endl;
    std::cout << "Tech company with the highest standard deviation for salaries: " <<t1.getName() << std::endl;

    if (isSameCompany(t, t1)){
        std::cout<<"The tech company: "<<t.getName()<<" has the highest standard deviation and highest average salary"<<std::endl;
    }
    return 0;
};