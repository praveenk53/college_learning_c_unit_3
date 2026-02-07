// remove duplicate characters from a string

#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int seen[256] = {0};
    int i, j = 0;
    
    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) return 0;
    if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
    
    for (i = 0; str[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str[i];
        if (!seen[c]) {
            seen[c] = 1;
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    
    printf("Result: %s\n", str);
    return 0;
}