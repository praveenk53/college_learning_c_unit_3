// find the ascii value of each character in a string 

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
    
    printf("\nCharacter - ASCII Value:\n");
    printf("-----------------------------\n");
    
    // Display ASCII value of each character
    for (i = 0; str[i] != '\0'; i++) {
        printf("'%c' - %d\n", str[i], (unsigned char)str[i]);
    }
    
    return 0;
}