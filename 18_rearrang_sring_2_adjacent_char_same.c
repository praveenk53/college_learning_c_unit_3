// rearrange string so that no two adjacent characters are the same

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store character and its frequency
typedef struct {
    char ch;
    int freq;
} CharFreq;

// Comparator function for qsort (sorts in descending order of frequency)
int compare(const void *a, const void *b) {
    return ((CharFreq *)b)->freq - ((CharFreq *)a)->freq;
}

int main() {
    char str[100];
    char result[100];
    CharFreq charFreq[26];
    int i, len, pos = 0;
    int uniqueChars = 0;
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    len = strlen(str);
    
    // Initialize character frequency array
    for (i = 0; i < 26; i++) {
        charFreq[i].ch = 'a' + i;
        charFreq[i].freq = 0;
    }
    
    // Count frequency of each character
    for (i = 0; i < len; i++) {
        charFreq[str[i] - 'a'].freq++;
    }
    
    // Sort by frequency in descending order
    qsort(charFreq, 26, sizeof(CharFreq), compare);
    
    // Count unique characters
    for (i = 0; i < 26 && charFreq[i].freq > 0; i++) {
        uniqueChars++;
    }
    
    // Check if arrangement is possible
    if (charFreq[0].freq > (len + 1) / 2) {
        printf("\nImpossible to rearrange: '%c' appears %d times (too frequent)\n", 
               charFreq[0].ch, charFreq[0].freq);
        return 0;
    }
    
    // Initialize result array
    for (i = 0; i < len; i++) {
        result[i] = '\0';
    }
    
    // Place characters at alternating positions
    for (i = 0; i < uniqueChars; i++) {
        int j = charFreq[i].freq;
        pos = 0;
        
        while (j > 0) {
            if (pos >= len) {
                pos = 1;  // Move to odd positions
            }
            result[pos] = charFreq[i].ch;
            j--;
            pos += 2;
        }
    }
    
    result[len] = '\0';
    
    printf("\nOriginal string: %s\n", str);
    printf("Rearranged string: %s\n", result);
    
    return 0;
}