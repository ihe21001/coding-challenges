#include <stdio.h>

int searchList(const char listone[],const char listtwo[],char c, int array_length){

    for (int i = 0; i < array_length; i++)
    {   
        if (listone[i] == c || listtwo[i] == c)
        {
            return i;
        }
        
    }

    return -1;
}

int main(){
    const char letters_original_small[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    const char letters_original_big[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    const char* letters_new[26] = {"@","8","(","|)","3","#","6","[-]","|","_|","|<","1","[]\\/[]","[]\\[]","0","|D","(,)","|Z","$","']['","|_|","\\/","\\/\\/","}{","`/","2"};

    char c;
    int i;
    int array_length = sizeof(letters_original_small)/sizeof(char);
    //printf("array length: %d \n \n",array_length);

    while (1)
    {
        c = getchar();
        if (c=='\n'){
            return 0;
        }
        
        i = searchList(letters_original_small, letters_original_big, c, array_length);
        if (i!=-1)
        {
            printf("%s", letters_new[i]);
        }
        else putchar(c);
    }
    return(0);
}
