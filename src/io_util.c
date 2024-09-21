#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <constants.h>
#include <io_util.h>

char** initialize_buffer () {
    char** buffer = malloc(ASCII_ART_CHAR_HEIGHT * sizeof(char *));
    
    for (int i = 0; i < ASCII_ART_CHAR_HEIGHT; i++) {
        char* line = malloc(ASCII_ART_CHAR_WIDTH * sizeof(char));
        memset(line, 0, ASCII_ART_CHAR_WIDTH * sizeof(char));

        buffer[i] = line;
    }
    
    return buffer;
}


char** read_ascii_char (int ascii_key) {
    char file_path [15];
    sprintf(file_path, "ascii/%d.txt", ascii_key);

    FILE* file_ptr = fopen(file_path, "r");

    char** buffer = initialize_buffer();

    char curr_ch;
    int i = 0, j = 0;

    while (i < ASCII_ART_CHAR_HEIGHT && j < ASCII_ART_CHAR_WIDTH) {
        curr_ch = fgetc(file_ptr);

        if (curr_ch == EOF) {
            break;
        }

        if (curr_ch == '\n') {
            i++;
            j = 0;
            continue;
        }

        buffer[i][j] = curr_ch;
        j++;
    }

    return buffer;
}
