// program to count the frequency of each character in a string

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0}; // Array to store frequency of each character (ASCII range)
    int i;

    // 1. Get the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Better than scanf for strings with spaces

    // 2. Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    // 3. Count frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    // 4. Display the frequency of each character
    printf("Character frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' : %d\n", (char)i, freq[i]);
        }
    }

    return 0;
}