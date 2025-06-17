#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;
class Song{
private:
    string naslov,avtor,izveduvach;
    int vreme;

public:
    Song(string naslov = "", string avtor ="", string izveduvach = "", int vreme = 0){
        this->naslov=naslov;
        this->avtor=avtor;
        this->izveduvach=izveduvach;
        this->vreme=vreme;
    }
    friend istream &operator >>(istream &in, Song &s){
        in.ignore();
        getline(in,s.naslov);
        getline(in,s.avtor);
        getline(in,s.izveduvach);
        in>>s.vreme;

        return in;
    }
//    Song title: Usni na usni, Author: Grigor Koprov, Interpreted by: Toshe Proeski, 215 sek.
    void print(ofstream& out){
        out<<"Song title: "<<naslov<<", Author: "<<avtor<<", Interpreted by: "<<izveduvach<<", "<<vreme<<" sek."<<endl;
    }
    bool operator ==(const Song &s){
        return (naslov == s.naslov) &&(avtor == s.avtor)&& (izveduvach == s.izveduvach)&&(vreme == s.vreme);
    }
    string avt(){
        return avtor;
    }

};
class Festival{
private:
    string imeFestival;
    string grad;
    string datum;
    Song *pesni;
    int n;
public:
    Festival(){
        pesni = new Song[0];
        n =0;
    }
//    Festival(string imeFestival, string grad, string datum, Song *pesni, int n){
//        this->imeFestival=imeFestival;
//        this->grad=grad;
//        this->datum=datum;
//        this->n=n;
//        this->pesni = new Song[n];
//        for (int i = 0; i < n; ++i) {
//            this->pesni[i] = pesni[i];
//        }
//    }
    Festival(const Festival &f){
        this->imeFestival = f.imeFestival;
        this->grad= f.grad;
        this->datum=f.datum;
        this->n =f.n;
        this->pesni = new Song[f.n];
        for (int i = 0; i < f.n; ++i) {
            this->pesni[i] = f.pesni[i];
        }
    }
    Festival &operator = (const Festival &f){
        if (this!=&f){
            delete[]pesni;
            this->imeFestival = f.imeFestival;
            this->grad= f.grad;
            this->datum=f.datum;
            this->n =f.n;
            this->pesni = new Song[f.n];
            for (int i = 0; i < f.n; ++i) {
                this->pesni[i] = f.pesni[i];
            }
        }
        return *this;
    }
    Festival &operator -=( Song &r){
        if (n == 0){
            cout<<"Trying to delete from an empty list!"<<endl;
        }
        int newCounter = 0;
        for (int i = 0; i < n; ++i) {
            if (pesni[i].operator==(r)){
                newCounter++;
            }
        }
        Song *tmp = new Song[n - newCounter];
        int j =0;
        for (int i = 0; i < n; ++i) {
            if (!(pesni[i]==r)){
                tmp[j++] = pesni[i];
            }
        }
        delete[]pesni;
        pesni = tmp;
        n = j;
        return *this;
    }
    friend ifstream &operator>>(ifstream &in, Festival &f){
        getline(in,f.imeFestival);
        getline(in,f.grad);
        getline(in,f.datum);
        in>>f.n;
        f.pesni = new Song[f.n];
        for (int i = 0; i < f.n; ++i) {
            in>>f.pesni[i];
        }
        return in;
    }
    void print(ofstream& out){
        out<<"Festival: "<<imeFestival<<" - "<<grad<<", "<<datum<<endl;
        for (int i = 0; i < n; ++i) {
            pesni[i].print(out);
        }
    }

    Festival notFromAuthor(string author){
        Festival obj= *this;
        if (n == 0){
            cout<<"Trying to delete from an empty list!"<<endl;
        }
        for (int i = 0; i < n; ++i) {
            if (pesni[i].avt() == author){
                obj-=pesni[i];
            }
        }
        return obj;
    }
    ~Festival(){
        delete[]pesni;
    }
};

void wtf() {
    ofstream fout("vlezna.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----"){
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
    //TODO your code here
    //TODO Read the data from the file and store them in `festival`
    ifstream in("vlezna.txt");
    ofstream out("izlezna1.txt");
    ofstream out2("izlezna2.txt");

    in>>festival;
    in.close();
    festival.print(out);
    out.close();



    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    string author;
    getline(cin, author);
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    //TODO Save the results in the files izlezna1.txt and izlezna2.txt after this line
    Festival f = festival.notFromAuthor(author);
    f.print(out2);
    out2.close();


    //DO NOT MODIFY THE CODE BELLOW

    cout << "All the data for the festival:" << endl;
    rff("izlezna1.txt");
    cout << "Songs NOT from the author " << author << ": " << endl;
    rff("izlezna2.txt");


    return 0;
}