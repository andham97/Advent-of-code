#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

int line_count(const char *path);
void read_long_array(const char *path, long *data);
void read_string_array(const char *path, char **lines);
void bubblesort(long *data, int length);
void free_string_array(char **lines, int length);
int array_occurences(void **data, void *value, int length, int width);

#endif