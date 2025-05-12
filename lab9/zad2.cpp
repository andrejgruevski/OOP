//
// Created by Huhe on 5/12/2025.
//
//Да се имплементира класа Athlete за која се чува:
//name (низа од карактери)
//age (int)
//Во класата да се имплементира виртуелна функција void displayInfo() која на екран печати информации за дадениот атлетичар.
//
//Потребно е да се имплементираат класите Runner и Jumper кои што ќе наследуваат од класата Athlete.
//
//За класата Runner дополнително се чуваат:
//
//speed - брзина на играчот(double)
//Функцијата displayInfo() ја вклучува и брзината.
//
//За класата Jumper дополнително се чуваат:
//
//height- висина на скокачот (double)
//Функцијата displayInfo() ја вклучува и висината.
//
//
//Потребно е да се имплементира класата AllRoundAthlete која што ќе наследува од класите Runner и Jumper.
//
//За класата AllRoundAthlete дополнително се чува:
//
//stamina - стамина на AllRound играчот(int)
//
//Функцијата displayInfo() печати вклучувајќи го и нивото на стамина.
//
//Да се направи глобална функцијаAthlete* findAthleteWithMaxValue(Athlete** athletes, int n) - најголема вредност за тркачите се одредува според брзина, додека кај скокачите според висина, треба да се најде играчот кој ќе има најголема вредност и да се врати покажувач кон него.
#include "iostream"
using namespace std;

int main() {
    char name[50];
    int age;
    double speed;
    double height;
    int n;
    int choice;

    cin>>choice;
    if(choice==1)
    {
        cin>>name;
        cin>>age;
        AllRoundAthlete allRoundAthlete(name, age, 13.6, 1.80, 6);
        allRoundAthlete.displayInfo();
    }
    else {

        cin >> n;

        Athlete **athletes = new Athlete *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> name >> age >> speed;

                athletes[i] = new Runner(name, age, speed);
            } else {
                cin >> name >> age >> height;

                athletes[i] = new Jumper(name, age, height);
            }

        }

        findAthleteWithMaxValue(athletes, n)->displayInfo();

    }
}

