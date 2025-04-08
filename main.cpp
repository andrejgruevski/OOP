#include <iostream>
#include <cstring>

using namespace std;
class Scholarship;
void studentsWithScholarship(Scholarship &scholarship, int num_students);
class Student {
private:
    char name[100];
    char prezime[100];
    char fakultet[100];
    float prosek;
    static int brS;
    static int brSf;
    friend class Scholarship;
    friend void studentsWithScholarship(Scholarship &scholarship, int num_students);
public:
    Student(){}
    Student(char *name, char *prezime, char *fakultet, float prosek) {
        strcpy(this->name,name);
        strcpy(this->prezime,prezime);
        strcpy(this->fakultet,fakultet);
        this->prosek = prosek;
    }
    static float getBrS() {
        return brS;
    }
    void zgolemiBrS() {
        brS++;
    }
    void zgolemiBrSf() {
        brSf++;
    }
    void print() {
        cout<<name<<" "<<prezime<<" "<<fakultet<<" "<<prosek<<endl;
    }
    float getProsek() {
        return prosek;
    }
    bool finkiStudent() {
        if((strcmp(this->fakultet,"FINKI")==0)&& (prosek>=9)) {
            return true;
        }
        return false;
    }
    ~Student(){}
};
class Scholarship {
private:
    char name[100];
    Student s[100];

    static float vkProsek;
    friend void studentsWithScholarship(Scholarship &scholarship, int num_students);
public:
    Scholarship(){}
    Scholarship(char *name) {
        strcpy(this->name,name);
    }
    void addStudent(Student &ss) {
        int index = ss.getBrS();
        s[index] =  ss;
        if(ss.finkiStudent()) {
            ss.zgolemiBrSf();

            vkProsek = vkProsek+ss.getProsek();
        }
        ss.zgolemiBrS();
    }
    Student *getS() {
        return s;
    }

    void print() {
        cout<<"Scholarship name: "<<name<<", total applicants: "<<Student::brS<<endl;
    }
    ~Scholarship(){}

};
void studentsWithScholarship(Scholarship &scholarships, int num_students) {
    for (int i = 0; i < num_students;i++) {
        for (int j = 0; j < num_students-1-i;j++) {
            if(scholarships.getS()[j].getProsek()<scholarships.getS()[j+1].getProsek()) {
                Student temp = scholarships.getS()[j];
                scholarships.getS()[j] = scholarships.getS()[j+1];
                scholarships.getS()[j+1] = temp;
            }
        }
    }
    int br = 0;
    cout<<"FINKI students with a scholarship"<<endl;
    for (int i = 0; i < num_students;i++) {
        if((scholarships.getS()[i].finkiStudent()) && br<3) {
            scholarships.getS()[i].print();
            br++;
        }
    }
    cout<<"Scholarship data shows that "<<(Student::brSf/(Student::brS*1.0))*100<<"% of applicants are from FINKI, with an average grade of "<<Scholarship::vkProsek/(Student::brSf*1.0)<<endl;

}
int Student::brS = 0;
int Student::brSf = 0;
float Scholarship::vkProsek = 0;
int main() {
    char name[50], surname[50], faculty[50], scholarship_name[50];
    float average_grade;
    int n,case_;
    cin>>case_;
    if (case_ == 0)
        //Testing Student constructor
    {
        cout<<"--Testing finkiStudent method--"<<endl;
        Student s("Ana", "Denkova", "BAS", 9.89);
        cout<<s.finkiStudent();
    }
    else if (case_==1){
        //Testing addStudent and print method
        cout<<"--Testing addStudent and print method--"<<endl;
        Scholarship sc("ITCompany");
        Student s("Ana", "Denkova", "BAS", 9.89);
        sc.addStudent(s);
        sc.print();
    }
    else if (case_ == 2){
        cin>>scholarship_name;
        Scholarship sc(scholarship_name);
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>name>>surname>>faculty>>average_grade;
            Student s = Student(name, surname, faculty, average_grade);
            sc.addStudent(s);
        }
        sc.print();
        studentsWithScholarship(sc,n);
    }
    return 0;
}
