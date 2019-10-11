#ifndef PlayersInfo_H
#define PlayersInfo_H
#include <string>

//The key press interpreter
class PlayersInfo
{

    public:
    	//Initializes variables
    	PlayersInfo() : _playerName("") { }

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