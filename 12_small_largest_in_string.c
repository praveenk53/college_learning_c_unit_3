// find the smallest and largest word in a string

#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char word[50];
    char smallest[50], largest[50];
    int i = 0, j = 0;
    int minLen = 999, maxLen = 0;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    // Extract and compare each word
    for (i = 0; i <= strlen(str); i++) {
        // Check if space or end of string
        if (str[i] == ' ' || str[i] == '\0') {
            if (j > 0) {  // If word exists
                word[j] = '\0';
                
                // Update smallest word
                if (j < minLen) {
                    minLen = j;
                    strcpy(smallest, word);
                }
                
                // Update largest word
                if (j > maxLen) {
                    maxLen = j;
                    strcpy(largest, word);
                }
                
                j = 0;  // Reset word index
            }
        } else {
            word[j++] = str[i];  // Add character to word
        }
    }
    
    printf("\nSmallest word: %s (length: %d)\n", smallest, minLen);
    printf("Largest word: %s (length: %d)\n", largest, maxLen);
    
    return 0;
}