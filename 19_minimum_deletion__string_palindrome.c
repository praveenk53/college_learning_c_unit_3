// find minimum deletions to make a string palindrome

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[100];
    int len, i, j;
    int dp[100][100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    len = strlen(str);
    
    // Initialize dp table
    // dp[i][j] = length of longest palindromic subsequence from i to j
    for (i = 0; i < len; i++) {
        dp[i][i] = 1;  // Single character is palindrome
    }
    
    // Build the dp table
    for (int chainLen = 2; chainLen <= len; chainLen++) {
        for (i = 0; i <= len - chainLen; i++) {
            j = i + chainLen - 1;
            
            if (str[i] == str[j]) {
                // If first and last characters match
                if (chainLen == 2) {
                    dp[i][j] = 2;
                } else {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            } else {
                // If they don't match, take max of two options
                dp[i][j] = (dp[i + 1][j] > dp[i][j - 1]) ? dp[i + 1][j] : dp[i][j - 1];
            }
        }
    }
    
    // Minimum deletions = total length - longest palindromic subsequence
    int minDeletions = len - dp[0][len - 1];
    
    printf("\nOriginal string: %s\n", str);
    printf("Length: %d\n", len);
    printf("Longest palindromic subsequence length: %d\n", dp[0][len - 1]);
    printf("Minimum deletions required: %d\n", minDeletions);
    
    return 0;
}