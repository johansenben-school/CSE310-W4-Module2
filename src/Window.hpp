#ifndef WINDOW
#define WINDOW

#include <string>
#include "libs.hpp"
#include "Renderable.hpp"
#include "Renderer.hpp"

class Window {
  const std::string title = "Chess";

  SDL_Window* window;

  bool initialized = false;
  bool running = false;

  SDL_Event event;
  Renderer* renderer;

  Renderable* currentPage;

  void init();

  public:

  Window();
  ~Window();

  void changePage(Renderable* newPage);
  void start();
};

#endif

