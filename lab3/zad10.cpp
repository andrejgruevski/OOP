//
// Created by Huhe on 3/28/2025.
//
//Да се дефинира класа Film во која ќе се чуваат информации за:
//
//name(низа од максимум 100 карактери) -име на филмот
//
//rating (децимален број) - рејтинг на филмот
//
//revenue(децимален број) - колку заработил филмот во милиони долари
//
//Сите променливи внатре во класата треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:
//
//конструктор (без и со параметри)
//
//деструктор
//
//        set методи
//
//        get методи
//
//        Да се дефинираат следните методи во класата:
//
//display() која што ќе ги печати информациите за сметката во следниот формат:
//
//Name of film: …
//
//Rating: …
//
//Revenue: …
//
//Надвор од класата:
//
//printMostPopularFilm(Film *films, int n) која што ќе го најде филмот со најголема заработувачка,
//
//ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА.
#include <iostream>
#include <cstring>
using namespace std;

class Film{
    char name[50];
    float rating;
    float revenue;
public:
    Film(){}
    Film(char *name,float rating, float revenue){
        strcpy(this->name,name);
        this->rating=rating;
        this->revenue=revenue;
    }
    ~Film(){}
    void setName(char *name){
        strcpy(this->name,name);
    }
    void setRating(float rating){
        this->rating=rating;
    }
    void setRevenue(float rev){
        this->revenue=rev;
    }
    float getRevenue(){
        return this->revenue;
    }
    float getRating(){
        return this->rating;
    }
    char *getName(){
        return this->name;
    }
    void display(){
        cout<<"Name of film: "<<this->name<<endl;
        cout<<"Rating: "<<this->rating<<endl;
        cout<<"Revenue: "<< this->revenue<<endl;
    }
};
void printMostPopularFilm(Film *films, int n){
    float max=0;
    Film najpopularen;
    for (int i = 0; i <n ; ++i) {
        if(films[i].getRevenue()>max){
            max=films[i].getRevenue();
            najpopularen=films[i];
        }
    }
    najpopularen.display();
}
int main() {
    int n;
    cin >> n;
    Film films[100];

    char name[100];
    double rating;
    double revenue;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin >> rating;
        cin >> revenue;

        // testing constructor with arguments
        films[i] = Film(name, rating, revenue);

    }


    // testing set methods and display for last element
    cin>>name;
    cin >> rating;
    cin >> revenue;
    films[n-1].setName(name);
    films[n-1].setRating(rating);
    films[n-1].setRevenue(revenue);

    cout<<"-->Testing set methods and display()"<<endl;
    films[n-1].display();
    cout<<endl;

    cout<<"-->Testing printMostPopularFilm()"<<endl;
    printMostPopularFilm(films , n);
    return 0;
};