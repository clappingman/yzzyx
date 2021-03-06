#include <stdlib.h>
#include "SDL_opengl.h"
#include "polygon.h"

void polygon::display() {
    int i;
    glPushMatrix();
    glRotated(angle.x, 1, 0, 0);
    glRotated(angle.y, 0, 1, 0);
    glRotated(angle.z, 0, 0, 1);
    for (i = 0; i < vertex_count; i++) {
        glVertex3d(vertices[i].x, 
                   vertices[i].y,
                   vertices[i].z);
    }
    glPopMatrix();
}

polygon::polygon(double *data, int n) {
    int i;
    vertices = (vertex *) malloc(sizeof vertices[0] * n/3);
    vertex_count = n/3;
    for (i = 0; i < n/3; i++) {
        vertices[i].x = data[i*3];
        vertices[i].y = data[i*3+1];
        vertices[i].z = data[i*3+2];
    }
}

polygon::~polygon() {
    free(vertices);
}
