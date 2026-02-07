// check whether a string is a rotation of another string

#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    char temp[200];
    int len1, len2;
    
    printf("Enter first string: ");
    scanf("%s", str1);
    
    printf("Enter second string: ");
    scanf("%s", str2);
    
    len1 = strlen(str1);
    len2 = strlen(str2);
    
    // If lengths are different, str2 cannot be rotation of str1
    if (len1 != len2) {
        printf("\n%s is NOT a rotation of %s\n", str2, str1);
        return 0;
    }
    
    // Concatenate str1 with itself
    // If str2 is a rotation of str1, it will be a substring of str1+str1
    strcpy(temp, str1);
    strcat(temp, str1);
    
    // Check if str2 is a substring of temp
    if (strstr(temp, str2) != NULL) {
        printf("\n%s is a rotation of %s\n", str2, str1);
    } else {
        printf("\n%s is NOT a rotation of %s\n", str2, str1);
    }
    
    return 0;
}