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
* \param char* nameWin - им€ окна
* \param int width - ширина окна
* \param int height - высота окна
*/
SDL_Window* InitWin(char* nameWin, int width, int height);

/*
* ‘ормируем рендер
* \param SDL_Renderer* - вернем указатель на структуру SDL_Renderer
* \param SDL_Window* win - целевое окно
*/
SDL_Renderer* InitRender(SDL_Window* win);

/*
* —оздает текстуру из внешнего файла .png
* \param SDL_Texture* - вернем указатель на текстуру
* \param SDL_Renderer* rend - целевой рендер
* \param char* pathImg - путь к вайлу .png
*/
SDL_Texture* InitTexturePng(SDL_Renderer* rend , char* pathImg );

/*
* «аписывает целевую текстуру в рендер (.png файл), требует очишение пам€ти
* \param SDL_Texture* - целева€ текстура
* \param SDL_Renderer* rend - целевой рендер
* \param int positionX - значение координат по ’
* \param int positionY - значение координат по Y
*/
void RenderTexturePng( SDL_Texture* texture , SDL_Renderer* rend , int positionX , int positionY );

/*
* «аписывает целевую текстуру в рендер (.png файл), требует очишение пам€ти
* \param SDL_Rect - вернем структуру позиции и размеров полученое из целевой текстуры
* \param SDL_Texture* - целева€ текстура
*/
SDL_Rect InitDest( SDL_Texture* texture );

/*
* «аписывает динамически целевую текстуру в рендер (.png файл), требует очишение пам€ти
* \param SDL_Texture* - целева€ текстура
* \param SDL_Renderer* rend - целевой рендер
* \param SDL_Rect* dest - структура позиции и размеров объекта
* \param double angle - угол поворота объекта
*/
void UpDateRenderTexturePng( SDL_Texture* texture , SDL_Renderer* rend , SDL_Rect* dest , double angle );

/*
* —оздает текстуру из текстового значени€
* \param SDL_Texture* - вернем указатель на текстуру
* \param SDL_Renderer* rend - целевой рендер
* \param char* str - текстовое содержание
* \param TTF_Font* font - структура настройка шрифта текста
* \param SDL_Color color - структура настройка цвета текста
*/
SDL_Texture* InitText( SDL_Renderer* rend , char* str , TTF_Font* font , SDL_Color color );

/*
* «аписывает целевую текстуру в рендер, требует очишение пам€ти
* \param SDL_Texture* - целева€ текстура
* \param SDL_Renderer* rend - целевой рендер
* \param int positionX - значение координат по ’
* \param int positionY - значение координат по Y
*/
void RenderTextureText( SDL_Texture* texture , SDL_Renderer* rend , int positionX , int positionY );

/*
* —оздает текстуру из текстового значени€, записывает результат в рендер
* \param SDL_Texture* - целева€ текстура
* \param SDL_Renderer* rend - целевой рендер
* \param char* str - текстовое содержание
* \param TTF_Font* font - структура настройка шрифта текста
* \param SDL_Color color - структура настройка цвета текста
* \param int positionX - значение координат по ’
* \param int positionY - значение координат по Y
*/
void UpDateRenderTextureText( SDL_Texture* texture, SDL_Renderer* rend , char* str , TTF_Font* font , SDL_Color color , int positionX , int positionY );

int BoundaryX( SDL_Rect dest , int width );

int BoundaryY( SDL_Rect dest , int height );

void CloseSDL( TTF_Font* font , SDL_Renderer* rend , SDL_Window* win );

#endif
