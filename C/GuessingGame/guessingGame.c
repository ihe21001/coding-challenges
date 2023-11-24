/*
TASK:
Stan thinks about number betwenn 1 and 10
Ollie guesses the number
Stan tells Ollie if the number is to high, to low or on pint.

Find out if Stan is cheating
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 0

int main(){
    int current_min_value=1, current_max_value=10, value;
    char line[20],value_str[20];

    while (1)
    {
        fgets(value_str, sizeof(value_str), stdin);
        value = atoi(value_str);

        
        if (DEBUG) printf("%d\n",value);

        if (value == 0) return 0;
        
        fgets(line, sizeof(line), stdin);
        if (DEBUG) printf("%s\n",line);

        if (strncmp(line, "too high",8) == 0)
        {
            if (DEBUG) printf("case: high\n");
            if (current_max_value>=value-1) current_max_value = value-1;
        }
        else if (strncmp(line, "too low",7) == 0)
        {
            if (DEBUG) printf("case: low\n");
            if (current_min_value<=value+1) current_min_value = value+1;
        }
        else if (strncmp(line, "right on", 8) == 0)
        {
            if (DEBUG) printf("case: right\n");
            if (value < current_min_value || value>current_max_value)
            {
                printf("Stan is dishonest\n");
            }
            else printf("Stan may be honest\n");
            current_min_value=1; 
            current_max_value=10;
        }
        else return 0;
    }
}