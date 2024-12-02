#include "GameUser.h"
GameUser::GameUser(std::string name, int points, std::string difficulty) : name(name), points(points), difficulty(difficulty) {}
std::string GameUser::getName() const {
    return this->name;
}
int GameUser::getPoints() const {
    return this->points;
}
std::string GameUser::getDifficulty() const {
    return this->difficulty;
}

void GameUser::addPoints(int points)
{
    this->points += points;
}

void GameUser::removePoints(int points)
{
    this->points -= points;
}

void GameUser::setPoints(int points)
{
    this->points = points;
}
