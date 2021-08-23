#include <stdio.h>
#include <stdlib.h>


struct array_t {
    int size;
    int array[100];
};

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

int read_std_input(char *path) {
    if (scanf("%30s", path) == 0){
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

int main() {

//    char *path = "c:\\temp\\coded.bin";
//    char *path = "array.bin";
    char path[31];
    printf("Podaj sciezke do pliku:\n");

    if (read_std_input(path)){
        printf("Incorrect input");
        return 1;
    }
    clean_std_input();

    struct array_t arr_out;

    /*  -- READ -- */
    switch (load_array_b(path, &arr_out)) {
        case 1:
        case 2:
            printf("Couldn't open file");
            return 4;
        case 3:
            printf("File corrupted");
            return 6;
    }
//    arrayToString(arr_out);

    if (sort(&arr_out)) {
        printf("Incorrect input data");
        return 2;
    }

    /*  -- WRITE -- */
    switch (save_array_b(path, &arr_out)) {
        case 1:
        case 2:
        case 3:
            printf("Couldn't create file");
            return 5;
    }


    printf("File saved");
    return 0;
}
