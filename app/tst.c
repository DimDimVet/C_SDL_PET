#include <SDL.h>
#include <SDL_timer.h>
#include <stdio.h>
#include <stdbool.h>
#include "tst.h"


#define WIN_WIDTH 500
#define WIN_HEIGHT 500

#define path_GND_PNG "res/gnd.png"
#define path_TNK_PNG "res/tnk.png"

int tst()
{
    char str[10];
    //// returns zero on success else non-zero
    //if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    //    printf("error initializing SDL: %s\n", SDL_GetError());
    //}
    //SDL_Window* win = SDL_CreateWindow("GAME", // creates a window
    //    SDL_WINDOWPOS_CENTERED,
    //    SDL_WINDOWPOS_CENTERED,
    //    1000, 1000, 0);
    SDL_Window* win;
    win=InitWin("GAMETEST", WIN_WIDTH, WIN_HEIGHT);

    //// запускает программу, которая управляет
    //// ваше графическое оборудование и устанавливает флаги
    //Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    //// создает рендерер для рендеринга наших изображений
    //SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_Renderer* rend;
    rend = InitRender(win);

    // создает поверхность для загрузки изображения в основную память
   // SDL_Texture* texMap;
    //SDL_Texture* tex;
    //SDL_Texture* textTexture;

    // creates a surface to load an image into the main memory
   // SDL_Surface* surfaceMap;
    //SDL_Surface* surface;
    SDL_Surface* surfaceTxt;

    // пожалуйста, укажите путь для вашего изображения
   // surfaceMap = IMG_Load(path_GND_PNG);
    SDL_Texture* texMap = InitTexturePng(rend, path_GND_PNG);
    SDL_Texture* tex = InitTexturePng(rend, path_TNK_PNG);

    //surface = IMG_Load(path_TNK_PNG);
    // Загрузка шрифта
    char* str1 = "PRIVED! по РУССКИ";
    TTF_Font* font = TTF_OpenFont("res/ofont.ru_Evolventa.ttf", 48);
    SDL_Color textColor = { 255, 255, 255, 255 }; // цвет
    SDL_Texture* textTexture = InitText(rend, str1, font, textColor);
    SDL_Texture* textTexture1 = InitText(rend, str1, font, textColor);;
    // загружает изображение в память нашего графического оборудования.
   // texMap = SDL_CreateTextureFromSurface(rend, surfaceMap);
   // tex = SDL_CreateTextureFromSurface(rend, surface);

    //surfaceTxt = TTF_RenderText_Solid(font, "PRIVED! по РУССКИ", textColor);
    //textTexture = SDL_CreateTextureFromSurface(rend, surfaceTxt);

    // clears main-memory
   // SDL_FreeSurface(surfaceMap);
   // SDL_FreeSurface(surface);
    

    // let us control our image position

    // so that we can move it with our keyboard.
   // SDL_Rect destMap;
    SDL_Rect dest;
    //SDL_Rect destTxt;

    // соединяет нашу текстуру с dest для управления позицией

    //SDL_QueryTexture(texMap, NULL, NULL, &destMap.w, &destMap.h);
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    //SDL_QueryTexture(textTexture, NULL, NULL, &destTxt.w, &destTxt.h);

    printf("w=%d h=%d\n", dest.w, dest.h);

    // отрегулируйте высоту и ширину нашего поля изображения.
    //destMap.w /= 1;
    //destMap.h /= 1;

    dest.w /= 2;
    dest.h /= 2;

    /*destTxt.w /= 2;
    destTxt.h /= 2;*/

    // устанавливает начальное положение x объекта
    //destMap.x = (WIN_WIDTH - destMap.w) / 2;
    dest.x = (WIN_WIDTH - dest.w) / 2;
    //destTxt.x = (WIN_WIDTH - destTxt.w) / 2;
    

    // устанавливает начальное положение y объекта
    //destMap.y = (WIN_HEIGHT - destMap.h) / 2;
    dest.y = (WIN_HEIGHT - dest.h) / 2;
    //destTxt.y = (WIN_HEIGHT - destTxt.h) / 2;

    double angle = 35; // Угол поворота


    // controls animation loop
    int close = 0;

    // speed of box
    int speed = 300;

    bool loop = false;
    int counLoop = 0;
    
    // animation loop
    while (!close)
    {
        // clears the screen
        SDL_RenderClear(rend);
        //SDL_RenderCopy(rend, texMap, NULL, &destMap);
        RenderTexturePng(texMap, rend, WIN_WIDTH, WIN_HEIGHT);
        SDL_RenderCopyEx(rend, tex, NULL, &dest, angle, NULL, SDL_FLIP_NONE);
        RenderTextureText(textTexture, rend, WIN_WIDTH, WIN_HEIGHT);
        //SDL_RenderCopy(rend, textTexture, NULL, &destTxt);

        SDL_Event event;

        counLoop++;
        if (counLoop >= 50)
        {
            if (loop)
            {
                dest.h = 50;
                dest.w = 50;
                loop = !loop;
            }
            else
            {
                dest.h = 52;
                dest.w = 52;
                loop = !loop;
            }
            //printf("w=%d h=%d\n", destTxt.w, destTxt.h);

           //surfaceTxt = TTF_RenderText_Solid(font, str, textColor);
            //textTexture = SDL_CreateTextureFromSurface(rend, surfaceTxt);
            
            counLoop = 0;
        }
        else
        {
            snprintf(str, sizeof str, "count =%d \n", counLoop);
            printf("str=%s\n", str);

            UpDateRenderTextureText(textTexture1, rend, str, font, textColor, WIN_WIDTH, WIN_HEIGHT+100);
        }

        // Events management
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed
                switch (event.key.keysym.scancode) {
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

        // right boundary
        if (dest.x + dest.w > WIN_WIDTH)
            dest.x = WIN_WIDTH - dest.w;

        // left boundary
        if (dest.x < 0)
            dest.x = 0;

        // bottom boundary
        if (dest.y + dest.h > WIN_HEIGHT)
            dest.y = WIN_HEIGHT - dest.h;

        // upper boundary
        if (dest.y < 0)
            dest.y = 0;

        
        //

        /*SDL_RenderCopy(rend, texMap, NULL, &destMap);
        SDL_RenderCopyEx(rend, tex, NULL, &dest, angle, NULL, SDL_FLIP_NONE);*/

        //SDL_RenderCopy(rend, tex, NULL, &dest);
        //SDL_RenderCopy(rend, textTexture, NULL, &destTxt);
        
        // triggers the double buffers
        // for multiple rendering
        SDL_RenderPresent(rend);

        // calculates to 60 fps
        SDL_Delay(1000 / 60);
    }

    // destroy texture
    SDL_DestroyTexture(texMap);
    SDL_DestroyTexture(tex);
    SDL_DestroyTexture(textTexture);
    

    // destroy renderer
    TTF_CloseFont(font);
    SDL_DestroyRenderer(rend);

    // destroy window
    SDL_DestroyWindow(win);

    // close SDL
    TTF_Quit();
    SDL_Quit();
    IMG_Quit();

    return 0;




    //SDL_Init(SDL_INIT_VIDEO);

    //SDL_Window* window = SDL_CreateWindow("Mouse and Keyboard Input",
    //	SDL_WINDOWPOS_UNDEFINED,
    //	SDL_WINDOWPOS_UNDEFINED,
    //	800,
    //	600,
    //	0);

    //if (window == NULL) 
    //{
    //	printf("Could not create window: %s\n", SDL_GetError());
    //	return 1;
    //}

    //SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    ///*SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255); // Устанавливаем цвет (синий)
    //SDL_RenderClear(renderer);
    //SDL_RenderPresent(renderer);*/
    ////
    //// 
    ////укажем путь к текстуре
    //SDL_Surface* surface;
    //surface = SDL_LoadBMP("textTst1.bmp");
    //SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);

    //// clears main-memory
    //SDL_FreeSurface(surface);

    //SDL_Rect rect = { 10, 10, 5, 5 }; // Позиция и размер.
    //// connects our texture with dest to control position
    //SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
    //// adjust height and width of our image box.
    //rect.w /= 6;
    //rect.h /= 6;
    //// sets initial x-position of object
    //rect.x = (1000 - rect.w) / 2;

    //// sets initial y-position of object
    //rect.y = (1000 - rect.h) / 2;


    ////
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

    //	while (SDL_PollEvent(&event))
    //	{
    //		if (event.type == SDL_QUIT) running = false;
    //	}
    //	const Uint8* state = SDL_GetKeyboardState(NULL);
    //	if (state[SDL_SCANCODE_LEFT]) rect.x -= 5;   // Влево
    //	if (state[SDL_SCANCODE_RIGHT]) rect.x += 5;  // Вправо
    //	if (state[SDL_SCANCODE_UP]) rect.y -= 5;     // Вверх
    //	if (state[SDL_SCANCODE_DOWN]) rect.y += 5;   // Вниз

    //	// Отрисовка
    //	SDL_RenderClear(renderer);
    //	SDL_SetRenderDrawColor(renderer, 200, 0, 0, 200); // Красный цвет для объекта.
    //	SDL_RenderFillRect(renderer, &rect);
    //	SDL_RenderPresent(renderer);
    //	SDL_Delay(16); // Для 60 FPS.

    //	//SDL_Delay(16);
    //}

    //SDL_DestroyRenderer(renderer);

    //SDL_DestroyWindow(window);
    //SDL_Quit();

    //return 0;

}