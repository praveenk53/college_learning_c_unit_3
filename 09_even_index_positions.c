// print all characters at even index positions 

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    printf("\nCharacters at even index positions:\n");
    
    // Print characters at even indices (0, 2, 4, ...)
    for (i = 0; str[i] != '\0'; i += 2) {
        printf("%c", str[i]);
    }
    
    printf("\n");
    
    return 0;
}