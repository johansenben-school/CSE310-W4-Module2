#include "Renderer.hpp"

Renderer::Renderer(SDL_Renderer* r)
{
  this->renderer = r;
  TTF_Init();
  this->font = TTF_OpenFont("Arial.ttf", 48);
}

Renderer::~Renderer()
{
  SDL_DestroyRenderer(this->renderer);
  SDL_FreeSurface(textSurface);
}

void Renderer::setColor(SDL_Color color)
{
  SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
}

void Renderer::renderText(std::string text, SDL_Color color, int x, int y, bool rerender)
{
  this->textRect.x = x;
  this->textRect.y = y;
  if (text != this-> lastText || rerender) {
    this->lastText = text;
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(this->textTexture);
    this->textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
    this->textTexture = SDL_CreateTextureFromSurface(this->renderer, this->textSurface);
    SDL_QueryTexture(this->textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
  }
  SDL_RenderCopy(this->renderer, this->textTexture, nullptr, &textRect);
}

void Renderer::renderRect(int x, int y, int width, int height)
{
  SDL_Rect* r = new SDL_Rect{ x, y, width, height };
  SDL_RenderFillRect(this->renderer, r);
  delete r;
}

void Renderer::renderPolygon(int points, int x, int y, int radius)
{
  if (points < 3)
    return;
  for (int i = 0; i < points; ++i) {
    float angle1 = (i * 2.0f * M_PI) / points;
    float angle2 = ((i + 1) * 2.0f * M_PI) / points;

    int x1 = static_cast<int>(x + radius * cos(angle1));
    int y1 = static_cast<int>(y + radius * sin(angle1));
    int x2 = static_cast<int>(x + radius * cos(angle2));
    int y2 = static_cast<int>(y + radius * sin(angle2));

    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
  }
}

void Renderer::renderClear(bool rerender)
{
  if (rerender)
    SDL_RenderClear(this->renderer);
}

void Renderer::renderPresent()
{
  SDL_RenderPresent(renderer);
}
