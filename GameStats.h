#pragma once
#include <vector>
#include "GameUser.h"
#include <string>
namespace szablon {
    class GameStats {
    public:
        GameStats();
        GameUser* getGameUser(std::string name);
        GameUser* getHighScoreUser();

        bool openDialogFile();
        void loadUser(std::string value);
        void saveUser(GameUser* gameuser);
        void setGameUser(GameUser* gameuser);

        int getHighScore();
        int getHighScoreSum();
    private:
        GameUser* gameuser;

        int highScore;
        int highScoreSum;
        std::string filePathNative;
        std::vector<GameUser*> vectorGameUsers;
    protected:
        ~GameStats();
    };
}
