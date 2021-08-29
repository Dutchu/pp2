//
// Created by blaszba2 on 8/25/2021.
//

#ifndef STRUCTS_UTILS_H
#define STRUCTS_UTILS_H

struct file_t
{
    FILE **f;
    int size;
};
int open_file(struct file_t* f, const char *filename);
struct file_t* find_min(const struct file_t* files, int size);
void close_file(struct file_t* f);
int read_std_input(char *path);
int read_std_to_file(char *path);
int file_size_from_file(FILE *f);

#endif //STRUCTS_UTILS_H
