
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "struct_utils.h"

struct point_t {
    int x;
    int y;
};


int main() {

    char path[31];
    if (read_std_input(path)) {
        printf("Incorrect input");
        return 1;
    }
    clean_std_input();

    struct point_t my_point;

    return 0;
}
