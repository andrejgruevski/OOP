//
// Created by Huhe on 4/6/2025.
//
//Дадена е класа Course во која се чува code и кредити на курс, соодветен конструктор и метода за печатење.
//
//Да се дефинира класа OnlineCourse која наследува од класата Course и која вклучува целобројна променлива за бонус кредити. Бројот на бонус кредити мора да е вредност поголема од 0 и помала од 3, во спротивно бонусот поставете го на 1.
//
//За класата OnlineCourse да се дефинира
//
//соодветен конструктор
//метод int calculateMaxCourseCredits() со којшто се пресметува бројот на максимални кредити од курсот (кредити на курсот + бонус кредити)
//метода за печатење void display(), којшто го печати кодот на курсот, бројот на кредити и бројот на бонус кредити
#include <iostream>

using namespace std;

class Course {
protected:
    string code;
    int credits;
public:
    Course(string code = "CS101", int credits = 6) : code(code), credits(credits) {}

    void display() {
        cout << code << " " << credits << " ";
    }

    ~Course() {}
};
class OnlineCourse: public Course{
private:int bonus;
public:
    explicit OnlineCourse(string code = "CS101", int credits = 6,int bonus=0): Course(code,credits)  {
        if (bonus > 0 && bonus < 3){
            this->bonus=bonus;
        }else{
            this->bonus=1;
        }
    }
    int calculateMaxCourseCredits(){
        return credits + bonus;
    }
    void display(){
        cout<<code<<" "<<credits<<" "<<bonus<<endl;
    }
};



OnlineCourse *createOnlineCourses(int n) {
    OnlineCourse *onlineCourses = new OnlineCourse[n];
    string code;
    int credits, bonusCredits;
    for (int i = 0; i < n; i++) {
        cin >> code >> credits >> bonusCredits;
        onlineCourses[i] = OnlineCourse(code, credits, bonusCredits);
    }
    return onlineCourses;
}

int main() {
    int testCase;
    cin >> testCase;

    switch (testCase) {
        case 1 : {
            OnlineCourse onlineCourse;
            onlineCourse.display();
            break;
        }
        case 2 : {
            OnlineCourse onlineCourse("CS101", 6, 1);
            onlineCourse.display();
            OnlineCourse onlineCourse1("CS102", 4,2);
            onlineCourse1.display();
            break;
        }
        case 3 : {
            OnlineCourse onlineCourse("CS101", 5, 5);
            onlineCourse.display();
            OnlineCourse onlineCourse1("CS102", 6, 0);
            onlineCourse1.display();
            break;
        }
        case 4: {
            OnlineCourse onlineCourse("CS101", 7, 2);
            cout << onlineCourse.calculateMaxCourseCredits();
            break;
        }
        case 5: {
            int n;
            cin >> n;
            OnlineCourse *onlineCourses = createOnlineCourses(n);
            for (int i = 0; i < n; i++) {
                onlineCourses[i].display();
            }
            delete [] onlineCourses;
            break;
        }
        default: {
            int n;
            cin >> n;

            OnlineCourse *onlineCourses = createOnlineCourses(n);
            for (int i = 0; i < n; i++) {
                onlineCourses[i].display();
            }
            for (int i = 0; i < n; i++) {
                cout << onlineCourses[i].calculateMaxCourseCredits()<<endl;
            }
            delete [] onlineCourses;
            break;
        }
    }
}

