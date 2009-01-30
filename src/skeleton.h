#ifndef __SKELETON_H__
#define __SKELETON_H__

#include "polygon.h"
#include "vertex.h"

/* 
   This class effectively forms a linked list.

   The head of any list is the root of that skeleton.

   If the contents is NULL then it is another skeleton
   as a child (i.e. a subtree) 
*/
class skeleton {
 public:
    void display();
    void add_child(polygon *, double, double, double);
    void add_child(skeleton *, double, double, double);

    skeleton(polygon *);
    skeleton(polygon *, double, double, double);
    skeleton(skeleton *, double, double, double);
    ~skeleton();

 private:
    vertex translation;         /* Relative placement of children */
    polygon *contents;

    skeleton *subtree;          /* Placeholder indicating a subtree */

    skeleton *next;             /* Children */
};

#endif
