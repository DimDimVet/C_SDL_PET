#include "SDLWIN.h"


SDL_Window* InitWin(char* nameWin, int width, int height)
{
	SDL_Window* win;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)//запустим библиотеку окна
	{
		printf("Error init Win SDL: %s\n", SDL_GetError());
	}
	else
	{
		TTF_Init();//запустим библиотеку шрифтов
		IMG_Init(IMG_INIT_PNG);//запустим библиотеку картинок

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
	// запускает программу, которая управляет граф оборудованием и устанавливим флаги
	Uint32 render_flags = SDL_RENDERER_ACCELERATED;
	// создадим рендерер для рендеринга изображений
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
	return rend;
}

SDL_Texture* InitTexturePng(SDL_Renderer* rend, char* pathImg)
{
	if (pathImg==NULL)
	{
		pathImg = "";
	}

	SDL_Surface* surface;//выделим память
	surface = IMG_Load(pathImg);//загрузим картинку и преобразуем
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, surface);//создадим текстуру из преобразованной картинки
	SDL_FreeSurface(surface);//очистим память
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

SDL_Rect InitDest(SDL_Texture* texture)
{
	SDL_Rect dest;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	return dest;
}

void UpDateRenderTexturePng(SDL_Texture* texture, SDL_Renderer* rend, SDL_Rect* dest, double angle)
{
	SDL_QueryTexture(texture, NULL, NULL, &dest->w, &dest->h);
	SDL_RenderCopyEx(rend, texture, NULL, dest, angle, NULL, SDL_FLIP_NONE);
}

SDL_Texture* InitText(SDL_Renderer* rend, char* str, TTF_Font* font, SDL_Color color)
{
	if (str == NULL)
	{
		str = "xxx";
	}

	SDL_Surface* surface;//выделим память
	surface = TTF_RenderText_Solid(font, str, color);//загрузим текст и преобразуем
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, surface);//создадим текстуру из преобразованной текста
	SDL_FreeSurface(surface);//очистим память
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

	SDL_Surface* surface;//выделим память
	surface = TTF_RenderText_Solid(font, str, color);//загрузим текст и преобразуем
	texture = SDL_CreateTextureFromSurface(rend, surface);//создадим текстуру из преобразованной текста

	SDL_Rect dest;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	dest.w /= 1;
	dest.h /= 1;
	dest.x = (positionX - dest.w) / 2;
	dest.y = (positionY - dest.h) / 2;

	SDL_RenderCopy(rend, texture, NULL, &dest);

	SDL_FreeSurface(surface);//очистим память
	SDL_DestroyTexture(texture);
}

int BoundaryX(SDL_Rect dest, int width)
{
	// правая граница
	if (dest.x + dest.w > width)
	{
		dest.x = width - dest.w;
	}

	// левая граница
	if (dest.x < 0)
	{
		dest.x = 0;
	}
		
	return dest.x;
}

int BoundaryY(SDL_Rect dest, int height)
{
	// нижния граница
	if (dest.y + dest.h > height)
	{
		dest.y = height - dest.h;
	}

	// верхнея граница
	if (dest.y < 0)
	{
		dest.y = 0;
	}

	return dest.y;
}

void CloseSDL(TTF_Font* font, SDL_Renderer* rend, SDL_Window* win)
{
	// destroy renderer

	TTF_CloseFont(font);
	SDL_DestroyRenderer(rend);

	// destroy window
	SDL_DestroyWindow(win);

	// close SDL
	TTF_Quit();
	SDL_Quit();
	IMG_Quit();
}