#include "GameUser.h"
GameUser::GameUser(std::string name, int points, int total, std::string difficulty, bool base) : 
    name(name), points(points), total(total), difficulty(difficulty), fromBase(base) {}
std::string GameUser::getName() 
{
    return this->name;
}
int GameUser::getPoints() 
{
    return this->points;
}
std::string GameUser::getDifficulty() 
{
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
void GameUser::setDifficulty(std::string difficulty) {
    this->difficulty = difficulty;
}
bool GameUser::getFromBase() {
    return this->fromBase;
}
void GameUser::setFromBase(bool base) {
    this->fromBase = base;
}
int GameUser::getTotalPoints() {
    return this->total + this->points;
}
int GameUser::getTotal() {
    return this->total;
}
void GameUser::setTotal(int total) {
    this->total = total;
}
