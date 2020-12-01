#include "io.h"
#include <stdio.h>
#include <stdlib.h>

int line_count(const char *path)
{
    FILE *file = fopen(path, "r");
    char c;
    int count = 0;

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
    return data;
}