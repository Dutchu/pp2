//
// Created by blaszba2 on 8/24/2021.
//

#ifndef STRUCTS_COLOR_H
#define STRUCTS_COLOR_H

enum colors {
    RED = 1,
    GREEN,
    BLUE,
    YELLOW,
    UNKNOWN
};
struct color_t {
    float r;
    float g;
    float b;
    enum colors c;
};

int load_colors_t(const char *filename, struct color_t* p, int N);
enum colors find_nearest_neighbour(const struct color_t* database, int size, const struct color_t* unknown, int *err_code);
float distance(const struct color_t* p1, const struct color_t* p2, int *err_code);

int read_std_input(char *path);
void clean_std_input(void);

#endif //STRUCTS_COLOR_H
