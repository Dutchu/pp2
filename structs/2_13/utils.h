//
// Created by blaszba2 on 8/29/2021.
//

#ifndef STRUCTS_UTILS_H
#define STRUCTS_UTILS_H

struct message_t
{
    char a;
    double b;
    int c;
};

int load_data(struct message_t *cp, int size, const char *filename);
int decode_message(const struct message_t *cp, int size, char *msg, int text_size);
int read_filename(char *path);

#endif //STRUCTS_UTILS_H
