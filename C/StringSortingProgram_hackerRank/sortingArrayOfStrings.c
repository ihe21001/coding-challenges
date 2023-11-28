#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    if (strcmp(a, b) > 0) return 1;
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    if (strcmp(a, b) < 0) return 1;
    return 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    //
    int char_set [128]= {0};
    for (int i=0; i<strlen(a); i++) {
        char_set[a[i]]=1;
    }
    int char_a=0;
    for (int i = 0; i<128; i++) {
        char_a += char_set[i];
    }
    
    memset(char_set, 0, sizeof(char_set)); // Reset the char_set for next string
    for (int i=0; i<strlen(b); i++) {
        char_set[b[i]]=1;
    }
    int char_b=0;
    for (int i = 0; i<128; i++) {
        char_b += char_set[i];
    }
    
    if (char_a > char_b) return 1;
    if (char_a == char_b) return lexicographic_sort(a,b);
    
    return 0;
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a)>strlen(b)) return 1;
    
    if (strlen(a)==strlen(b)) return lexicographic_sort(a,b);
    
    return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for (int i = 0; i<len-1; i++) {
        for (int j = 0; j<len-1; j++) {
            if (cmp_func(arr[j],arr[j+1])){
                char *temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}


int main() 
{
    printf("Enter the number of strings in array: ");
    int n;
    scanf("%d", &n);

    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
    
    printf("Enter the string: ");
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
    
    printf("\nSorting in lexicographic order:\n");
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s ", arr[i]);
    printf("\n");

    printf("Sorting in reverse lexicographic order:\n");
    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s ", arr[i]); 
    printf("\n");

    printf("Sorting by length:\n");
    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s ", arr[i]);    
    printf("\n");

    printf("Sorting by number of distinct characters:\n");
    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s ", arr[i]); 
    printf("\n");
}