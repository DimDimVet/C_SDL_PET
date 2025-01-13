#include <SDL.h>
#include <SDL_timer.h>
#include <stdio.h>
#include <stdbool.h>
#include "tst.h"


#define WIN_WIDTH 500
#define WIN_HEIGHT 500

#define path_GND_PNG "res/gnd.png"
#define path_TNK_PNG "res/tnk.png"
#define path_Font "res/ofont.ru_Evolventa.ttf"
#define size_Font 48

int tst()
{
	char str[10];

	SDL_Window* win;
	win = InitWin("GAMETEST", WIN_WIDTH, WIN_HEIGHT);

	// �������� �������
	SDL_Renderer* rend;
	rend = InitRender(win);

	// �������� �������� �� ��������
	SDL_Texture* texMap = InitTexturePng(rend, path_GND_PNG);
	SDL_Texture* texPlay = InitTexturePng(rend, path_TNK_PNG);

	// �������� ������
	char* str1 = "PRIVED!";
	TTF_Font* font = TTF_OpenFont(path_Font, size_Font);
	// �������� �����
	SDL_Color textColor = { 255, 255, 255, 255 };
	// �������� �������� �� ��������
	SDL_Texture* texText = InitText(rend, str1, font, textColor);
	SDL_Texture* texTextDinamic = InitText(rend, str1, font, textColor);;

	// �������� ������� �������� � �������
	SDL_Rect dest = InitDest(texPlay);
	double angle = 35; // ���� ��������

	// ������ � ������ �������
	dest.w /= 10;
	dest.h /= 10;

	// ������� �� ���� �������
	dest.x = (WIN_WIDTH - dest.w) / 2;
	dest.y = (WIN_HEIGHT - dest.h) / 2;

	// controls animation loop
	int close = 0;

	// �������� ����������� �������
	int speed = 300;

	bool loop = false;
	int counLoop = 0;

	//������ ������� ������� (����+���)
	SDL_Event event;

	// animation loop
	while (!close)
	{
		//������� �������
		SDL_RenderClear(rend);

		counLoop++;
		if (counLoop >= 50)
		{
			counLoop = 0;
		}

		snprintf(str, sizeof str, "count %d", counLoop);

		//�������� � ������ �������� �������� (����)
		RenderTexturePng(texMap, rend, WIN_WIDTH, WIN_HEIGHT);
		//�������� � ������ �������� �������� � �������(������) (�������� �������)
		UpDateRenderTexturePng(texPlay, rend, &dest, angle);
		//�������� � ������ �������� ������ (��������� �����)
		RenderTextureText(texText, rend, WIN_WIDTH, WIN_HEIGHT);
		//�������� � ������ �������� ������ (���������� �����)
		UpDateRenderTextureText(texTextDinamic, rend, str, font, textColor, WIN_WIDTH, WIN_HEIGHT + 100);

		// Events management
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{

			case SDL_QUIT:
			case SDL_SCANCODE_ESCAPE:
				// handling of close button
				close = 1;
				break;

			case SDL_KEYDOWN:
				// keyboard API for key pressed
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_W:
				case SDL_SCANCODE_UP:
					dest.y -= speed / 30;
					break;
				case SDL_SCANCODE_A:
				case SDL_SCANCODE_LEFT:
					dest.x -= speed / 30;
					break;
				case SDL_SCANCODE_S:
				case SDL_SCANCODE_DOWN:
					dest.y += speed / 30;
					break;
				case SDL_SCANCODE_D:
				case SDL_SCANCODE_RIGHT:
					dest.x += speed / 30;
					break;
				default:
					break;
				}
			}
		}

		dest.x = BoundaryX(dest, WIN_WIDTH);
		dest.y = BoundaryY(dest, WIN_HEIGHT);

		SDL_RenderPresent(rend);

		// calculates to 60 fps
		SDL_Delay(1000 / 60);
	}

	// �������� ��������
	SDL_DestroyTexture(texMap);
	SDL_DestroyTexture(texPlay);
	SDL_DestroyTexture(texText);

	CloseSDL(font, rend, win);

	return 0;

	//SDL_Event event;
	//int running = 1;

	//while (running) 
	//{
	//	/*while (SDL_PollEvent(&event)) {
	//		switch (event.type) {
	//		case SDL_QUIT:
	//			running = 0;
	//			break;

	//		case SDL_MOUSEBUTTONDOWN:
	//			if (event.button.button == SDL_BUTTON_LEFT) {
	//				printf("Left mouse button clicked at (%d, %d)\n",
	//					event.button.x, event.button.y);
	//			}
	//			break;

	//		case SDL_KEYDOWN:
	//			printf("Key pressed: %s\n",
	//				SDL_GetKeyName(event.key.keysym.sym));
	//			break;
	//		}
	//	}*/


}