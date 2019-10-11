#ifndef PlayersInfo_H
#define PlayersInfo_H
#include <string>
#include "player.h"

const std::string kDataFileName{"datalogger.txt"};

class PlayersInfo
{

    public:
    	//Initializes variables
    	PlayersInfo(std::string &playerName,
                    unsigned int score = 0) : player(playerName, score) {  }

    	std::string GetPlayerName() const { return player.GetName(); }

        void IncrementPlayerScore() { player.IncrementScore(); }

        unsigned int GetPlayerScore() const { return player.GetScore(); }

        void GetHighScoreAndName(int &highScore, std::string &playerName) const;

    private:
        Player player;
};

#endif