//
// Created by blaszba2 on 8/24/2021.
//
#include "color.h"
#include <stdio.h>
#include <math.h>

int load_colors_t(const char *filename, struct color_t *p, int N) {
    if (filename == NULL || p == NULL || N <= 0) {
        return -1;
    }

    FILE *p_file;
    if ((p_file = fopen(filename, "r")) == NULL) {
        return -2;
    }

    while (!feof(p_file)) {
        int c = fgetc(p_file);
        if ((c < '0' || c > '9') && c != '.' && c != EOF && c != ' ' && c != '\n') {
            fclose(p_file);
            return -3;
        }
    }

    fseek(p_file, 0, SEEK_SET);

    int i = 0;
    int my_colour;
    while (i < N && fscanf(p_file, "%f %f %f %d", &(p + i)->r, &(p + i)->g, &(p + i)->b, &my_colour) == 4) {
        (p + i)->c = my_colour;
        i++;
    }

    fclose(p_file);

    return i == 0 ? -3 : i;
}

float distance(const struct color_t* p1, const struct color_t* p2, int *err_code)
{
    if (err_code != NULL)
        *err_code = 0;

    if (p1 == NULL || p2 == NULL)
    {
        if (err_code != NULL)
            *err_code = 1;
        return -1;
    }
    return sqrtf( (p1->r - p2->r) * (p1->r - p2->r) +
                 (p1->g - p2->g) * (p1->g - p2->g) +
                 (p1->b - p2->b) * (p1->b - p2->b));
}

enum colors find_nearest_neighbour(const struct color_t* database, int size, const struct color_t* unknown, int *err_code)
{
    if (database == NULL || unknown == NULL || size <= 0)
    {
        if (err_code != NULL)
            *err_code = 1;
        return UNKNOWN;
    }

    float lowest_distance = distance(database, unknown, err_code);
    struct color_t my_color = *database;

    if (err_code != NULL)
        *err_code = 0;

    for (int i = 1; i < size; ++i)
    {
        float gap = distance(database + i, unknown, err_code);
        if (gap < lowest_distance)
        {
            if (err_code != NULL)
                *err_code = 0;
            lowest_distance = gap;
            my_color = *(database + i);
        }
        else if (gap == lowest_distance && my_color.c != (database + i)->c)
        {
            if (err_code != NULL)
                *err_code = 2;
            my_color.c = UNKNOWN;
        }

    }
    return my_color.c;
}


int read_std_input(char *path) {
    if (scanf("%30s", path) < 1) {
        return 1;
    }
    return 0;
}

void clean_std_input(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

