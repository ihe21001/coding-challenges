#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_words 1000
#define max_word_length 31 // 30 + 1 for null terminator
#define max_variables 2000
#define DEBUGER 0

struct variable{
    char name[max_word_length];
    int value;
};

int searchForStruct_pos(struct variable var[max_variables], char *variable_name , int count_variables){
    for (int i = 0; i < count_variables; i++)
        if (strcmp(var[i].name,variable_name) == 0)return i;
        
    return -1;
}

int checkForValue_pos(struct variable var[max_variables], int value , int count_variables){
    for (int i = 0; i < count_variables; i++)
        if (var[i].value == value) return i;

    return -1;
}

int read_line_and_parse_words(char* words_input[]){
    char line[max_words]; //store input

    if (fgets(line, max_words, stdin) == NULL) return 0; //EOS

    if (line[0] == '\n') return -1; //empty line

    char *newline = strchr(line, '\n');
    if (newline) *newline = '\0';

    int count_words = 0;
    char* token_word = strtok(line," ");

    //if (strncmp(token_word,"calc",4) != 0 && strncmp(token_word,"def",3) != 0 && strncmp(token_word,"clear",5) != 0) return -1;

    while (token_word != NULL)
    {
        words_input[count_words++] = strdup(token_word); // Allocate memory and copy the word
        token_word = strtok(NULL, " "); // next word
    }
    return count_words;
}

int main(){
    char* words_input[max_words];
    int count_words=0, count_variables=0;
    struct variable var[max_variables];

    while ((count_words = read_line_and_parse_words(words_input))!=0)
    {
        if (count_words == -1) continue;

        if (DEBUGER)
        {
            printf("Words in current line: %d\n", count_words); // Print the number of words in the current line

            for (int i = 0; i < count_words; i++) 
                printf("Word %d: %s\n", i + 1, words_input[i]);
        }
        
        if (strcmp(words_input[0], "def") == 0 && count_words==3)
        {
            if (DEBUGER) printf ("start def \n");
            
            if(count_variables >= max_variables) continue;

            if (DEBUGER) printf("amount variables: %d\n",count_variables);
            
            int idx_word = searchForStruct_pos(var, words_input[1], count_variables);
            int idx_value = checkForValue_pos(var, atoi(words_input[2]), count_variables); 

            if (idx_word != -1) {
                for (int i = idx_word; i < count_variables - 1; i++) {
                    var[i] = var[i + 1];
                }
                count_variables--;
            }

            idx_value = checkForValue_pos(var, atoi(words_input[2]), count_variables);

            if (idx_value != -1) {
                for(int i = idx_value; i < count_variables - 1; i++) {
                    var[i] = var[i + 1];
                }
                count_variables--;
            }

            if(count_variables < max_variables) {
                strncpy(var[count_variables].name, words_input[1], max_word_length - 1);
                var[count_variables++].value = atoi(words_input[2]);
            }
        }
        else if ((strcmp(words_input[0], "calc") == 0) && (strcmp(words_input[count_words-1], "=") == 0) && count_words<max_words)
        {   
            int result_status= 1; 
            int result = 0;
            
            for (int i = 1; i < count_words; i+=2)
            {
                int idx_word = searchForStruct_pos(var, words_input[i], count_variables);
                if (idx_word == -1){
                    result_status = 2; // unknown
                    break; 
                }
                
                if (i != 1){ 
                    if (strcmp(words_input[i-1], "+") == 0) {
                        result += var[idx_word].value;
                    } else if (strcmp(words_input[i-1], "-") == 0) {
                        result -= var[idx_word].value;
                    }
                } else { 
                    result = var[idx_word].value;
                }
            }

            
                for (int i = 1; i < count_words; i++)
                {
                   printf("%s ", words_input[i]);
                }

                if (result_status==1) //result
                {
                    int idx_word = checkForValue_pos(var, result, count_variables);
                    if (idx_word == -1){
                        printf("unknown\n");
                    } 
                    else {
                        printf("%s\n",var[idx_word].name);
                    }
                }
                else if (result_status==2) //unknown
                {
                    printf("unknown\n");
                }
            
        }
        else if (strcmp(words_input[0], "clear") == 0 && count_words==1)
        {
            if (DEBUGER) printf ("start clear \n");
            count_variables = 0;
        }
        if(DEBUGER) {
            printf("------var--------\n");
            for (int i = 0; i < count_variables; i++)
                printf("name: %s    value: %d \n",var[i].name,var[i].value);
            printf("-----------------\n");
        }

            // Free the allocated memory
        for (int i = 0; i < count_words; i++) free(words_input[i]);
    }

    return 0;
}