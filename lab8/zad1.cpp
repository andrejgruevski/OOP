//
// Created by Huhe on 5/2/2025.
//
#include "iostream"
using namespace std;
class Room{
public:
    virtual void displayRoomInfo() const = 0;
    virtual void displayRoomPrice() const =0;
};
class StandardRoom:public Room{
private:
    bool hasBathroom;
public:
    StandardRoom(bool hasBathroom = false){
        this->hasBathroom=hasBathroom;
    }
    void displayRoomInfo() const override {
        cout<<"This is standard room with a queen-sized bed ";
        if (hasBathroom){
            cout<<" and a bathroom";
        }
        cout<<".";
    }
    void displayRoomPrice() const override {
        cout<<"The price for a standard room is ";
        if (hasBathroom){
            cout<<"100$ per night.";
        }else {
            cout<<"80$ per night.";
        }
    }
};

class DeluxeRoom:public Room{
private:
    bool hasBalcony;
public:
    DeluxeRoom(bool hasBathroom = false){
        this->hasBalcony=hasBathroom;
    }
    void displayRoomInfo() const override {
        cout<<"This is standard room with a king-sized bed, a bathroom, a mini-fridge ";
        if (hasBalcony){
            cout<<" and a balcony";
        }
        cout<<".";
    }
    void displayRoomPrice() const override {
        cout<<"The price for a deluxe room is ";
        if (hasBalcony){
            cout<<"200$ per night.";
        }else {
            cout<<"160$ per night.";
        }
    }
};

int main() {
    Room* rooms[5];

    int testCase;

    cin >> testCase;

    if (testCase == 1) {
        cout << "TEST CASE 1: TESTING STANDARD ROOM CLASS" << endl;

        for (int i = 0; i < 5; i++) {
            rooms[i] = new StandardRoom();
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    } else if (testCase == 2) {
        cout << "TEST CASE 2: TESTING DELUXE ROOM CLASS" << endl;
        for (int i = 0; i < 5; i++) {
            rooms[i] = new DeluxeRoom();
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    } else {
        cout << "TEST CASE 3: TESTING BOTH CLASSES" << endl;
        for (int i = 0; i < 5; i++) {
            if (i % 2) {
                bool hasBalcony;
                cin >> hasBalcony;
                rooms[i] = new DeluxeRoom(hasBalcony);
            }
            else {
                bool hasBathroom;
                cin >> hasBathroom;
                rooms[i] = new StandardRoom(hasBathroom);
            }
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    }

    return 0;
}
