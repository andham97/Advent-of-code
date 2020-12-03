#include "../common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int64_t simple_tree_count(char **data, int length, int dx, int dy)
{
    int line_length = strlen(data[0]) - 1; // Remove new-line character from count
    int x = dx, y = dy;
    int64_t count = 0;
    while (y < length)
    {
        if (data[y][x % line_length] == '#')
        {
            count++;
        }
        x += dx;
        y += dy;
    }
    return count;
}

int main()
{
    const char *path = "./input.txt";
    int file_length = line_count(path);
    char **data = calloc(file_length, sizeof(char *));
    read_string_array(path, data);
    int64_t trees_1_1 = simple_tree_count(data, file_length, 1, 1);
    int64_t trees_1_2 = simple_tree_count(data, file_length, 1, 2);
    int64_t trees_3_1 = simple_tree_count(data, file_length, 3, 1);
    int64_t trees_5_1 = simple_tree_count(data, file_length, 5, 1);
    int64_t trees_7_1 = simple_tree_count(data, file_length, 7, 1);

    int64_t multiple_count = trees_1_1 * trees_1_2 * trees_3_1 * trees_5_1 * trees_7_1;

    printf("Tree count basic slope: %lli\n", trees_3_1);
    printf("All sclope multiplication count: %lli\n", multiple_count);

    free_string_array(data, file_length);
    free(data);
    return 0;
}