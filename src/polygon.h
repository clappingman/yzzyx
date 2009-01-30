#ifndef __POLYGON_H__
#define __POLYGON_H__

#include "vertex.h"

class polygon {
 public:
    void display();

    polygon(double *, int n);
    ~polygon();
 private:
    vertex *vertices;
    int vertex_count;
    vertex angle;
};

#endif
