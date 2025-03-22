//
// Created by Huhe on 3/9/2025.
//
#include "iostream"
#include "cstring"
using namespace std;

class BasketballPlayer{
private:
    char name[21];
    char surname[21];
    int number;
    int p1;
    int p2;
    int p3;
public:
    BasketballPlayer(char *name, char *surname, int number, int p1, int p2, int p3) {
        strcpy(this->name,name);
        strcpy(this->surname,surname);
        this->number=number;
        this->p1=p1;
        this->p2=p2;
        this->p3=p3;
    }

    int avgPoints(){
        return (p1+p2+p3)/3;
    }
    void print(){
        cout<<"Player: "<<name<<" "<<surname<<
        " with number: "<<number<< " has "<<
        avgPoints()<<" points on average"<<endl;
    }
    void read(){
        cin>>name>>surname>>number>>p1>>p2>>p3;
    }
};
int main(){
    char name[21];
    char surname[21];
    int number,p1,p2,p3;
    cin>>name>>surname>>number>>p1>>p2>>p3;

    BasketballPlayer p(name,surname,number,p1,p2,p3);
    p.print();


    return 0;
}