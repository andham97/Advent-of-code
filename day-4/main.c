#include "../common.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char *byr;
    char *iyr;
    char *eyr;
    char *hgt;
    char *hcl;
    char *ecl;
    char *pid;
    char *cid;
} passport_t;

void read_to_character(char **data, char **target, char end)
{
    int count = 0;
    int length = strlen(*data);
    for (int i = 0; i < length; i++)
    {
        if ((*data)[i] == end || (*data)[i] == '\n')
        {
            break;
        }
        count++;
    }

    *target = malloc(count * sizeof(char));

    for (int i = 0; i < count; i++)
    {
        (*target)[i] = (*data)[i];
    }

    *data += count + 1;
}

void parse_passport_line(passport_t *passport, char *data)
{
    char *cursor = data;
    char *key = NULL;
    char *value = NULL;
    while ((cursor - data) < strlen(data))
    {
        read_to_character(&cursor, &key, ':');
        read_to_character(&cursor, &value, ' ');
        if (memcmp(key, "byr", 3) == 0)
        {
            passport->byr = value;
        }
        else if (memcmp(key, "iyr", 3) == 0)
        {
            passport->iyr = value;
        }
        else if (memcmp(key, "eyr", 3) == 0)
        {
            passport->eyr = value;
        }
        else if (memcmp(key, "hgt", 3) == 0)
        {
            passport->hgt = value;
        }
        else if (memcmp(key, "hcl", 3) == 0)
        {
            passport->hcl = value;
        }
        else if (memcmp(key, "ecl", 3) == 0)
        {
            passport->ecl = value;
        }
        else if (memcmp(key, "pid", 3) == 0)
        {
            passport->pid = value;
        }
        else if (memcmp(key, "cid", 3) == 0)
        {
            passport->cid = value;
        }
        printf("KEY=%s;VALUE=%s;\n", key, value);
        free(key);
        value = NULL;
    }
}

void parse_passport(passport_t *passport, char **data, int length)
{
}

void free_passport_data(passport_t *passport)
{
    if (passport->byr)
    {
        free(passport->byr);
    }
    if (passport->iyr)
    {
        free(passport->iyr);
    }
    if (passport->eyr)
    {
        free(passport->eyr);
    }
    if (passport->hgt)
    {
        free(passport->hgt);
    }
    if (passport->hcl)
    {
        free(passport->hcl);
    }
    if (passport->ecl)
    {
        free(passport->ecl);
    }
    if (passport->pid)
    {
        free(passport->pid);
    }
    if (passport->cid)
    {
        free(passport->cid);
    }
}

int main()
{
    const char *path = "./input.txt";
    int file_length = line_count(path);
    char **data = calloc(file_length, sizeof(char *));
    read_string_array(path, data);
    passport_t *pass = calloc(1, sizeof(passport_t));
    parse_passport_line(pass, data[0]);
    free_passport_data(pass);
    printf(";%s;%i", data[2], strcmp(data[2], "\n"));
    free(pass);
    free_string_array(data, file_length);
    free(data);
    return 0;
}
