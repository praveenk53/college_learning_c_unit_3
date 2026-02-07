// check whether a string is a valid identifier in c 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, valid = 1;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    // Check if string is empty
    if (strlen(str) == 0) {
        printf("Invalid identifier: Empty string\n");
        return 0;
    }
    
    // First character must be letter or underscore
    if (!isalpha(str[0]) && str[0] != '_') {
        valid = 0;
    }
    
    // Remaining characters must be letters, digits, or underscore
    for (i = 1; str[i] != '\0' && valid; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            valid = 0;
        }
    }
    
    if (valid) {
        printf("\"%s\" is a valid identifier\n", str);
    } else {
        printf("\"%s\" is NOT a valid identifier\n", str);
    }
    
    return 0;
}