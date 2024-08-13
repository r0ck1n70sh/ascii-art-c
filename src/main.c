#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int CHAR_WIDTH  = 13;
int CHAR_HEIGHT = 6;

char** read_ascii_char (int);
char** initialize_buffer (void);

int main () {
    char input [] = "WALL-E";
    char buffer [6][1000];

    int i;
    for (i = 0; i < CHAR_HEIGHT; i++) {
        memset(buffer[i], 0, 1000 * sizeof(char));
    }

    int idx, ch;
    char** ascii_str;

    for (idx = 0; idx < strlen(input); idx++) {
        ch = input[idx];
        ascii_str = read_ascii_char (ch);

        /*  --  debugging  --
        for (i = 0; i < CHAR_HEIGHT; i++) {
            printf("%s\n", ascii_str[i]);
        } */

        for (i = 0; i < CHAR_HEIGHT; i++) {
            strncat (buffer[i], ascii_str[i], CHAR_WIDTH);
        }
    }

    for (i = 0; i < CHAR_HEIGHT; i++) {
        printf("%s\n", buffer[i]);
    }
}

char** read_ascii_char (int ascii_key) {
    char file_path [15];
    sprintf(file_path, "ascii/%d.txt", ascii_key);

    FILE* file_ptr = fopen(file_path, "r");

    char** buffer = initialize_buffer();

    char curr_ch;
    int i = 0, j = 0;

    while (i < CHAR_HEIGHT && j < CHAR_WIDTH) {
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

char** initialize_buffer () {
    char** buffer = malloc(CHAR_HEIGHT * sizeof(char *));
    
    for (int i = 0; i < CHAR_HEIGHT; i++) {
        char* line = malloc(CHAR_WIDTH * sizeof(char));
        memset(line, 0, CHAR_WIDTH * sizeof(char));

        buffer[i] = line;
    }
    
    return buffer;
}
