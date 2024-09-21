#include <stdlib.h>
#include <buffer_util.h>
#include <constants.h>


int* initialize_dist_arr (int);


int* calculate_begin_dist_arr (
    char** ascii_buffer_str,
    int ascii_buffer_str_len) {

    int* dist_arr = initialize_dist_arr(ASCII_ART_CHAR_WIDTH);

    int i, j;
    char curr;
    for (i = 0; i < ASCII_ART_CHAR_HEIGHT; i++) {
        for (j = 0; j < ascii_buffer_str_len; j++) {
            curr = ascii_buffer_str[i][j];
            if (curr == SPACE_CHAR) continue;

            dist_arr[i] = j;
            break;
        }
    }

    return dist_arr;
}

int* calculate_end_dist_arr (
    char** ascii_buffer_str,
    int ascii_buffer_str_len) {
        
    int* dist_arr = initialize_dist_arr(-ASCII_ART_CHAR_WIDTH);

    int i, j;
    char curr;
    for (i = 0; i < ASCII_ART_CHAR_HEIGHT; i++) {
        for (j = ascii_buffer_str_len - 1; j >= 0; j--) {
            curr = ascii_buffer_str[i][j];
            if (curr == SPACE_CHAR || curr == END_OF_STR_CHAR) continue;

            dist_arr[i] = j - ascii_buffer_str_len + 1;
            break;
        } 
    }

    return dist_arr;
}

int calculate_optimal_merge_dist (
    int* end_dist_arr,
    int* begin_dist_arr) {

    int start_o = 0;
    int i, curr;

    for (i = 0; i < ASCII_ART_CHAR_HEIGHT; i++) {
        curr = end_dist_arr[i];
        if (curr <= -ASCII_ART_CHAR_WIDTH || curr > start_o) {
            continue;
        }

        start_o = curr;
    }
    
    int o, is_overlapping, curr_end_dist, curr_begin_dist;
    for (o = start_o; o <= 0; o++) {
        is_overlapping = 0;
        for (i = 0; i < ASCII_ART_CHAR_HEIGHT; i++) {
            curr_begin_dist = begin_dist_arr[i] + o;
            curr_end_dist = end_dist_arr[i];

            if (curr_end_dist > curr_begin_dist) {
                is_overlapping = 1;
            }
        }

        if (is_overlapping == 0) {
            break;
        }
    }

    return o;
}

void append_ascii_buffer_str (
    char** end_ascii_buffer_str,
    int end_ascii_buffer_str_len,
    char** begin_ascii_buffer_str,
    int append_origin) {

    int i, idx;
    /*
        here, '-1' in offset, accounts for '\0' char;
    */
    int offset = end_ascii_buffer_str_len + append_origin - 1;
    char curr, prev;

    if (offset < 0) offset = 0;

    for (i = 0; i < ASCII_ART_CHAR_HEIGHT; i++) {
        for (idx = 0; idx < ASCII_ART_CHAR_WIDTH; idx++) {
            curr = begin_ascii_buffer_str[i][idx];
            prev = end_ascii_buffer_str[i][offset + idx];

            if (curr == SPACE_CHAR && prev != END_OF_STR_CHAR) {
                continue;
            }

            end_ascii_buffer_str[i][offset + idx] = curr;
        }
    }
}

int* initialize_dist_arr (int default_dist) {
    int* dist_arr = (int*) malloc(ASCII_ART_CHAR_HEIGHT * sizeof(int));

    int i;
    for (i = 0; i < ASCII_ART_CHAR_HEIGHT; i++) {
        dist_arr[i] = default_dist;
    }

    return dist_arr;
}
