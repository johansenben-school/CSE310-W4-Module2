#ifndef WINDOW
#define WINDOW

#include <string>
#include "util.hpp"
#include "Renderable.hpp"
#include "Renderer.hpp"

class Window {
  const std::string title = "Chess";
  bool rerender = true;
  bool initialized = false;
  bool running = false;

  SDL_Window* window;
  SDL_Event event;
  Renderer* renderer;
  Renderable* currentPage;

  void init();

  public:
  //constructor/destructor
  Window();
  ~Window();

  //methods
  void changePage(Renderable* newPage);
  void start();
};

#endif

