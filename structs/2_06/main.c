#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "color.h"

int main() {
    struct color_t colors[100];

    char path[31];
    printf("Podaj sciezke do pliku:\n");
    if (read_std_input(path)) {
        printf("Incorrect input");
        return 1;
    }
    clean_std_input();

    int number_of_colours = load_colors_t(path, colors, 100);
    switch (number_of_colours) {
        case -2:
            printf("Couldn't open file");
            return 4;
        case -3:
            printf("File corrupted");
            return 6;
    }

    while (1) {
        struct color_t c;

        printf("Podaj skladowe koloru: ");

        if (scanf("%f %f %f", &c.r, &c.g, &c.b) != 3) {
            printf("Incorrect input");
            break;
        }

        int err_code;

        enum colors answer = find_nearest_neighbour(colors, number_of_colours, &c, &err_code);

        switch (answer) {
            case RED:
                printf("RED\n");
                break;

            case GREEN:
                printf("GREEN\n");
                break;

            case BLUE:
                printf("BLUE\n");
                break;

            case YELLOW:
                printf("YELLOW\n");
                break;

            case UNKNOWN:
                printf("UNKNOWN\n");
                break;
        }
    }

    return 0;
}
