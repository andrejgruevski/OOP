//
// Created by Huhe on 3/9/2025.
//
#include "iostream"
using namespace std;

struct Player{
    char name[50];
    int number;
    int klaeniGolovi;
};
struct Club{
    char team[50];
    Player players[11];
    int goals = 0;

    void read(){
        cin >>team;
        for (int i = 0; i < 11; ++i) {
            cin>>players[i].name>> players[i].number>> players[i].klaeniGolovi;
            goals+=players[i].klaeniGolovi;
        }
    }
};

void BestClub(Club *clubs, int n){
    int indexMax=0;
    int max=0;

    for (int i = 0; i < n; ++i) {
        if (clubs[i].goals > max){
            max = clubs[i].goals;
            indexMax = i;
        }
    }
    cout<<"Najdobar tim e: "<<clubs[indexMax].team<<endl;
}
int main(){
    int n;
    cin>>n;
    Club clubs[n];
    for (int i = 0; i < n; ++i) {
        clubs[i].read();
    }
    BestClub(clubs,n);
    return 0;
}