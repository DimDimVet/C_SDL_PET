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

SDL_Texture* InitTexturePng(SDL_Renderer* rend, char* pathImg)
{
	if (pathImg==NULL)
	{
		pathImg = "";
	}

	SDL_Surface* surface;//������� ������
	surface = IMG_Load(pathImg);//�������� �������� � �����������
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, surface);//�������� �������� �� ��������������� ��������
	SDL_FreeSurface(surface);//������� ������
	return texture;
}

void RenderTexturePng(SDL_Texture* texture, SDL_Renderer* rend, int positionX, int positionY)
{
	SDL_Rect dest;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	dest.w /= 1;
	dest.h /= 1;

	dest.x = (positionX - dest.w) / 2;
	dest.y = (positionY - dest.h) / 2;

	SDL_RenderCopy(rend, texture, NULL, &dest);
}

void UpDateRenderTexturePng(SDL_Texture* texture, SDL_Renderer* rend, SDL_Rect dest)
{
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(rend, texture, NULL, &dest);
}

SDL_Texture* InitText(SDL_Renderer* rend, char* str, TTF_Font* font, SDL_Color color)
{
	if (str == NULL)
	{
		str = "xxx";
	}

	SDL_Surface* surface;//������� ������
	surface = TTF_RenderText_Solid(font, str, color);//�������� ����� � �����������
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, surface);//�������� �������� �� ��������������� ������
	SDL_FreeSurface(surface);//������� ������
	return texture;
}

void RenderTextureText(SDL_Texture* texture, SDL_Renderer* rend, int positionX, int positionY)
{
	SDL_Rect dest;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	dest.w /= 1;
	dest.h /= 1;

	dest.x = (positionX - dest.w) / 2;
	dest.y = (positionY - dest.h) / 2;
	
	SDL_RenderCopy(rend, texture, NULL, &dest);
}

void UpDateRenderTextureText(SDL_Texture* texture, SDL_Renderer* rend, char* str, TTF_Font* font, SDL_Color color, int positionX, int positionY)
{
	if (str == NULL)
	{
		str = "xxx";
	}

	SDL_Surface* surface;//������� ������
	surface = TTF_RenderText_Solid(font, str, color);//�������� ����� � �����������
	texture = SDL_CreateTextureFromSurface(rend, surface);//�������� �������� �� ��������������� ������

	SDL_Rect dest;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	dest.w /= 1;
	dest.h /= 1;
	dest.x = (positionX - dest.w) / 2;
	dest.y = (positionY - dest.h) / 2;

	SDL_RenderCopy(rend, texture, NULL, &dest);

	SDL_FreeSurface(surface);//������� ������
	SDL_DestroyTexture(texture);
}