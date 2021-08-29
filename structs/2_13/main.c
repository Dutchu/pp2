#include <stdio.h>
#include "utils.h"

int main() {
    struct message_t msg_t[100];
    printf("Podaj sciezke do pliku:\n");
    char path[31];
    read_filename(path);

    int rc = load_data(msg_t, 100, path);
    if (rc == -2) {
        printf("Couldn't open file");
        return 4;
    }
    if (rc == -3) {
        printf("File corrupted");
        return 6;
    }
    char msg[1101];
    decode_message(msg_t, rc, msg, 1101);
    printf("%s", msg);
    return 0;

}

