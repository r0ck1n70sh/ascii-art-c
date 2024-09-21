#ifndef BUFFER_UTIL_H
#define BUFFER_UTIL_H


/*
    here, we've considered origin as
    end of beginning ascii art character

    also, number line is moving from
    left (-ve) to right (+ve)
*/
int* calculate_begin_dist_arr (char**, int);

int* calculate_end_dist_arr (char**, int);

/*
    here, we're using shift origin and valid overlap
    algorithm, i.e. we'll merge two ascii art characters
    until there is valid overlap
*/
int calculate_optimal_merge_dist (int*, int*);


void append_ascii_buffer_str (char**, int, char**, int);

#endif