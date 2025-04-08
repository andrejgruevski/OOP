#include <iostream>
#include <cstring>
using namespace std;

class Scholarship;
void studentsWithScholarship(Scholarship &scholarship, int num_students);

class Student {
private:
    char name[100];
    char surname[100];
    char faculty[100];
    float avgGrade;
    static int totalStudents;
    static int finkiStudents;
    friend class Scholarship;
    friend void studentsWithScholarship(Scholarship &scholarship, int num_students);

public:
    Student() {}

    Student(char *name, char *surname, char *faculty, float avgGrade) {
        strncpy(this->name, name, 99);
        this->name[99] = '\0';
        strncpy(this->surname, surname, 99);
        this->surname[99] = '\0';
        strncpy(this->faculty, faculty, 99);
        this->faculty[99] = '\0';
        this->avgGrade = avgGrade;
    }

    void print() const {
        cout << name << " " << surname << " " << faculty << " " << avgGrade << endl;
    }

    bool isFinki() const {
        return strcmp(faculty, "FINKI") == 0 && avgGrade >= 9;
    }

    float getAvgGrade() const {
        return avgGrade;
    }

    static int getTotalStudents() {
        return totalStudents;
    }

    static int getFinkiStudents() {
        return finkiStudents;
    }

    static void incrementTotal() {
        totalStudents++;
    }

    static void incrementFinki() {
        finkiStudents++;
    }
};

int Student::totalStudents = 0;
int Student::finkiStudents = 0;

class Scholarship {
private:
    char name[100];
    Student applicants[100];
    int count;
    static float sumFinkiGrades;

public:
    Scholarship() {
        name[0] = '\0';
        count = 0;
    }

    Scholarship(char *name) {
        strncpy(this->name, name, 99);
        this->name[99] = '\0';
        count = 0;
    }

    void addStudent(Student &s) {
        if (count < 100) {
            applicants[count++] = s;
            Student::incrementTotal();
            if (s.isFinki()) {
                Student::incrementFinki();
                sumFinkiGrades += s.getAvgGrade();
            }
        }
    }

    void print() const {
        cout << "Scholarship name: " << name << ", total applicants: " << Student::getTotalStudents() << endl;
    }

    Student* getApplicants() {
        return applicants;
    }

    int getCount() const {
        return count;
    }

    static float getSumFinkiGrades() {
        return sumFinkiGrades;
    }
};

float Scholarship::sumFinkiGrades = 0;

void studentsWithScholarship(Scholarship &sch, int num_students) {
    Student *arr = sch.getApplicants();

    // Sort students by avgGrade (descending)
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (arr[j].getAvgGrade() > arr[i].getAvgGrade()) {
                swap(arr[i], arr[j]);
            }
        }
    }

    cout << "FINKI students with a scholarship" << endl;
    int shown = 0;
    for (int i = 0; i < num_students && shown < 3; i++) {
        if (arr[i].isFinki()) {
            arr[i].print();
            shown++;
        }
    }

    if (Student::getFinkiStudents() > 0) {
        float percent = (Student::getFinkiStudents() * 100.0) / Student::getTotalStudents();
        float avg = Scholarship::getSumFinkiGrades() / Student::getFinkiStudents();
        cout << "Scholarship data shows that " << percent
             << "% of applicants are from FINKI, with an average grade of " << avg << endl;
    }
}

// DO NOT CHANGE THE MAIN FUNCTION!
int main() {
    char name[50], surname[50], faculty[50], scholarship_name[50];
    float average_grade;
    int n, case_;
    cin >> case_;
    if (case_ == 0) {
        cout << "--Testing finkiStudent method--" << endl;
        Student s("Ana", "Denkova", "BAS", 9.89);
        cout << s.isFinki();
    } else if (case_ == 1) {
        cout << "--Testing addStudent and print method--" << endl;
        Scholarship sc("ITCompany");
        Student s("Ana", "Denkova", "BAS", 9.89);
        sc.addStudent(s);
        sc.print();
    } else if (case_ == 2) {
        cin >> scholarship_name;
        Scholarship sc(scholarship_name);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> name >> surname >> faculty >> average_grade;
            Student s(name, surname, faculty, average_grade);
            sc.addStudent(s);
        }
        sc.print();
        studentsWithScholarship(sc, sc.getCount());
    }
    return 0;
}
