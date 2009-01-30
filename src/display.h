#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "SDL.h"

class display {
 public:
    display(int, int);
    ~display();

 private:
    int width, height;
    SDL_Surface *surface;
};

#endif
