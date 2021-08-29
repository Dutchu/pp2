//
// Created by blaszba2 on 8/25/2021.
//
#include <stdio.h>
#include <limits.h>
#include "utils.h"

int open_file(struct file_t *f, const char *filename) {
    if (filename == NULL || f == NULL) {
        return 1;
    }

    FILE *p_file;
    p_file = fopen(filename, "a");
    if (p_file == NULL) {
        return 2;
    }

    f->size = file_size_from_file(p_file);
    f->f = (FILE **) p_file;

    return 0;
}

struct file_t *find_min(const struct file_t *files, int size) {
    if (files == NULL || size <= 0) {
        return NULL;
    }
    int min_file_size = INT_MAX;
    struct file_t *min_file;
    for (int i = 0; i < size; ++i) {
        if ((files + i)->size < min_file_size) {
            min_file_size = (files + i)->size;
            min_file = (struct file_t *) (files + i);
        }
    }
    return min_file;
}

void close_file(struct file_t *f) {
    if (f == NULL) {
        return;
    } else if (f->f != NULL) {
        fclose((FILE *) f->f);
    }
}

int file_size_from_file(FILE *f) {

    if (f == NULL) {
        return -2;
    }

    long starting_position = ftell(f);

    if (fseek(f, 0L, SEEK_END) != 0) {
        return -1;
    }
    int file_size = ftell(f);

    fseek(f, starting_position, SEEK_SET);

    return file_size;
}

int read_std_input(char *path) {
    int c;
    int count = 0;
    while ((c = getchar()) != EOF && c != '\n' && count < 30) {
        *(path + count) = (char) c;
        count = count + 1;
    }
    return count;
}

int read_std_to_file(char *path) {
    int c;
    int count = 0;
    while ((c = getchar()) != EOF && count < 998) {
        *(path + count) = (char) c;
        if ( c == '\n') {
            break;
        }
        count = count + 1;
    }
    return count;
}


