#ifndef IO_H
#define IO_H

#include <stdint.h>

int line_count(const char *path);
void read_long_array(const char *path, long *data);

#endif