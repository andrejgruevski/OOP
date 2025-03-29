//
// Created by Huhe on 3/28/2025.
//
//Да се дефинира класа InvoiceItem во која што ќе се чуваат податоци за една ставка во фактура:
//
//име на ставка (низа од максимум 100 карактери)
//цена на ставка (цел број)
//За класата да се дефинира copy конструктор, default конструктор и конструктор со аргументи.
//Доколку е потребно да се креира и get методи.
//
//Потоа да се креира класа Invoice во која што се чуваат следните податоци:
//
//број на фактура (низа од максимум 10 карактери)
//број на ставки во фактурата (цел број)
//низа од ставки во фактурата (низа од објекти од InvoiceItem класата, max 100)
//Да се креира конструктор со аргументи за класата.
//Доколку е потребно да се креира и get методи.
//
//Во класата да се креира метода totalPrice што ќе го пресметува вкупниот износ на фактурата. Вкупниот износ на фактурата се пресметува како збир од цените на сите ставки во нејзе.
//
//ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА.
#include <iostream>
#include <cstring>
using namespace std;
class InvoiceItem {
private:
    char stavka[100];
    int cena;
public:
    InvoiceItem (char stavka[]=" ", int cena=0) {
        strcpy(this->stavka, stavka);
        this->cena=cena;
    }
    InvoiceItem (InvoiceItem &i) {
        strcpy(this->stavka, i.stavka);
        this->cena=i.cena;
    }
    ~InvoiceItem() {};
    int getCena() {
        return cena;
    }
};
class Invoice {
private:
    char br_faktura[10];
    int br_stavki;
    InvoiceItem items[100];
public:
    Invoice(char br_faktura[], int br_stavki, InvoiceItem items[100]) {
        strcpy(this->br_faktura, br_faktura);
        this->br_stavki = br_stavki;

        for (int i = 0; i < br_stavki; i++) {
            this->items[i] = items[i];
        }
    }
    Invoice(Invoice &ii) {
        strcpy(this->br_faktura, ii.br_faktura);
        this->br_stavki = ii.br_stavki;

        for (int i = 0; i < br_stavki; i++) {
            this->items[i] = ii.items[i];
        }
    }
    int totalPrice() {
        int vkupno=0;
        for (int i=0; i<br_stavki; i++) {
            vkupno+=items[i].getCena();
        } return vkupno;
    }
};
