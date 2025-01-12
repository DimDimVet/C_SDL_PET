#ifndef SDLWIN_H
#define SDLWIN_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>

/*
* \param SDL_Window* - вернем указатель на структуру SDL_Window
* \param char* nameWin - имя окна
* \param int width - ширина окна
* \param int height - высота окна
*/
SDL_Window* InitWin(char* nameWin, int width, int height);

/*
* Формируем рендер
* \param SDL_Renderer* - вернем указатель на структуру SDL_Renderer
* \param SDL_Window* win - целевое окно
*/
SDL_Renderer* InitRender(SDL_Window* win);

#endif
