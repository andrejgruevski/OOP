//
// Created by Huhe on 5/8/2025.
//
//Да се дефинира класа Theater за која ќе се чуваат:
//
//динамички алоцирана низа од карактери за името на театарот
//        динамички алоцирана низа од карактери за градот во кој се наоѓа театарот
//капацитет (int)
//низа од 10 оцени за театарот (double)
//основна цена на карта (double)
//процент на попуст (број од 0-100) (int)
//За потребите на класата да се дефинираат:
//
//default конструктор и конструктор со аргументи
//        copy constructor и оператор =
//деструктор
//метод avgRating() кој ја враќа просечната оцена:
//
//
//метода finalTicketPrice():
//
//За просечна оцена понизка од 2.0 основната цена се намалува за 20%
//За просечна оцена понизка од 4.0 основната цена не се менува
//        За просечна оцена повисока и еднаква на 4.0 основната цена се зголемува за 20%
//Потоа се пресметува процентот за попуст
//
//метод print() кој го печати тркачот во следниот формат:
//
//Тheater name - име на театарот
//
//        City- градот во кој се наоѓа театарот
//
//Rating: просечната оцена
//
//Ticket price: конечната цена на билет
//
//Од претходната класа Theater да се изведе класата MovieTheater за која дополнително ќе се чуваат и:
//
//ширина на екран (double)
//висина на екран (double)
//дали е 3Д (bool)
//За потребите на класата да се дефинираат:
//
//default конструктор
//        конструктор кој ги прима сите аргументи (од основната класа и дополнителните oд изведената класа) (погледни main)
//copy constructor и оператор =
//        деструктор
//Да се препокријат методите:
//finalTicketPrice():
//
//        Доколку киното е 3Д, основната цена на билет се зголемува 30%
//Ако не е, останува иста
//Потоа се пресметува процентот за попуст
//print() кој покрај основните информации печати и:
//Screen Width: ширина на екранот
//        Screen Height: висина на екранор
//        Is 3D: дали е 3Д
//Да се имплементира глобалната функција MostExpensiveTheater() - прима низа од покажувачи од класата Theater (објектите можат да бидат и Theater и MovieTheater и број на елементи). Како резултат се печатат информациите за најскапиот елемент во низата (без разлика дали е Theater или MovieTheater)
#include "iostream"
#include "cstring"
using namespace std;

int main() {
    int n;
    cin >> n;

    char name[100];
    char city[100];
    int capacity;
    double reviews[10];
    double baseTicketPrice;
    int discount;
    double screenWidth, screenHeight;
    bool is3D;

    if (n == 1) {
        cout << "TESTING CLASS THEATER:" << endl;
        cout << "==============================" << endl;
        for (int i = 0; i < 3; ++i) {
            cin >> name >> city >> capacity;
            for (int j = 0; j < 10; ++j)
                cin >> reviews[j];
            cin >> baseTicketPrice >> discount;

            Theater t(name, city, capacity, reviews, baseTicketPrice, discount);
            t.print();
            cout << "------------------------------";
        }
    } else if (n == 2) {
        cout << "TESTING CLASS MOVIE THEATERS:" << endl;
        cout << "==============================" << endl;
        for (int i = 0; i < 3; ++i) {
            cin >> name >> city >> capacity;
            for (int j = 0; j < 10; ++j)
                cin >> reviews[j];
            cin >> baseTicketPrice >> discount >> screenWidth >> screenHeight >> is3D;

            MovieTheater mt(name, city, capacity, reviews, baseTicketPrice, discount, screenWidth, screenHeight, is3D);
            mt.print();
            cout << "------------------------------";
        }
    } else if (n == 3) {
        cout << "TESTING MostExpensiveTheater FUNCTION:" << endl;
        cout << "==============================" << endl;

        Theater *theaters[6];
        int type;
        for (int i = 0; i < 5; ++i) {
            cin >> type;

            if (type == 1) { // Theater
                cin >> name >> city >> capacity;
                for (int j = 0; j < 10; ++j)
                    cin >> reviews[j];
                cin >> baseTicketPrice >> discount;
                theaters[i] = new Theater(name, city, capacity, reviews, baseTicketPrice, discount);
            } else { // MovieTheater
                cin >> name >> city >> capacity;
                for (int j = 0; j < 10; ++j)
                    cin >> reviews[j];
                cin >> baseTicketPrice >> discount;
                cin >> screenWidth >> screenHeight >> is3D;
                theaters[i] = new MovieTheater(name, city, capacity, reviews, baseTicketPrice, discount,
                                               screenWidth, screenHeight, is3D);
            }
        }

        MostExpensiveTheater(5, theaters);

        for (int i = 0; i < 5; ++i) {
            delete theaters[i];
        }
    }
