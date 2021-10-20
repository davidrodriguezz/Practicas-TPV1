//
// Created by eys on 20/8/21.
//

#include "ViewController.h"


ViewController::ViewController(Game *_game) {
    game = _game;
    cout << "[DEBUG] frame duration: " << frameDuration() << " ms" << endl;
    initSDL();

    game->setRenderer(renderer);
    game->loadTextures();
    estado = menu;
}

void ViewController::run() {
    
    if(menu){
        handleEvents();
        game->drawMenuInfo();
    }


    else if (playing) {
        cout << "playing" << endl;
        uint32_t startTime = 0;
        uint32_t frameTime;
        game->startGame();


        while (!game->doQuit()) {
            frameTime = SDL_GetTicks() - startTime;
            handleEvents();
            if (frameTime >= frameDuration()) {
                clearBackground();
                game->update();
                game->draw();
                SDL_RenderPresent(renderer);
                startTime = SDL_GetTicks();
            }
            else {
                SDL_Delay(frameDuration() - frameTime);
            }
        }
    }
}

void ViewController::clearBackground() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void ViewController::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) ){
        if( event.type == SDL_QUIT)
            game->setUserExit();
        else if(event.type == SDL_KEYDOWN){
            SDL_Keycode key = event.key.keysym.sym;

        if (key== SDLK_UP) {
            game->setCarUp();
        }
        else if (key ==SDLK_DOWN ) {
            game->setCarDown();
        }
        else if (key == SDLK_RIGHT) {
            game->Accelerate();
        }
        else if (key == SDLK_LEFT) {
            game->Brake();
        }
        else if (key == SDLK_SPACE&&menu) {
            estado = playing;
        }
        }
     
    }
}

uint32_t ViewController::frameDuration() {
    return 1000 / FRAME_RATE;
}

void ViewController::initSDL() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(game->getGameName().c_str(),
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              game->getWindowWidth(),
                              game->getWindowHeight(),
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (window == nullptr || renderer == nullptr)
        throw string("Error creating SDL window or renderer");

    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, &screenSurface->clip_rect, 0xFF);
    SDL_UpdateWindowSurface(window);
}

ViewController::~ViewController() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
