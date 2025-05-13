#include <iostream>
#include <cstring>
using namespace std;

class Game {
private:
    char name[50];
public:
    Game(const char *name = "") {
        strncpy(this->name, name, 49);
        this->name[49] = '\0';
    }

    bool operator==(const Game &g) const {
        return strcmp(name, g.name) == 0;
    }

    const char* getName() const {
        return name;
    }
};

class Gamer {
protected:
    char *username;
    Game games[50];
    int numGames;
    int hoursPerWeek;

public:
    Gamer(const char *username = "", Game *games = nullptr, int numGames = 0, int hoursPerWeek = 0) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
        this->numGames = numGames;
        for (int i = 0; i < numGames; ++i) {
            this->games[i] = games[i];
        }
        this->hoursPerWeek = hoursPerWeek;
    }

    Gamer(const Gamer &g) {
        username = new char[strlen(g.username) + 1];
        strcpy(username, g.username);
        numGames = g.numGames;
        for (int i = 0; i < numGames; ++i) {
            games[i] = g.games[i];
        }
        hoursPerWeek = g.hoursPerWeek;
    }

    Gamer& operator=(const Gamer &g) {
        if (this != &g) {
            delete[] username;
            username = new char[strlen(g.username) + 1];
            strcpy(username, g.username);
            numGames = g.numGames;
            for (int i = 0; i < numGames; ++i) {
                games[i] = g.games[i];
            }
            hoursPerWeek = g.hoursPerWeek;
        }
        return *this;
    }

    virtual ~Gamer() {
        delete[] username;
    }

    bool playsGame(const Game &game) const {
        for (int i = 0; i < numGames; ++i) {
            if (games[i] == game) return true;
        }
        return false;
    }

    int getHoursPerWeek() const {
        return hoursPerWeek;
    }

    virtual const char* calculateSkillLevel() const = 0;
    virtual void printInfo() const = 0;
};

class PCGamer : public Gamer {
private:
    int streamHours;
public:
    PCGamer(const char *username, Game *games, int numGames, int hoursPerWeek, int streamHours)
            : Gamer(username, games, numGames, hoursPerWeek) {
        this->streamHours = streamHours;
    }

    PCGamer(const PCGamer &pg) : Gamer(pg) {
        this->streamHours = pg.streamHours;
    }

    PCGamer& operator=(const PCGamer &pg) {
        if (this != &pg) {
            Gamer::operator=(pg);
            streamHours = pg.streamHours;
        }
        return *this;
    }

    ~PCGamer() override = default;

    const char* calculateSkillLevel() const override {
        if (hoursPerWeek > 30 && streamHours > 20)
            return "Pro PCGamer";
        return "Casual PCGamer";
    }

    void printInfo() const override {
        cout << "PCGamer : " << username
             << ", Hours Per Week: " << hoursPerWeek << "h"
             << ", Skill Level: " << calculateSkillLevel() << endl;
    }
};

class ConsoleGamer : public Gamer {
private:
    bool isProPlayer;
public:
    ConsoleGamer(const char *username, Game *games, int numGames, int hoursPerWeek, bool isProPlayer)
            : Gamer(username, games, numGames, hoursPerWeek) {
        this->isProPlayer = isProPlayer;
    }

    ConsoleGamer(const ConsoleGamer &cg) : Gamer(cg) {
        this->isProPlayer = cg.isProPlayer;
    }

    ConsoleGamer& operator=(const ConsoleGamer &cg) {
        if (this != &cg) {
            Gamer::operator=(cg);
            isProPlayer = cg.isProPlayer;
        }
        return *this;
    }

    ~ConsoleGamer() override = default;

    const char* calculateSkillLevel() const override {
        return isProPlayer ? "Pro ConsoleGamer" : "Casual ConsoleGamer";
    }

    void printInfo() const override {
        cout << "ConsoleGamer: " << username
             << ", Hours Per Week: " << hoursPerWeek << "h"
             << ", Skill Level: " << calculateSkillLevel() << endl;
    }
};

void printGamersThatPlayGame(Gamer *gamers[], int n, const Game &game) {
    int count = 0, totalHours = 0;
    for (int i = 0; i < n; ++i) {
        if (gamers[i]->playsGame(game)) {
            totalHours += gamers[i]->getHoursPerWeek();
            count++;
        }
    }

    if (count == 0) return;

    double avgHours = totalHours / (double)count;
    for (int i = 0; i < n; ++i) {
        if (gamers[i]->playsGame(game) && gamers[i]->getHoursPerWeek() > avgHours) {
            gamers[i]->printInfo();
        }
    }
}


int main() {
    int n;
    cin >> n;
    cin.ignore();

    Gamer* gamers[n];

    for (int i = 0; i < n; ++i) {
        char username[30];
        char gameName[50];
        int numGames, hoursPerWeek, streamHours, isProPlayer;

        cin.getline(username, 30);
        cin >> numGames;
        cin.ignore();

        Game games[50];
        for (int j = 0; j < numGames; ++j) {
            cin.getline(gameName, 50);
            games[j] = Game(gameName);
        }

        cin >> hoursPerWeek;
        cin.ignore();

        if (i % 2 == 0) {
            cin >> streamHours;
            cin.ignore();
            gamers[i] = new PCGamer(username, games, numGames, hoursPerWeek, streamHours);
        } else {
            cin >> isProPlayer;
            cin.ignore();
            gamers[i] = new ConsoleGamer(username, games, numGames, hoursPerWeek, isProPlayer);
        }
    }

    char gameQuery[50];
    cin.getline(gameQuery, 50);
    printGamersThatPlayGame(gamers, n, Game(gameQuery));

    for (int i = 0; i < n; ++i) {
        delete gamers[i];
    }

    return 0;
}
