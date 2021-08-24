
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "struct_utils.h"

int if_file_exists(char *filename) {
    FILE *f;
    f = fopen(filename, "r");
    if (f == NULL) {
        return 1;
    }
    fclose(f);
    return 0;
}

int f_type_check(char *filename) {
    char *dot = strrchr(filename, '.');
    if (dot != NULL && strcmp(dot, ".bin") == 0) {
        return 1;
    }
    if (dot != NULL && strcmp(dot, ".txt") == 0) {
        return 2;
    }
    return 7;
}


int main() {

    srand(time(NULL));
    struct point_t my_point;
    int x = rand() % 50;
    int y = rand() % 50;
    set(&my_point, x, y);
    show(&my_point);

    char path[31];
    printf("Podaj sciezke do pliku:\n");
    if (read_std_input(path)) {
        printf("Incorrect input");
        return 1;
    }
    clean_std_input();

    int error_code;
    int f_type = 0;
    switch (f_type_check(path)) {
        case 1:
            f_type = 1;
            error_code = save_point_b(path, &my_point);
            if (error_code == 2 || error_code == 3) {
                printf("Couldn't create file");
                return 5;
            }
            break;
        case 2:
            f_type = 2;
            error_code = save_point_t(path, &my_point);
            if (error_code == 2 || error_code == 3) {
                printf("Couldn't create file");
                return 5;
            }
            break;
        case 7:
            printf("Unsupported file format");
            return 7;
    }

    if (if_file_exists(path)) {
        printf("Couldn't open file");
        return 5;
    }
    printf("File saved\n");


    printf("Do you want to read the file (Y/N)?\n");
    char respond;
    scanf("%1ch", &respond);
    clean_std_input();
    if (respond == 'n' || respond == 'N') {
        return 0;
    } else if (respond == 'y' || respond == 'Y') {

        if (f_type == 2) {
            error_code = load_point_t(path, &my_point);
        }
        if (f_type == 1) {
            error_code = load_point_b(path, &my_point);
        }
        if (error_code == 3) {
            printf("File corrupted");
            return 6;
        }
        if (error_code == 2) {
            printf("Couldn't open file");
            return 4;
        }
        show(&my_point);
    } else {
        printf("incorrect input");
        return 1;
    }

    return 0;
}
