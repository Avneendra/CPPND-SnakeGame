#ifndef GAME_H
#define GAME_H

#include <random>
#include <string>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "playersInfo.h"

class Game {
 public:
  Game(std::size_t grid_width, 
       std::size_t grid_height, 
       std::size_t screen_width, 
       std::size_t screen_height,
       std::string &playerName);
  
  void Run(Controller const &controller, 
           Renderer         &renderer,
           std::size_t      target_frame_duration);
  
  unsigned int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  std::size_t gridWidth;
  std::size_t gridHeight; 
  PlayersInfo playerInfo;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  void PlaceFood();
  void Update();
  void DisplayScreen(Controller const &controller, Renderer &renderer,
                     std::string &message,  bool &running, bool &returnKey,
                     std::size_t target_frame_duration, int fontSize = 20);
};

#endif