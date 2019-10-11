#include "renderer.h"
#include <iostream>
#include <string>
#include "SDL_ttf.h"
#include "cleanup.h"

/*
 * Log an SDL error with some error message to the output stream of our choice
 * @param os The output stream to write the message too
 * @param msg The error message to write, format will be msg error: SDL_GetError()
 */
void logSDLError(std::ostream &os, const std::string &msg)
{
  os << msg << " error: " << SDL_GetError() << std::endl;
}

void logTTFError(std::ostream &os, const std::string &msg)
{
  os << msg << " error: " << TTF_GetError() << std::endl;
}

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    logSDLError(std::cerr, "SDL could not initialize");
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    logSDLError(std::cerr, "Window could not be created.");
    SDL_Quit();
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_SOFTWARE);
  if (nullptr == sdl_renderer) {
    logSDLError(std::cerr, "Renderer could not be created.");
    cleanup(sdl_window);
    SDL_Quit();
  }

  // Initialize font
  if (TTF_Init() < 0) 
  {
    logTTFError(std::cerr, "TTF couldn't be initialized");
    SDL_Quit();
  }

}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
  TTF_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &food) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(unsigned int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::Render(std::string &text, int fontSize)
{
      // Load font
    sdl_font = TTF_OpenFont("../font.ttf", fontSize);
    if(nullptr == sdl_font) {
      logTTFError(std::cout, "TTF_OpenFont");
      return;
    }
    SDL_Color White = {255, 255, 255, 0};
    SDL_Surface *screen = SDL_GetWindowSurface(sdl_window);
    if(screen == nullptr){
        logSDLError(std::cerr, "SDL WindowSurface error");
        TTF_CloseFont(sdl_font);
        return;
    }
    SDL_Surface *message   = TTF_RenderText_Blended(sdl_font, text.c_str(), White);
    if(message == nullptr)
    {
        logTTFError(std::cerr, "TTF_RenderText");
        TTF_CloseFont(sdl_font);
        return;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(sdl_renderer, message);
    if(texture == nullptr)
    {
        logSDLError(std::cerr, "CreateTexture");
        TTF_CloseFont(sdl_font);
        SDL_FreeSurface(message);
        return;
    }
    SDL_FreeSurface(message);
    TTF_CloseFont(sdl_font);

    //Get the texture w/h so we can center it in the screen
    int iW, iH;
    SDL_QueryTexture(texture, NULL, NULL, &iW, &iH);
    int x = screen->w/2- iW / 2;
    int y = screen->h/2 - iH / 2;

    SDL_RenderClear(sdl_renderer);
    //We can draw our message as we do any other texture, since it's been
    //rendered to a texture
    renderTexture(texture, x, y);
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::renderTexture(SDL_Texture *tex, int x, int y, SDL_Rect *clip)
{
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  if (clip != nullptr)
  {
    dst.w = clip->w;
    dst.h = clip->h;
  }
  else 
  {
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
  }
  renderTexture(tex, dst, clip);
}

void Renderer::renderTexture(SDL_Texture *tex, SDL_Rect dst, SDL_Rect *clip)
{
  SDL_RenderCopy(sdl_renderer, tex, clip, &dst);
}