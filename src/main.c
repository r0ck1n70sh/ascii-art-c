#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <io_util.h>


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
