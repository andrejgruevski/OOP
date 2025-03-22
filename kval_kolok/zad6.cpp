//
// Created by Huhe on 3/13/2025.
//
#include <iostream>

using namespace std;
class Letter{
private:
    char c;
public:
    void set(char c) {
        Letter::c = c;
    }

    explicit Letter(char c='a') : c(c) {
        this->c=c;
    }
    void lowerLetter(){
        if (isalpha(c)){
            c= tolower(c);
        }else{
            cout<<"Character is not a letter"<<endl;
        }
    }
    void print(){
        cout<<c<<endl;
    }

};

int main() {
    Letter obj;
    int n;
    cin >> n;
    int cmd;
    char k;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        switch (cmd) {
            case 1: {
                cin >> k;
                obj.set(k);
                obj.print();
                break;
            }
            case 2: {
                obj.lowerLetter();
                obj.print();
                break;
            }
            case 3: {
                cin >> k;
                Letter obj2;
                obj2.set(k);
                obj2.lowerLetter();
                obj2.print();
                break;
            }
            default: {
                obj.print();
                break;
            }
        }
    }
}