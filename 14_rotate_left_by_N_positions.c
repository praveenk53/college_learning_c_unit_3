// rotate a string left by N positions

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char rotated[100];
    int n, positions, i, len;
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    printf("Enter number of positions to rotate left: ");
    scanf("%d", &positions);
    
    len = strlen(str);
    positions = positions % len;  // Handle positions > length
    
    // Create rotated string
    // Copy characters from position 'positions' to end, then from start to 'positions'
    strcpy(rotated, str + positions);       // Copy from position onwards
    strncat(rotated, str, positions);       // Append first 'positions' characters
    
    printf("\nOriginal string: %s\n", str);
    printf("Rotated string (left by %d): %s\n", positions, rotated);
    
    return 0;
}