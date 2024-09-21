#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <constants.h>
#include <io_util.h>
#include <buffer_util.h>


char** initialize_ascii_buffer(int);
void write_ascii_buffer_str(char**, char*);
void print_ascii_buffer_str(char**);


int main() {
    char* input_str;
    int input_str_len;

    char** buffer;

    while(TRUE_VAL) {
        input_str = (char*) malloc(INPUT_MAX_STR_LEN * sizeof(char));

        printf("Enter any value (length < %d):\n", INPUT_MAX_STR_LEN);
        scanf("%s", input_str);

        input_str_len = strlen(input_str);
        if (input_str_len > INPUT_MAX_STR_LEN) {
            printf(
                "Invalid input! length must be less than %d\n",
                INPUT_MAX_STR_LEN);

            continue;
        }

        buffer = initialize_ascii_buffer(input_str_len + INPUT_MIN_STR_LEN);
        write_ascii_buffer_str(buffer, input_str);
        print_ascii_buffer_str(buffer);
    }
}

char** initialize_ascii_buffer(int buffer_length) {
    int i;
    char** buffer = (char**) malloc(buffer_length * sizeof(char*));
    for(i = 0; i < ASCII_ART_CHAR_HEIGHT; i++) {
        buffer[i] = (char*) malloc(buffer_length * ASCII_ART_CHAR_WIDTH * sizeof(char));
        memset(buffer[i], SPACE_CHAR, buffer_length * ASCII_ART_CHAR_WIDTH * sizeof(char));
    }

    return buffer;
}

void write_ascii_buffer_str(char** buffer, char* input_str) {
    int idx, ch, origin = 0, buffer_len = 0;
    char** ascii_str;

    int* begin_dist_arr;
    int* end_dist_arr;

    for (idx = 0; idx < strlen(input_str); idx++) {
        ch = input_str[idx];
        ascii_str = read_ascii_char(ch);

        begin_dist_arr =
            calculate_begin_dist_arr(ascii_str, ASCII_ART_CHAR_WIDTH);

        end_dist_arr = calculate_end_dist_arr(buffer, buffer_len);

        origin = calculate_optimal_merge_dist(end_dist_arr, begin_dist_arr);

        append_ascii_buffer_str(buffer, buffer_len, ascii_str, origin);

        buffer_len += ASCII_ART_CHAR_WIDTH + origin;
    }
}


void print_ascii_buffer_str(char** buffer) {
    int i;
    for (i = 0; i < ASCII_ART_CHAR_HEIGHT; i++) {
        printf("%s\n", buffer[i]);
    }
}
