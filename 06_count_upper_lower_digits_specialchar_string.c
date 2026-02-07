// count number of uppercase , lowercase , digits and special characters in a string
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int uppercase = 0, lowercase = 0, digits = 0, special = 0;
    int i;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    // Count each type of character
    for (i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            uppercase++;
        } else if (islower(str[i])) {
            lowercase++;
        } else if (isdigit(str[i])) {
            digits++;
        } else if (str[i] != ' ') {  // Count non-space special characters
            special++;
        }
    }
    
    printf("\nCharacter Count:\n");
    printf("Uppercase letters: %d\n", uppercase);
    printf("Lowercase letters: %d\n", lowercase);
    printf("Digits: %d\n", digits);
    printf("Special characters: %d\n", special);
    
    return 0;
}