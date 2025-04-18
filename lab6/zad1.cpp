//
// Created by Huhe on 4/18/2025.
//
//Како успешен студент на ФИНКИ вие сте повикани да работите на подобрување на IKnow системот. Како дел од системот треба да се додаде нов дел кој ќе биде одговорен за обработување на дисциплински мерки, па како дел од тимот за развивање на софтверот ќе треба да ја имплементирате класата DisciplinaryAction која ќе ги чува следните информации:
//
//Името на студентот (динамички алоцирана низа од карактери)
//Индексот на студентот (int)
//Причината за дисциплинската мерка (динамички алоцирана низа од карактери)
//
//Класата треба да ги има следните методи и конструктори:
//
//Default конструктор
//Copy конструктор
//Конструктор со аргументи
//        Деструктор
//Set и Get методи за индексот
//void print() метод
//        Оператор =
//
//        Print() методот треба да печати според следниот формат:
//Student: [Name]
//Student's index: [Index]
//Reason: [Reason]
//
//При што вредностите во [] треба да се заменат со вредностите во класата!
#include "iostream"
#include "cstring"
using namespace std;
class DisciplinaryAction{
private:
    char *name;
    int index;
    char *reason;
public:
    DisciplinaryAction(){
        name = new char[0];
        reason = new char[0];
    }
    DisciplinaryAction(char *name, int index, char *reason)  {
        this->name= new char[strlen(name)+1];
        strcpy(this->name,name);
        this->index=index;
        this->reason= new char[strlen(reason)+1];
        strcpy(this->reason,reason);
    }
    DisciplinaryAction(const DisciplinaryAction &d){
        this->name= new char[strlen(d.name)+1];
        strcpy(this->name,d.name);
        this->index=d.index;
        this->reason= new char[strlen(d.reason)+1];
        strcpy(this->reason,d.reason);
    }
    ~DisciplinaryAction(){
        delete[]name;
        delete[]reason;
    }

    void setIndex(int index) {
        this->index = index;
    }
    DisciplinaryAction &operator=(const DisciplinaryAction &d){
        if (this != &d){
            delete[]name;
            delete[]reason;
            strcpy(this->name,d.name);
            this->index=d.index;
            strcpy(this->reason,d.reason);

        }
        return *this;
    }

    void print(){
        cout<<"Student: "<<name<<endl;
        cout<<"Students's index: "<<index<<endl;
        cout<<"Reason: "<<reason<<endl;
    }
};
int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for(int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;

        cin >> name >> index >> reason;

        arr[i] = DisciplinaryAction(name, index, reason);
    }

    cout << "-- Testing operator = & print() --\n";
    arr[0].print();

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    arr[0].print();

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    merka.print();

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for(int i = 0; i < n; i++)
        arr[i].print();

    return 0;
}