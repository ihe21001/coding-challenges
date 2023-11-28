#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_nth_term(int n, int a, int b, int c) {
  if (n==1) return a;
  if (n==2) return b;
  if (n==3) return c;
  
  return find_nth_term(n-1, b, c, a+b+c);;
  
}

int main() {
    int n, a, b, c;

      // Instructions for the user
    printf("Enter four integers: \n");
    printf("1st integer (n): Position of the term in the sequence to find.\n");
    printf("2nd to 4th integers (a, b, c): The first three terms of the sequence.\n");
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("The %dth term in the sequence is: %d\n", n, ans);
    return 0;
}
