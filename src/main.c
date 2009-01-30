#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "display.h"

int main(int argc, char **argv) {
    display *screen = new display(640, 480);

    sleep(1);

    return EXIT_SUCCESS;
}
