#include "../common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    long min_count;
    long max_count;
    char character;
} pwd_rule_t;

char *parse_rule(pwd_rule_t *rule, char *text)
{
    char *end;
    rule->min_count = strtol(text, &end, 10);
    rule->max_count = strtol(end + 1, &end, 10);
    rule->character = *(end + 1);
    return end + 4;
}

void find_valid_pwd_count(char **lines, int pwd_count, int *old_count, int *new_count)
{
    pwd_rule_t rule;
    *old_count = 0;
    for (int i = 0; i < pwd_count; i++)
    {
        if (lines[i])
        {
            char *text = parse_rule(&rule, lines[i]);
            int count = array_occurences((void **)&text, (void *)&rule.character, strlen(text), sizeof(char));
            if (count >= rule.min_count && count <= rule.max_count)
            {
                (*old_count)++;
            }
            if (text[rule.min_count - 1] != text[rule.max_count - 1] && (text[rule.min_count - 1] == rule.character || text[rule.max_count - 1] == rule.character))
            {
                (*new_count)++;
            }
        }
    }
}

int main()
{
    const char *path = "./input.txt";
    int pwd_count = line_count(path);
    char **lines = calloc(pwd_count, sizeof(char *));
    read_string_array(path, lines);

    int old_valid_pwds, valid_pwds;
    find_valid_pwd_count(lines, pwd_count, &old_valid_pwds, &valid_pwds);
    printf("Valid passwords old policy: %i\n", old_valid_pwds);
    printf("Valid passwords new policy: %i\n", valid_pwds);

    free_string_array(lines, pwd_count);
    free(lines);
    return 0;
}