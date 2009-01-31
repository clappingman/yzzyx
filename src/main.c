#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "SDL_opengl.h"
#include "polygon.h"
#include "display.h"

double p[] = {-50, -50, 0.0,
              50, -50, 0.0,
              50, 50, 0.0,
              -50, 50, 0.0};

int main(int argc, char **argv) {
    display *screen = new display(640, 480);
    polygon *poly = new polygon(p, 12);
    
    glBegin(GL_QUADS);
    poly->display();
    glEnd();
    SDL_GL_SwapBuffers();
    sleep(1);

    return EXIT_SUCCESS;
}
