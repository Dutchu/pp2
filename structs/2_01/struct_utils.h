//
// Created by blaszba2 on 8/23/2021.
//

#ifndef STRUCTS_STRUCT_UTILS_H
#define STRUCTS_STRUCT_UTILS_H

#include "main.c"

/* -- STRUCTS -- */
//ZAD 10
struct array_t {
    int size;
    int array[100];
};

/* -- ZAD 01 -- */
void show(const struct point_t* p);
struct point_t* set(struct point_t* p, int x, int y);
int save_point_b(const char *filename, const struct point_t* p);
int load_point_b(const char *filename, struct point_t* p);
int save_point_t(const char *filename, const struct point_t* p);
int load_point_t(const char *filename, struct point_t* p);
/* -- ZAD 10 -- */
int read_std_input(char *path);
void clean_std_input(void);
int compare(const void *a, const void *b);
int sort(struct array_t *arr);
#endif //STRUCTS_STRUCT_UTILS_H
