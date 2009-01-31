#include <stdlib.h>
#include "SDL_opengl.h"
#include "skeleton.h"

void skeleton::add_child(polygon *child, double x, double y, double z) {
    skeleton *current = this;
    
    while (current->next) {
        current = current->next;
    }

    current->next = new skeleton(child, x, y, z);
}

void skeleton::add_child(skeleton *child, double x, double y, double z) {
    skeleton *current = this;
    
    while (current->next) {
        current = current->next;
    }

    current->next = new skeleton(child, x, y, z);
}

void skeleton::display() {
    skeleton *current = this;

    while(current) {
        glPushMatrix();
        glTranslated(current->translation.x,
                     current->translation.y, 
                     current->translation.z);
        if (current->contents) 
            current->contents->display();
        else
            current->subtree->display();
        glPopMatrix();

        current = current->next;
    }
}

skeleton::skeleton(polygon *contents) {
    translation.x = 0.0;
    translation.y = 0.0;
    translation.z = 0.0;
    this->contents = contents;
    next = NULL;
}

skeleton::skeleton(polygon *contents, double x, double y, double z) {
    translation.x = x;
    translation.y = y;
    translation.z = z;
    this->contents = contents;
    next = NULL;
}

skeleton::skeleton(skeleton *subtree, double x, double y, double z) {
    translation.x = x;
    translation.y = y;
    translation.z = z;
    this->subtree = subtree;
    next = NULL;
}

/* TODO: this will leak */
skeleton::~skeleton() {
    if (next)
        delete next;
}
