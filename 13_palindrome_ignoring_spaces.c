// check whether a string follows palindrome ignoring spaces

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    char cleaned[200];
    int i = 0, j = 0;
    int n, isPalindrome = 1;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    // Remove spaces and convert to lowercase
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            cleaned[j++] = tolower(str[i]);
        }
    }
    cleaned[j] = '\0';
    
    n = strlen(cleaned);
    
    // Check if palindrome
    for (i = 0; i < n / 2; i++) {
        if (cleaned[i] != cleaned[n - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }
    
    if (isPalindrome) {
        printf("\nThe string is a palindrome (ignoring spaces)\n");
    } else {
        printf("\nThe string is NOT a palindrome (ignoring spaces)\n");
    }
    
    printf("Cleaned string: %s\n", cleaned);
    
    return 0;
}