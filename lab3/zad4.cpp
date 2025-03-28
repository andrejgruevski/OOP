//
// Created by Huhe on 3/28/2025.
//
//Во оваа задача е потребно да уредите даден дом со маси. Креирајте класа Masa со следниве атрибути:
//
//должина (целобројна вредност)
//ширина (целобројна вредност)
//конструктор со и без параметри и метода pecati().
//
//Креирајте класа Soba која содржи:
//
//маса (објект од класата Маса)
//должина на собата (целобројна вредност)
//ширина на собата (целобројна вредност)
//конструктор со и без параметри и метода pecati() во која се повикува и pecati() за објектот Masa.
//
//Креирајте класа Kukja со атрибути:
//
//соба (објект од класата Soba)
//адреса (низа од 50 знаци), и соодветни методи.
//конструктор со и без параметри, деструктор и метода pecati() во која се повикува и pecati() за објектот Soba.
#include "iostream"
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i int masaSirina,masaDolzina;
        cin>>masaSirina;
    cin>>masaDolzina;
    Masa m(masaSirina,masaDolzina);
    int sobaSirina,sobaDolzina;
    cin>>sobaSirina;
    cin>>sobaDolzina;
    Soba s(sobaSirina,sobaDolzina,m);
    char adresa[30];
    cin>>adresa;
    Kukja k(s,adresa);
    k.pecati();
}

return 0;
}