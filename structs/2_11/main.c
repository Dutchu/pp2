#include <stdio.h>
#include "utils.h"
#include <string.h>


int main() {

    struct file_t files[5];
    printf("Podaj sciezke do pliku:\n");

    int opened_f = 0;
    while (opened_f <= 5) {
        char path[31] = {0};
        read_std_input(path);
        if (*path == 0) {
            break;
        }
        switch (open_file((files + opened_f), path)) {
            case 1:
            case 2:
                break;
            default:
                opened_f += 1;
        }
    }
    if (opened_f == 0) {
        printf("Couldn't open file\n");
        return 4;
    }


    while (1) {
        int contents_size;
        char contents[999] = {0};
        printf("Please enter contents:\n");
        contents_size = read_std_to_file(contents);
        printf("Contents size: %d\n", contents_size);
        if (*contents == '\n') {
            break;
        }

        struct file_t *min_file = find_min(files, opened_f);
        fwrite(contents, sizeof(char), strlen(contents), (FILE *) min_file->f);
        min_file->size = file_size_from_file((FILE *) min_file->f);
    }

    for (int i = 0; i < opened_f; ++i) {
        close_file((files + i));
    }

    printf("Files saved\n");
    return 0;
}

