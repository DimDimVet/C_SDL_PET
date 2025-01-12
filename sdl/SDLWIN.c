#include "SDLWIN.h"


SDL_Window* InitWin(char* nameWin, int width, int height)
{
	SDL_Window* win;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)//�������� ���������� ����
	{
		printf("Error init Win SDL: %s\n", SDL_GetError());
	}
	else
	{
		TTF_Init();//�������� ���������� �������
		IMG_Init(IMG_INIT_PNG);//�������� ���������� ��������

		win = SDL_CreateWindow(
			nameWin,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width, height, 0);
		return win;
	}
}

SDL_Renderer* InitRender(SDL_Window* win)
{
	// ��������� ���������, ������� ��������� ���� ������������� � ������������ �����
	Uint32 render_flags = SDL_RENDERER_ACCELERATED;
	// �������� �������� ��� ���������� �����������
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
	return rend;
}