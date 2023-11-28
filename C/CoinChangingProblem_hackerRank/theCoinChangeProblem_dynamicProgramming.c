#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);
long parse_long(char*);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

 void sort_array(long *a, int len) {
    for (int i = 0; i<len-1; i++) {
        for (int j = 0; j<len-1; j++) {
            if (a[j] > a[j+1]){
                long temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

long long getWays(int n, int m, long *c){
    // Dynamically allocate memory for a 2D matrix
    long long **ways = (long long **)malloc(m * sizeof(long long *));
    if (!ways) return -1;  // or some other error handling
    for (int i=0; i<m; i++) {
        ways[i] = (long long *)malloc((n+1) * sizeof(long long));
        if (!ways[i]) {
            for (int j = 0; j < i; j++) {
                free(ways[j]);
            }
            free(ways);
            return -1;  // or some other error handling
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            if (j==0) ways[i][j] = 1;
            else if (j<c[i])
            {
                if (i==0) ways[i][j] = 0;
                else ways[i][j] = ways[i-1][j];
            }
            else{
                if (i == 0) ways[i][j] = j % c[i] == 0 ? 1 : 0;
                else ways[i][j] = ways[i-1][j] + ways[i][j-c[i]];
            }
            //printf("%d ", ways[i][j]);
        }
        //printf("\n");
    }
    long long result = ways[m-1][n];

    // Clean up dynamically allocated memory
    for (int i = 0; i < m; i++)
        free(ways[i]);
    free(ways);

    return result;
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    printf("Enter the total amount and the number of different coin denominations (separated by a space): ");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int m = parse_int(*(first_multiple_input + 1));

    printf("Enter the values of the %d denominations (separated by space): ", m);

    char** c_temp = split_string(rtrim(readline()));

    long* c = malloc(m * sizeof(long));

    for (int i = 0; i < m; i++) {
        long c_item = parse_long(*(c_temp + i));

        *(c + i) = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long long ways = getWays(n, m, c);

    fprintf(fptr, "%lld\n", ways);

    printf("The number of ways to make change for %d using the given denominations is: %lld\n", n, ways);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

long parse_long(char* str) {
    char* endptr;
    long value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
