#include <stdlib.h>
#include <stdio.h>
#include "../common.h"

long multiple2(long *data, int data_length, long goal, int skip, int *result) {
    int high = data_length - 1;
    int low = 0;
    while (data[low] + data[high] != goal && low < high) {
        if (low == skip) {
            low++;
            continue;
        }
        else if (high == skip) {
            high--;
            continue;
        }
        long sum = data[low] + data[high];
        if (sum > goal) {
            high--;
        }
        else if (sum < goal) {
            low++;
        }
    }
    result[0] = low;
    result[1] = high;
    return data[low] * data[high];
}

long multiple3(long *data, int data_length, long goal, int *result) {
    int tuples[2];
    int i;
    for (i = 0; i < data_length; i++) {
        multiple2(data, data_length, goal - data[i], i, tuples);
        if (tuples[0] != tuples[1]) {
            break;
        }
    }
    result[0] = i;
    result[1] = tuples[0];
    result[2] = tuples[1];
    return data[i] * data[tuples[0]] * data[tuples[1]];
}

void main()
{
    const char const *path = "./input.txt";
    int data_length = line_count(path);
    printf("DL %i\n", data_length);
    long *data = malloc(data_length * sizeof(long));
    read_long_array(path, data);
    bubblesort(data, data_length);

    int tuples[3];
    long m2 = multiple2(data, data_length, 2020, -1, tuples);
    long m3 = multiple3(data, data_length, 2020, tuples);

    printf("Multiple 2 = %ld\n", m2);
    printf("Multiple 3 = %ld\n", m3);
}