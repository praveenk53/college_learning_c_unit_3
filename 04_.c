// given a string s find the substring which has no repeating character and consists one digit

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, j, start = 0, maxStart = 0, maxLen = 0;
    int charIndex[256]; // To store last seen index of each character
    int hasDigit = 0;
    
    // Initialize all indices to -1
    for (i = 0; i < 256; i++) {
        charIndex[i] = -1;
    }

    // 1. Get the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // 2. Remove newline character
    str[strcspn(str, "\n")] = '\0';

    // 3. Use sliding window to find longest substring
    for (i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];
        
        // If character is repeated, move start pointer
        if (charIndex[ch] >= start) {
            start = charIndex[ch] + 1;
        }
        
        // Update last seen index
        charIndex[ch] = i;
        
        // Check if current window has a digit
        hasDigit = 0;
        for (j = start; j <= i; j++) {
            if (isdigit(str[j])) {
                hasDigit = 1;
                break;
            }
        }
        
        // Update max length if current window is longer and has digit
        if (hasDigit && (i - start + 1) > maxLen) {
            maxLen = i - start + 1;
            maxStart = start;
        }
    }

    // 4. Display the result
    if (maxLen > 0) {
        printf("Longest substring with no repeating chars and one digit: ");
        for (i = maxStart; i < maxStart + maxLen; i++) {
            printf("%c", str[i]);
        }
        printf("\nLength: %d\n", maxLen);
    } else {
        printf("No substring found with those conditions.\n");
    }

    return 0;
}