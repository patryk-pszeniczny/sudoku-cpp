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

    std::string getName() const;
    int getPoints() const;
    std::string getDifficulty() const;

    void addPoints(int points);
    void removePoints(int points);
    void setPoints(int points);
};

#endif
