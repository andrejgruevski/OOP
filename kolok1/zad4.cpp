//
// Created by Huhe on 3/22/2025.
//
#include<iostream>
#include<cstring>
using namespace std;

class Patnik{

private:
    char name[101];
    int klasa;
    bool velosiped;
public:
    Patnik(char *name="", int klasa=0, bool velosiped= false)  {
        strcpy(this->name,name);
        this->klasa=klasa;
        this->velosiped=velosiped;
    }
    Patnik(const Patnik &p){
        strcpy(this->name,p.name);
        this->klasa=p.klasa;
        this->velosiped=p.velosiped;
    }

    friend ostream &operator<<(ostream &os, const Patnik &patnik) {
        os<<patnik.name<<endl;
        os<<patnik.klasa<<endl;
        os<<patnik.velosiped<<endl;
        return os;
    }

    bool isVelosiped() const {
        return velosiped;
    }

    int getKlasa() const {
        return klasa;
    }
};

class Voz{

private:
    char destinacija[101];
    Patnik *patnici;
    int brPatnici;
    int brTochaci;
public:
    Voz(char *destinacija="", int brTochaci=0)  {
        strcpy(this->destinacija,destinacija);
        this->brTochaci=brTochaci;
        this->patnici = nullptr;
        this->brPatnici = 0;

    }
    Voz(const Voz &v)  {
        strcpy(this->destinacija,v.destinacija);
        this->brTochaci=v.brTochaci;
        this->brPatnici=v.brPatnici;
        this->patnici = new Patnik[brPatnici];
        for (int i = 0; i < brPatnici; ++i) {
            this->patnici[i]=v.patnici[i];
        }
    }
    ~Voz(){
        delete[]patnici;
    }
    Voz &operator = (const Voz &v){
        if (this != &v){
            delete[]patnici;
            strcpy(this->destinacija,v.destinacija);
            this->brTochaci=v.brTochaci;
            this->brPatnici=v.brPatnici;
            this->patnici = new Patnik[brPatnici];
            for (int i = 0; i < brPatnici; ++i) {
                this->patnici[i]=v.patnici[i];
            }
        }
        return *this;
    }
    Voz &operator +=(const Patnik &v){
        if (v.isVelosiped() && brTochaci ==0){
            return *this;
        }
        Patnik *tmp = new Patnik[brPatnici + 1];
        for (int i = 0; i < brPatnici; ++i) {
            tmp[i] = patnici[i];
        }
        tmp[brPatnici] = v;
        delete[]patnici;
        patnici=tmp;
        brPatnici++;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Voz &voz) {
        os<< voz.destinacija<<endl;
        for (int i = 0; i < voz.brPatnici; ++i) {
            os<<voz.patnici[i]<<endl;
        }
        return os;
    }



    void patniciNemaMesto(){
        int K1 = 0;
        int K2 = 0;
        int tochaci = 0;

        for (int i = 0; i < brPatnici; ++i) {
            if (patnici[i].isVelosiped() && patnici[i].getKlasa() == 1){
                if (tochaci < brTochaci){
                    tochaci++;
                }else{
                    K1++;
                }
            }
        }

        for (int i = 0; i < brPatnici; ++i) {
            if (patnici[i].isVelosiped() && patnici[i].getKlasa() == 2){
                if (tochaci < brTochaci){
                    tochaci++;
                }else{
                    K2++;
                }
            }
        }
        cout<<"Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "<<K1<<endl;
        cout<<"Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: "<<K2<<endl;


    }


};


