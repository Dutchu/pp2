//
// Created by blaszba2 on 8/23/2021.
//
#include "library.h"
#include <stdio.h>
#include <stdlib.h>

/* -- POINTS --*/

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
    if (filename == NULL || p == NULL) {
        return 1;
    }

    FILE *p_file = fopen(filename, "wb");
    if (p_file == NULL) {
        return 2;
    }

    size_t elements_written = fwrite(p, sizeof(struct point_t), 1, p_file);
    fclose(p_file);
    if (elements_written == 0) {
        return 3;
    }

    return 0;
}
int load_point_b(const char *filename, struct point_t *p) {
    if (filename == NULL || p == NULL) {
        return 1;
    }

    FILE *p_file = fopen(filename, "rb");
    if (p_file == NULL) {
        return 2;
    }

    size_t elements_written = fread(p, sizeof(struct point_t), 1, p_file);
    fclose(p_file);
    if (elements_written == 0) {
        return 3;
    }

    return 0;
}

int save_point_t(const char *filename, const struct point_t *p) {
    if (filename == NULL || p == NULL) {
        return 1;
    }

    FILE *p_file;
    p_file = fopen(filename, "w");
    if (p_file == NULL) {
        return 2;
    }

    if (fprintf(p_file, "%d %d", p->x, p->y) < 1) {
        fclose(p_file);
        return 3;
    }
    fclose(p_file);
    return 0;
}

int load_point_t(const char *filename, struct point_t *p) {
    if (filename == NULL || p == NULL) {
        return 1;
    }
    FILE *p_file;
    p_file = fopen(filename, "r");
    if (p_file == NULL) {
        return 2;
    }

    if (fscanf(p_file, "%d %d", &p->x, &p->y) != 2) {
        fclose(p_file);
        return 3;
    }
    fclose(p_file);
    return 0;
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

int serialize_point(struct point_t *p, char *string) {
    if (p == NULL || string == NULL) {
        return 1;
    }

    sprintf(string, "%d %d", p->x, p->y);

    return 0;
}

/* -- ARRAYS --*/

int save_array_b(const char *filename, const struct array_t *arr) {
    if (filename == NULL || arr == NULL) {
        return 1;
    }

    FILE *p_file = fopen(filename, "wb");
    if (p_file == NULL) {
        return 2;
    }

    size_t elements_written = fwrite(arr, sizeof(struct array_t), 1, p_file);
    fclose(p_file);
    if (elements_written == 0) {
        return 3;
    }

    return 0;
}

int load_array_b(const char *filename, struct array_t *arr) {

    if (filename == NULL || arr == NULL) {
        return 1;
    }

    FILE *p_file = fopen(filename, "rb");
    if (p_file == NULL) {
        return 2;
    }

    size_t elements_written = fread(arr, sizeof(struct array_t), 1, p_file);
    fclose(p_file);
    if (elements_written == 0) {
        return 3;
    }

    return 0;
}