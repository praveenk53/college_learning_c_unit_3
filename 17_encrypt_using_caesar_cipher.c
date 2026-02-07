// encrypt a string using Caesar cipher

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    char encrypted[100];
    int shift, i, len;
    char ch;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    
    len = strlen(str);
    
    // Encrypt each character
    for (i = 0; i < len; i++) {
        ch = str[i];
        
        if (isalpha(ch)) {
            if (isupper(ch)) {
                // Shift uppercase letters
                encrypted[i] = ((ch - 'A' + shift) % 26) + 'A';
            } else {
                // Shift lowercase letters
                encrypted[i] = ((ch - 'a' + shift) % 26) + 'a';
            }
        } else {
            // Keep non-alphabetic characters unchanged
            encrypted[i] = ch;
        }
    }
    encrypted[len] = '\0';
    
    printf("\nOriginal string: %s\n", str);
    printf("Encrypted string (shift by %d): %s\n", shift, encrypted);
    
    return 0;
}