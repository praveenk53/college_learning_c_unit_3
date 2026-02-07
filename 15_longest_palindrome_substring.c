// given a string, find the longest palindrome substring

#include <stdio.h>
#include <string.h>

int isPalindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[100];
    int len, i, j;
    int maxLen = 0;
    int startIndex = 0;
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    len = strlen(str);
    
    // Check all possible substrings
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            // Check if substring from i to j is palindrome
            if (isPalindrome(str, i, j)) {
                int currentLen = j - i + 1;
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    startIndex = i;
                }
            }
        }
    }
    
    printf("\nLongest palindrome substring: ");
    for (i = startIndex; i < startIndex + maxLen; i++) {
        printf("%c", str[i]);
    }
    printf("\nLength: %d\n", maxLen);
    
    return 0;
}