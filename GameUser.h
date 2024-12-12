#ifndef GAMEUSER_H
#define GAMEUSER_H

#include <string>

class GameUser {
private:
    std::string name;
    int points;
    int total;
    std::string difficulty;
    bool fromBase;
public:
    GameUser(std::string name, int points, int total, std::string difficulty, bool base);

    std::string getName();
    int getPoints();
    std::string getDifficulty();
    bool getFromBase();

    int getTotalPoints();
    int getTotal();

    void addPoints(int points);
    void removePoints(int points);
    void setPoints(int points);
    void setDifficulty(std::string difficulty);
    void setFromBase(bool base);
    void setTotal(int points);
};

#endif
