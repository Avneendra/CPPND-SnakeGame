#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>
#include "SDL.h"
#include "snake.h"
#include "SDL_ttf.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food);
  void UpdateWindowTitle(unsigned int score, int fps);
  void Render(std::string &text, int fontSize);

 private:
  void renderTexture(SDL_Texture *tex, SDL_Rect dst, SDL_Rect *clip = nullptr);
  void renderTexture(SDL_Texture *tex, int x, int y, SDL_Rect *clip = nullptr);

  SDL_Window   *sdl_window = nullptr;
  SDL_Renderer *sdl_renderer = nullptr;
  TTF_Font *sdl_font = nullptr;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif