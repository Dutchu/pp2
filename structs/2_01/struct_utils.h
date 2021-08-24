//
// Created by blaszba2 on 8/23/2021.
//

#ifndef STRUCTS_STRUCT_UTILS_H
#define STRUCTS_STRUCT_UTILS_H



/* -- STRUCTS -- */

struct point_t {
    int x;
    int y;
};

void show(const struct point_t* p);
struct point_t* set(struct point_t* p, int x, int y);
int save_point_b(const char *filename, const struct point_t* p);
int load_point_b(const char *filename, struct point_t* p);
int save_point_t(const char *filename, const struct point_t* p);
int load_point_t(const char *filename, struct point_t* p);


int read_std_input(char *path);
void clean_std_input(void);

#endif //STRUCTS_STRUCT_UTILS_H
