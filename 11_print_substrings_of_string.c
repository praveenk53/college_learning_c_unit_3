// print all substrings of a given string

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int n, i, j;
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    n = strlen(str);
    
    printf("\nAll substrings of the string are:\n");
    
    // Outer loop for starting position
    for (i = 0; i < n; i++) {
        // Inner loop for ending position
        for (j = i; j < n; j++) {
            // Print substring from i to j
            for (int k = i; k <= j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
    
    return 0;
}