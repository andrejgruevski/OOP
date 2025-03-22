//
// Created by Huhe on 3/8/2025.
//
#include <iostream>
#include <cstring>
using namespace std;
void test(int k);

// TODO: Define TennisPlayer class
class TennisPlayer{
private:
    char name[20];
    char suraname[20];
    int rank;
    int maatchesPlayed;
    int matchesWon;
public:
    TennisPlayer(){

    }
    double findPercentageWins(){
        return ( (double)matchesWon/maatchesPlayed)*100;
    }

    const char *getName() const {
        return name;
    }

    const char *getSurname() const {
        return suraname;
    }

    int getRank() const {
        return rank;
    }

    void setRank(int rank) {
        TennisPlayer::rank = rank;
    }

    int getMatchesPlayed() const {
        return maatchesPlayed;
    }

    void setMatchesPlayed(int maatchesPlayed) {
        TennisPlayer::maatchesPlayed = maatchesPlayed;
    }

    int getMatchesWon() const {
        return matchesWon;
    }

    void setMatchesWon(int matchesWon) {
        TennisPlayer::matchesWon = matchesWon;
    }
    void setName(const char*namee){
        strcpy(name,namee);
    }
    void setSurname(const char*surnamee){
        strcpy(suraname,surnamee);
    }
};



// TODO: Define input arguments and implement function logic
void printHighestRankedPlayerBelow50PercentWins(TennisPlayer players[], int n) {
    TennisPlayer* bestPlayer = nullptr;

    for (int i = 0; i < n; ++i) {
        if (players[i].findPercentageWins()<50){
            if (bestPlayer == nullptr || players[i].getRank()< bestPlayer->getRank()){
                bestPlayer = &players[i];
            }
        }
    }
    if (bestPlayer){
        cout<<bestPlayer->getName()<<" "<<bestPlayer->getSurname()<<endl;
    }else{
        cout<<"No such tennis player."<<endl;
    }
}


int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 0 || testCase == 1) {
        test(testCase);
        return 0;
    }

    int n;
    cin >> n;

    // TODO: Read input data for all tennis players
    TennisPlayer players[n];
    for (int i = 0; i < n; ++i) {
        char name[20], surname[20];
        int rank, matchesPlayed, matchesWon;
        cin>>name>>surname>>rank>>matchesPlayed>>matchesWon;
        players[i].setName(name);
        players[i].setSurname(surname);
        players[i].setRank(rank);
        players[i].setMatchesPlayed(matchesPlayed);
        players[i].setMatchesWon(matchesWon);
    }



    // TODO: Pass correct input arguments
    printHighestRankedPlayerBelow50PercentWins(players,n);

    return 0;
}


void test(int k) {
    if (k == 0) {
        cout << "Testing default constructor and getters/setters" << endl;
        cout << "---" << endl;
        TennisPlayer player = TennisPlayer();
        player.setName(new char[5] {'J', 'o', 'h', 'n', '\0'});
        player.setSurname(new char[5] {'D', 'o', 'e', '\0'});
        player.setRank(55);
        player.setMatchesPlayed(100);
        player.setMatchesWon(50);
        cout << "Full name: " << player.getName() << " " << player.getSurname() << endl;
        cout << "Rank and won matches out of total: " << player.getRank() << " " << player.getMatchesWon() << "/"
             << player.getMatchesPlayed() << endl;
    }
    else if (k == 1) {
        cout << "Testing findPercentageWins function" << endl;
        cout << "---" << endl;
        TennisPlayer player = TennisPlayer();
        player.setName(new char[5] {'J', 'o', 'h', 'n', '\0'});
        player.setSurname(new char[5] {'D', 'o', 'e', '\0'});
        player.setRank(55);
        player.setMatchesPlayed(100);
        player.setMatchesWon(50);
        if (player.findPercentageWins() != 50) {
            cout << "Test case failed." << endl;
            cout << "Expected: " << 0.5 << "; Got: " << player.findPercentageWins() << endl;
            return;
        }
        player.setMatchesWon(90);
        if (player.findPercentageWins() != 90) {
            cout << "Test case failed." << endl;
            cout << "Expected: " << 0.9 << "; Got: " << player.findPercentageWins() << endl;
            return;
        }
        cout << "Passed." << endl;
    }
}
