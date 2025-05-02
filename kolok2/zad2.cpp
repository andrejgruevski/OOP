//
// Created by Huhe on 4/29/2025.
//
// vashiot kod ovde
#include "iostream"
#include "cstring"
using namespace std;
class Vozac{
protected:
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
public:
    Vozac(char *ime="", int vozrast=0, int trki=0, bool vet=false){
        strcpy(this->ime,ime);
        this->vozrast=vozrast;
        this->trki=trki;
        this->vet=vet;
    }
    Vozac(const Vozac &v){
        strcpy(this->ime,v.ime);
        this->vozrast=v.vozrast;
        this->trki=v.trki;
        this->vet=v.vet;
    }

    friend ostream &operator<<(ostream  &os, const Vozac  &out){
        os<<out.ime<<endl;
        os<<out.vozrast<<endl;
        os<<out.trki<<endl;
        if (out.vet){
            cout<<"VETERAN"<<endl;
        }
        return os;
    }
    virtual double zarabotuvachka() const = 0;
    virtual double danok() const =0;
    bool operator==(Vozac &v){
        return zarabotuvachka() == v.zarabotuvachka();
    }
};
class Avtomobilist:public Vozac{
private:
    double cena;
public:
    Avtomobilist(char *ime="", int vozrast=0, int trki=0, bool vet=false,double cena=0):
            Vozac(ime,vozrast,trki,vet){
        this->cena=cena;
    }

    double zarabotuvachka() const override {
        return cena / 5.0;
    }
     double danok()const override{
        if (trki>10){
            return zarabotuvachka() * 0.15;
        }
        return zarabotuvachka() * 0.10;
    }
};
class Motociklist:public Vozac{
private:
    int mokjnost;
public:
    Motociklist(char *ime="", int vozrast=0, int trki=0, bool vet=false,int mokjnost=0):
            Vozac(ime,vozrast,trki,vet){
        this->mokjnost=mokjnost;
    }

    double zarabotuvachka() const override{
        return mokjnost * 20;
    }
    double danok()const override{
        if (vet){
            return zarabotuvachka() * 0.25;
        }
        return zarabotuvachka() * 0.20;
    }
};
int soIstaZarabotuvachka(Vozac**vozaci, int n,Vozac *vx){
    int br=0;
    for (int i = 0; i < n; ++i) {
        if (vozaci[i]->zarabotuvachka() == vx->zarabotuvachka()){
            br++;
        }
    }
    return br;

}

int main() {
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac*[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for(int i = 0; i < n; ++i) {
        cin >> ime >> vozrast >> trki >> vet;
        if(i < x) {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        } else {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for(int i = 0; i < n; ++i) {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
    return 0;
}