#ifndef GAMEUSER_H
#define GAMEUSER_H

#include <string>

class GameUser {
private:
    std::string name;
    int points;
    std::string difficulty;
public:
    GameUser(std::string name, int points, std::string difficulty);

    std::string getName();
    int getPoints();
    std::string getDifficulty();

    void addPoints(int points);
    void removePoints(int points);
    void setPoints(int points);
};

#endif
