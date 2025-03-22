//
// Created by Huhe on 3/9/2025.
//
#include "iostream"
using namespace std;
 struct Transaction{
     int id;
     int sum;
     int comission;
     bool debitCard;
 };

 void results(Transaction *tt, int n){
     bool flag = false;
     for (int i = 0; i < n; ++i) {
         int sum = 0;

         if (tt[i].debitCard == 1){
             flag = true;
             sum = tt[i].sum + tt[i].comission;
             cout <<tt[i].id << " " << sum << endl;
         }
     }

     if (!flag){
         cout<< "No credit card transaction"<<endl;
     }
 }
int main(){
     Transaction tt[100];
     int n;
     cin >> n;

    for (int i = 0; i < n; ++i) {
        cin>>tt[i].id >> tt[i].sum >> tt[i].comission >> tt[i].debitCard;
    }

    results(tt,n);

    return 0;
}