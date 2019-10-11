#ifndef Player_H
#define Player_H
#include <string>

//The key press interpreter
class Player
{

    public:
    	//Initializes variables
    	Player(std::string &playerName,
               unsigned int score);

    	std::string GetName() const { return _playerName; }
    	void SetName(std::string& playerName) 
    	{
    		if(!playerName.empty())
    			_playerName = playerName;
    	}

        void IncrementScore() { ++_score; }
        
        unsigned int GetScore() const { return _score; }
    
    private:
    	//The storage string
    	std::string _playerName = "";
        unsigned int _score{0};

};

#endif