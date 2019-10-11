#ifndef PlayersInfo_H
#define PlayersInfo_H
#include <string>
#include "player.h"

//The key press interpreter
class PlayersInfo
{

    public:
    	//Initializes variables
    	PlayersInfo(std::string &playerName,
                    unsigned int score) : player(playerName, score) { }

    	std::string GetPlayerName() const { return player.GetName(); }
    	void SetPlayerName(std::string& playerName) 
    	{
            player.SetName(playerName);
    	}

        void IncrementPlayerScore() { player.IncrementScore(); }

        unsigned int GetPlayerScore() const { return player.GetScore(); }

    private:
        Player player;
};

#endif