int main()
{
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    //cout<<v<<endl;
    for (int i = 0; i < n; i++){
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        //cout<<p<<endl;
        v += p;
    }
    cout << v;
    v.patniciNemaMesto();

    return 0;
}
//class Gitara{
//private:
//    char seriski[25];
//    double nabavna;
//    int godinaProizvodstvo;
//    char tip[40];
//public:
//    Gitara(char *tip="",char * seriski ="",int godinaProizvodstvo=0,double nabavna =0)
//    {
//        strcpy(this->tip,tip);
//        strcpy(this->seriski,seriski);
//        this->godinaProizvodstvo = godinaProizvodstvo;
//        this->nabavna = nabavna;
//    }
//    Gitara(const Gitara &g)
//    {
//        strcpy(this->tip,g.tip);
//        strcpy(this->seriski,g.seriski);
//        this->godinaProizvodstvo = g.godinaProizvodstvo;
//        this->nabavna = g.nabavna;
//    }
//    Gitara & operator=(const Gitara &g)
//    {
//        strcpy(this->tip,g.tip);
//        strcpy(this->seriski,g.seriski);
//        this->godinaProizvodstvo = g.godinaProizvodstvo;
//        this->nabavna = g.nabavna;
//        return *this;
//    }
//    ~Gitara()
//    {
//    }
//    bool daliIsti(Gitara &g)
//    {
//        return strcmp(this->seriski,g.seriski)==0;
//    }
//    void pecati()
//    {
//        cout<<seriski<<" "<<tip<<" "<<nabavna<<endl;
//    }
//    double getNabavna()
//    {
//        return nabavna;
//    }
//    char * getTip()
//    {
//        return tip;
//    }
//    char * getSeriski()
//    {
//        return seriski;
//    }
//    int getGodina()
//    {
//        return godinaProizvodstvo;
//    }
//};
//
//class Magacin{
//private:
//    char lokacija[60];
//    char ime[50];
//    int godinaOtvaranje;
//    Gitara * niza;
//    int brGitari;
//public:
//    Magacin(char * ime="",char * lokacija="",int godinaOtvaranje=0)
//    {
//        strcpy(this->lokacija,lokacija);
//        strcpy(this->ime,ime);
//        this->godinaOtvaranje = godinaOtvaranje;
//        niza = NULL;
//        brGitari = 0;
//    }
//    Magacin(const Magacin & m)
//    {
//        strcpy(this->lokacija,m.lokacija);
//        strcpy(this->ime,m.ime);
//        this->godinaOtvaranje = m.godinaOtvaranje;
//        niza = new Gitara[m.brGitari];
//        for(int i =0;i<m.brGitari;i++)
//            niza[i] = m.niza[i];
//        brGitari = m.brGitari;
//    }
//
//    Magacin & operator=(const Magacin & m)
//    {
//        delete [] niza;
//        strcpy(this->lokacija,m.lokacija);
//        strcpy(this->ime,m.ime);
//        this->godinaOtvaranje = m.godinaOtvaranje;
//        niza = new Gitara[m.brGitari];
//        for(int i =0;i<m.brGitari;i++)
//            niza[i] = m.niza[i];
//        brGitari = m.brGitari;
//        return *this;
//    }
//    ~Magacin(){delete [] niza;}
//    double vrednost()
//    {
//        double sum=0;
//        for(int i=0;i<brGitari;i++)
//            sum+=niza[i].getNabavna();
//        return sum;
//
//    }
//    void dodadi(Gitara & g)
//    {
//        Gitara * tmp = new Gitara[brGitari +1];
//        for(int i=0;i<brGitari;i++)
//            tmp[i] = niza[i];
//        tmp[brGitari++]=g;
//        delete [] niza;
//        niza=tmp;
//
//    }
    void prodadi(Gitara & g)
    {
        int newBr = 0;
        for(int i=0;i<brGitari;i++)
        {
            if(niza[i].daliIsti(g)==false)
            {
                newBr++;
            }
        }
        Gitara * tmp = new Gitara[newBr];
        int j=0;
        for(int i=0;i<brGitari;i++)
        {
            if(niza[i].daliIsti(g)==false)
            {
                tmp[j] = niza[i];
                j++;
            }
        }
        delete [] niza;
        niza = tmp;
        brGitari = newBr;
    }
//    void pecati(bool daliNovi)
//    {
//        cout<<ime<<" "<< lokacija<<endl;
//        for(int i=0;i<brGitari;i++)
//        {
//            if(daliNovi==true&&niza[i].getGodina()>godinaOtvaranje)
//            {
//                niza[i].pecati();
//            }
//            else if(daliNovi==false){
//                niza[i].pecati();
//            }
//        }
//    }
//};