//
// Created by Huhe on 6/15/2025.
//
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Song {
private:
    string title;
    string fullName;
    string izveduvach;
    int vreme;
public:
    Song(string title = "", string fullName = "", string izveduvach = "", int vreme = 0) {
        this->title = title;
        this->fullName = fullName;
        this->izveduvach = izveduvach;
        this->vreme = vreme;
    }

    friend ifstream &operator>>(ifstream &in, Song &s) {
        getline(in, s.title);
        getline(in, s.fullName);
        getline(in, s.izveduvach);
        in >> s.vreme;
        in.ignore();
        return in;
    }

    void print(ofstream &out) {
        out << "Song title: " << title << ", Author: " << fullName << ", Interpreted by: " << izveduvach << ", "
            << vreme << " sek."<<endl;
    }

    friend class Festival;
};

class Festival {
private:

    string imeFestival;
    string grad;
    string datum;
    Song *pesni;
    int n;
public:
    Festival(string imeFestival = "", string grad = "", Song *pesni = nullptr, int n = 0) {
        this->imeFestival = imeFestival;
        this->grad = grad;
        this->datum = datum;
        this->n = n;
        this->pesni = new Song[n];
        for (int i = 0; i < n; ++i) {
            this->pesni[i] = pesni[i];
        }
    }

    Festival(const Festival &f) {
        this->imeFestival = f.imeFestival;
        this->grad = f.grad;
        this->datum = f.datum;
        this->n = f.n;
        this->pesni = new Song[f.n];
        for (int i = 0; i < f.n; ++i) {
            this->pesni[i] = f.pesni[i];
        }
    }

    Festival &operator=(const Festival &f) {
        if (this != &f) {
            delete[]pesni;
            this->imeFestival = f.imeFestival;
            this->grad = f.grad;
            this->datum = f.datum;
            this->n = f.n;
            this->pesni = new Song[f.n];
            for (int i = 0; i < f.n; ++i) {
                this->pesni[i] = f.pesni[i];
            }
        }
        return *this;
    }

    ~Festival() {
        delete[]pesni;
    }

    Festival &operator-=(const Song &s) {
        if (n == 0) {
            cout << "Trying to delete from an empty list!" << endl;
            return *this;
        }
        for (int i = 0; i < n; ++i) {
            if ((pesni[i].fullName == s.fullName) &&
                (pesni[i].izveduvach == s.izveduvach) &&
                (pesni[i].title == s.title) &&
                (pesni[i].vreme == s.vreme)){
                for (int j = i; j <n-1 ; ++j) {
                    pesni[j] = pesni[j+1];
                }
            }
        }
        n--;
        return *this;
    }
    friend ifstream &operator >> (ifstream &in, Festival &f){
        getline(in,f.imeFestival);
        getline(in,f.grad);
        getline(in,f.datum);
        in>>f.n;
        in.ignore();
        f.pesni = new Song[f.n];
        for (int i = 0; i < f.n; ++i) {
            in>>f.pesni[i];
        }
        return in;
    }

    void print(ofstream &out) {
        out<<"Festival: "<<imeFestival<<" - "<<grad<<", "<<datum<<endl;
        for (int i = 0; i < n; ++i) {
            pesni[i].print(out);
        }
    }
    Festival notFromAuthor(string author){
        Festival f = *this;
        Song p;
        if (n == 0){
            f -= p;
        }else{
            for (int i = 0; i < n; ++i) {
                if (pesni[i].fullName == author){
                    p = pesni[i];
                    f-=pesni[i];
                }
            }
        }
        return f;
    }
};

void wtf() {
    ofstream fout("vlezna.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}


int main() {

    wtf();

    Festival festival;

    ifstream fin("vlezna.txt");
    ofstream fout("izlezna1.txt");
    ofstream fout2("izlezna2.txt");

    fin>>festival;

    fin.close();

    festival.print(fout);
    fout.close();

    string author;
    getline(cin, author);

    festival.notFromAuthor(author).print(fout2);
    fout2.close();


    cout << "All the data for the festival:" << endl;
    rff("izlezna1.txt");
    cout << "Songs NOT from the author " << author << ": " << endl;
    rff("izlezna2.txt");


    return 0;
}