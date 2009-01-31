#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include "SDL_opengl.h"
#include "display.h"

const unsigned SDL_FLAGS = SDL_OPENGL;
const int BIT_DEPTH = 16;
const int DEFAULT_WIDTH = 640;
const int DEFAULT_HEIGHT = 480;

display::display(int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    this->width = width;
    this->height = height;
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    surface = SDL_SetVideoMode(width, height, BIT_DEPTH, SDL_FLAGS);
    //    glEnable(GL_TEXTURE_2D);
 
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
 
    glViewport(0, 0, 640, 480);
 
    glClear(GL_COLOR_BUFFER_BIT);
 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
 
    glOrtho(0.0f, 640, 480, 0.0f, -1.0f, 1.0f);
	
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    atexit(SDL_Quit);
}

display::~display() {
    SDL_FreeSurface(surface);
}
