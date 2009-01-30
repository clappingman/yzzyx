#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include "display.h"

const unsigned SDL_FLAGS = SDL_DOUBLEBUF;
const int BIT_DEPTH = 16;
const int DEFAULT_WIDTH = 640;
const int DEFAULT_HEIGHT = 480;

display::display(int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Unable to initialize SDL\n");
        exit(EXIT_FAILURE);
    }
    this->width = width;
    this->height = height;
    surface = SDL_SetVideoMode(width, height, BIT_DEPTH, SDL_FLAGS);
    atexit(SDL_Quit);
}

display::~display() {
    SDL_FreeSurface(surface);
}
