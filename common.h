#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

int line_count(const char *path);
void read_long_array(const char *path, long *data);
void bubblesort(long *data, int length);

#endif