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

/*
* ������� �������� �� �������� ����� .png
* \param SDL_Texture* - ������ ��������� �� ��������
* \param SDL_Renderer* rend - ������� ������
* \param char* pathImg - ���� � ����� .png
*/
SDL_Texture* InitTexturePng(SDL_Renderer* rend , char* pathImg );

/*
* ���������� ������� �������� � ������ (.png ����), ������� �������� ������
* \param SDL_Texture* - ������� ��������
* \param SDL_Renderer* rend - ������� ������
* \param int positionX - �������� ��������� �� �
* \param int positionY - �������� ��������� �� Y
*/
void RenderTexturePng( SDL_Texture* texture , SDL_Renderer* rend , int positionX , int positionY );

/*
* ������� �������� �� ���������� ��������
* \param SDL_Texture* - ������ ��������� �� ��������
* \param SDL_Renderer* rend - ������� ������
* \param char* str - ��������� ����������
* \param TTF_Font* font - ��������� ��������� ������ ������
* \param SDL_Color color - ��������� ��������� ����� ������
*/
SDL_Texture* InitText( SDL_Renderer* rend , char* str , TTF_Font* font , SDL_Color color );

/*
* ���������� ������� �������� � ������, ������� �������� ������
* \param SDL_Texture* - ������� ��������
* \param SDL_Renderer* rend - ������� ������
* \param int positionX - �������� ��������� �� �
* \param int positionY - �������� ��������� �� Y
*/
void RenderTextureText( SDL_Texture* texture , SDL_Renderer* rend , int positionX , int positionY );

/*
* ������� �������� �� ���������� ��������, ���������� ��������� � ������
* \param SDL_Texture* - ������� ��������
* \param SDL_Renderer* rend - ������� ������
* \param char* str - ��������� ����������
* \param TTF_Font* font - ��������� ��������� ������ ������
* \param SDL_Color color - ��������� ��������� ����� ������
* \param int positionX - �������� ��������� �� �
* \param int positionY - �������� ��������� �� Y
*/
void UpDateRenderTextureText( SDL_Texture* texture, SDL_Renderer* rend , char* str , TTF_Font* font , SDL_Color color , int positionX , int positionY );



#endif
