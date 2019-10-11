#include "playersInfo.h"
#include <fstream>
#include <sstream>
#include <iostream> 

void PlayersInfo::GetHighScoreAndName(int &highScore, std::string &playerName) const
{
	std::string line, name, score;

	std::fstream filestream(kDataFileName);
	if (filestream) 
	{	
		if(filestream.is_open())
		{
			std::getline(filestream, line);
			std::istringstream linestream(line);
			
			linestream >> name >> score;

			if(stoi(score) < GetPlayerScore())
			{
				filestream.close();
				filestream.open(kDataFileName, std::fstream::out | std::fstream::trunc);
				filestream << GetPlayerName() << " " << GetPlayerScore();
				highScore = GetPlayerScore();
				playerName = GetPlayerName();
			}
			else
			{
				highScore = stoi(score);
				playerName = name;
			}

			filestream.close();
		}

	}
	else
	{
		filestream.open(kDataFileName, std::fstream::out);
		filestream << GetPlayerName() << " " << GetPlayerScore();
		highScore = GetPlayerScore();
		playerName = GetPlayerName();
		filestream.close();

	}
}