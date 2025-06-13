//
// Created by Huhe on 5/22/2025.
//
#include<iostream>
#include<cstring>
using namespace std;

//место за вашиот код
class Delo{
private:
    char ime[51];
    int godina;
    char zemja[51];
public:
    Delo(){
        *ime='\0';
        godina=0;
        *zemja = '\0';
    }
    Delo(char *ime, int godina, char *zemja){
        strcpy(this->ime,ime);
        this->godina=godina;
        strcpy(this->zemja,zemja);
    }
    bool operator == (Delo &d){
       return (strcmp(ime,d.ime)==0);
    }
    int getGodina()const{
        return godina;
    }
    char *getIme() {
        return ime;
    }
};
class Pretstava{
private:
    Delo delo;
    int brojKarti;
    char data[16];
public:
    Pretstava(){
        brojKarti=0;
        *data = '\0';
    }
    Pretstava(Delo delo, int brojKarti, char *data){
       this->delo=delo;
       this->brojKarti=brojKarti;
        strcpy(this->data,data);
    }
    double cena(){
        int n,m;
        if (delo.getGodina() > 1900){
            m = 50;
        }else if (delo.getGodina() > 1800){
            n = 75;
        }else{
            n = 100;
        }

        if (strcmp(delo.getIme(),"Italija")==0){
            m = 100;
        }
        else if (strcmp(delo.getIme(),"Rusija")==0){
            m = 150;
        }else{
            m = 80;
        }

        return n+m;
    }
    
};
class Balet : public Pretstava{
    static int cenaPlus;
public:
    Balet():Pretstava(){

    }
    Balet(Delo delo, int brojKarti, char *data):Pretstava(delo,brojKarti,data){}
    int cena(){
        return Pretstava::cena() + cenaPlus;
    }
    static void setCenaBalet(int p){
        cenaPlus = p;
    }
};
//citanje na delo
Delo readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return Delo(ime,godina,zemja);
}
//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    Delo d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}
int main(){
    int test_case;
    cin>>test_case;

    switch(test_case){
        case 1:
            //Testiranje na klasite Opera i Balet
        {
            cout<<"======TEST CASE 1======="<<endl;
            Pretstava* p1=readPretstava();
            cout<<p1->getDelo().getIme()<<endl;
            Pretstava* p2=readPretstava();
            cout<<p2->getDelo().getIme()<<endl;
        }break;

        case 2:
            //Testiranje na  klasite Opera i Balet so cena
        {
            cout<<"======TEST CASE 2======="<<endl;
            Pretstava* p1=readPretstava();
            cout<<p1->cena()<<endl;
            Pretstava* p2=readPretstava();
            cout<<p2->cena()<<endl;
        }break;

        case 3:
            //Testiranje na operator ==
        {
            cout<<"======TEST CASE 3======="<<endl;
            Delo f1=readDelo();
            Delo f2=readDelo();
            Delo f3=readDelo();

            if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
            if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;

        }break;

        case 4:
            //testiranje na funkcijata prihod
        {
            cout<<"======TEST CASE 4======="<<endl;
            int n;
            cin>>n;
            Pretstava **pole=new Pretstava*[n];
            for (int i=0;i<n;i++){
                pole[i]=readPretstava();

            }
            cout<<prihod(pole,n);
        }break;

        case 5:
            //testiranje na prihod so izmena na cena za 3d proekcii
        {
            cout<<"======TEST CASE 5======="<<endl;
            int cenaBalet;
            cin>>cenaBalet;
            Balet::setCenaBalet(cenaBalet);
            int n;
            cin>>n;
            Pretstava **pole=new Pretstava*[n];
            for (int i=0;i<n;i++){
                pole[i]=readPretstava();
            }
            cout<<prihod(pole,n);
        }break;

        case 6:
            //testiranje na brojPretstaviNaDelo
        {
            cout<<"======TEST CASE 6======="<<endl;
            int n;
            cin>>n;
            Pretstava **pole=new Pretstava*[n];
            for (int i=0;i<n;i++){
                pole[i]=readPretstava();
            }

            Delo f=readDelo();
            cout<<brojPretstaviNaDelo(pole,n,f);
        }break;

    };


    return 0;
}
