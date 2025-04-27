//
// Created by Huhe on 4/27/2025.
//
#include "iostream"
#include "cstring"
using namespace std;
class Ekipa{
protected:
    char ime[15];
    int porazi;
    int pobedi;
public:
    Ekipa(char *name="",int pobedi=0, int porazi=0 ){
        strcpy(this->ime,name);
        this->pobedi=pobedi;
        this->porazi=porazi;
    }
    void pecati(){
        cout << "Ime: " << ime << " Pobedi: " << pobedi << " Porazi: " << porazi;
    }
};
class FudbalskaEkipa:public Ekipa{
private:
    int crveni;
    int zholti;
    int neresheni;
public:
    FudbalskaEkipa(char *name="",int pobedi=0, int porazi=0,int crveni=0,int zholti=0,int neresheni=0):Ekipa(ime,pobedi,porazi){
        crveni=0;
        zholti=0;
        neresheni=0;
    }
    void pecati(){
        Ekipa::pecati();
        cout << " Nereseni: " << neresheni << " Poeni: " << pobedi * 3 + neresheni << endl;
    }
};
int main()
{
    char ime[15];
    int pob, por, ck, zk, ner;
    cin >> ime >> pob >> por >> ck >> zk >> ner;
    FudbalskaEkipa f1(ime, pob, por, ck, zk, ner);
    f1.pecati();
    return 0;
}