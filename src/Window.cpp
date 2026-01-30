#include "Window.hpp"
#include "StartPage.hpp"

TTF_Font* font = nullptr;

void Window::init()
{
 if (SDL_Init(SDL_INIT_VIDEO) != 0) { //did SDL_Init work?
    std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
    return;
  }

  //create window
  this->window = SDL_CreateWindow(
    this->title.c_str(),
    SDL_WINDOWPOS_CENTERED_DISPLAY(DISPLAY),
    SDL_WINDOWPOS_CENTERED_DISPLAY(DISPLAY),
    WIN_WIDTH, WIN_HEIGHT,
    SDL_WINDOW_SHOWN
  );
  

  if (!this->window) {
    SDL_LogError_Debug("SDL_CreateWindow");
    SDL_Quit();
    return;
  }

  this->renderer = new Renderer(SDL_CreateRenderer(
    this->window,
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  ));
  if (!this->renderer) {
    SDL_LogError_Debug("SDL_CreateRenderer");
    return;
  }

  this->currentPage = new StartPage();

  this->initialized = true;
}

Window::Window()
{
  this->init();
}

Window::~Window()
{
  delete this->currentPage;
  delete this->renderer;

  SDL_DestroyWindow(this->window);
  SDL_Quit();
  TTF_CloseFont(font);
  TTF_Quit();
}

void Window::changePage(Renderable *newPage)
{
  delete currentPage;
  this->currentPage = newPage;
}

void Window::start()
{
  if (!this->initialized)
    return;
  this->running = true;
  while (this->running) {
    this->renderer->setColor({0,0,0,0});
    this->renderer->renderClear(this->renderer);
    while (SDL_PollEvent(&this->event)) {
      if (this->event.type == SDL_QUIT) {
        this->running = false;
        break;
      } else
        this->currentPage->handleEvent(event, *this, rerender);
    }
    this->currentPage->update();
    this->currentPage->render(this->renderer, this->rerender);

    this->renderer->renderPresent();
    // Small delay so we don't burn 100% CPU
    SDL_Delay(20);
  }
}
