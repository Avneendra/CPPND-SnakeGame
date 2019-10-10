#ifndef PlayerInfo_H
#define PlayerInfo_H
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

//The key press interpreter
class PlayerInfo
{

    public:
    	//Initializes variables
    	PlayerInfo() : _playerName("") { }

    	//Does clean up
    	//~PlayerInfo();

    	std::string GetPlayerName() { return _playerName; }
    	void SetPlayerName(std::string& playerName) 
    	{
    		if(!playerName.empty())
    			_playerName = playerName;
    	}
    
    private:
    	//The storage string
    	std::string _playerName;

};

#endif