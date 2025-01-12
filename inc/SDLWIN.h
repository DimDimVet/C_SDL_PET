#ifndef SDLWIN_H
#define SDLWIN_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>

/*
* \param SDL_Window* - ������ ��������� �� ��������� SDL_Window
* \param char* nameWin - ��� ����
* \param int width - ������ ����
* \param int height - ������ ����
*/
SDL_Window* InitWin(char* nameWin, int width, int height);

/*
* ��������� ������
* \param SDL_Renderer* - ������ ��������� �� ��������� SDL_Renderer
* \param SDL_Window* win - ������� ����
*/
SDL_Renderer* InitRender(SDL_Window* win);

#endif
