#include "common.h"
#include <stdio.h>
#include <stdlib.h>

int line_count(const char *path)
{
    FILE *file = fopen(path, "r");
    char c;
    int count = 1;

    while (!feof(file))
    {
        c = fgetc(file);
        if (c == '\n')
        {
            count++;
        }
    }
    fclose(file);

    return count;
}

void read_long_array(const char *path, long *data)
{
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t line_length;
    ssize_t read;
    int i = 0;

    while ((read = getline(&line, &line_length, file)) != -1)
    {
        data[i] = strtol(line, NULL, 10);
        i++;
    }
    if (line)
    {
        free(line);
    }
    fclose(file);
}

void bubblesort(long *data, int length) {
    int unsorted = 1;
    while (unsorted > 0) {
        unsorted = 0;
        for (int i = 0; i < length - 1; i++) {
            if (data[i] > data[i + 1]) {
                long tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
                unsorted++;
            }
        }
    }
}