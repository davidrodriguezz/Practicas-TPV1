//
// Created by eys on 20/8/21.
//

#ifndef CARGAME_VIEWCONTROLLER_H
#define CARGAME_VIEWCONTROLLER_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"


#include "../Logic/Game.h"
#include "CommandFactory.h"

const int FRAME_RATE = 30;

class ViewController {
private:
    Game *game;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    CommandFactory* commandFactory = nullptr;
    void initSDL();
public:
    ViewController(Game *game);

    ~ViewController();

    void run();
    void handleEvents();
    void clearBackground();

    unsigned int frameDuration();
    //enum Estado { menu, playing, gameOver } estado;		//enum de estados
	bool salir = false;		//booleano para poder salir del juego en menu o gameover
};


#endif //CARGAME_VIEWCONTROLLER_H
