//
// Created by blaszba2 on 8/29/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

int load_data(struct message_t *cp, int size, const char *filename) {
    if (size <= 0 || cp == NULL || filename == NULL) {
        return -1;
    }
    FILE *p_file;
    p_file = fopen(filename, "rb");
    if (p_file == NULL) {
        return -2;
    }
    if (file_size_from_file(p_file) == 0) {
        fclose(p_file);
        return -3;
    }
    unsigned int data;
    int el = 0;
    for (int i = 0; i < size; ++i) {

        fread(&data, sizeof(unsigned int), 1, p_file);
        data *= 8;
        if (data % 24 != 0 || data < 24) {
            fclose(p_file);
            return -3;
        }
        for (int j = 0; j < (int) (data / 24); ++j) {
            if (el >= size) break;
            if (fread((cp + i++), sizeof(struct message_t), 1, p_file) != 1) {
                if (feof(p_file) != 0) {
                    fclose(p_file);
                    return el;
                }
                fclose(p_file);
                return -3;
            } else {
                el++;
            }
        }
    }
    fclose(p_file);
    return el;
}

int decode_message(const struct message_t *cp, int size, char *msg, int text_size) {
    if (cp == NULL || size <= 0 || msg == NULL || text_size <= 0) return 1;

    for (int i = 0; i < size; ++i) {
        unsigned char dst[24];
        memcpy(dst, (cp + i), 24);

        for (int j = 1; j <= 7; ++j) {
            if (text_size <= 1) {
                *msg = '\0';
                return 0;
            }
            *msg++ = (char) *(dst + j);
            text_size--;

        }
        for (int j = 20; j <= 23; ++j) {
            if (text_size <= 1) {
                *msg = '\0';
                return 0;
            }
            *msg++ = (char) *(dst + j);
            text_size--;

        }
    }
    return 0;
}

int read_filename(char *path) {
    int c;
    int count = 0;
    while ((c = getchar()) != EOF && c != '\n' && count < 30) {
        *(path + count) = (char) c;
        count = count + 1;
    }
    return count;
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