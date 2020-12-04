#!/bin/bash
day=$(ls | grep '^day-[0-9]\+$' | cut -c5- | sort -n | tail -n1 | sed 's|^||')
day=$(echo "$day + 1" | bc -l)
mkdir day-${day}
cp day-3/Makefile day-${day}/Makefile
touch day-${day}/input.txt
echo "#include \"../common.h\"" > day-${day}/main.c
echo "#include <stdlib.h>" >> day-${day}/main.c
echo "#include <stdio.h>" >> day-${day}/main.c
echo "" >> day-${day}/main.c
echo "int main() {" >> day-${day}/main.c
echo "    const char *path = \"./input.txt\";
    int file_length = line_count(path);
    char **data = calloc(file_length, sizeof(char *));
    read_string_array(path, data);
    
    return 0;" >> day-${day}/main.c
echo "}" >> day-${day}/main.c