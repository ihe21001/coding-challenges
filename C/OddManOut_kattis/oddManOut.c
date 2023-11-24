#include <stdio.h>
#include <stdbool.h>

int main(){
    int N; //number of cases
    int G; //number of guests


    scanf("%d", &N);
    int N_list[N];

    for (size_t i = 0; i < N; i++)
    {
        scanf("%d", &G);

        int C_list[G];
        for (size_t j = 0; j < G; j++)
        {
            scanf("%d", &C_list[j]);
        }

        bool duplicate = false;

        for (size_t m = 0; m < G; m++)
        {   
            bool duplicate = false;
            for (size_t n = 0; n < G; n++)
            {
                if ((n!=m) & (C_list[n]==C_list[m]))
                {
                    duplicate = true;
                }
            }
            if (!duplicate)
            {
                N_list[i]=C_list[m];
                break;
            }
        }
    }

    for (size_t i = 0; i < N; i++) printf("Case #%d: %d\n", i+1,N_list[i]);
}