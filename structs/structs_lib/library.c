//
// Created by blaszba2 on 8/23/2021.
//
#include "library.h"
#include <stdio.h>


struct array_t {
    int size;
    int array[100];
};


void show(const struct point_t *p) {
    if (p == NULL) return;
    printf("%d %d", p->x, p->y);
}

struct point_t *set(struct point_t *p, int x, int y) {
    if (p == NULL) return NULL;
    p->x = x;
    p->y = y;
    return p;
}

int save_point_b(const char *filename, const struct point_t *p) {

}

int load_point_b(const char *filename, struct point_t *p) {

}

int save_point_t(const char *filename, const struct point_t *p) {

}

int load_point_t(const char *filename, struct point_t *p) {

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

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int sort(struct array_t *arr) {

    if (arr == NULL || arr->size <= 0 || arr->size > 100) {
        return 1;
    }

    qsort(arr->array, arr->size, sizeof(int), compare);
    return 0;
}