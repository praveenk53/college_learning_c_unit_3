// validate email id format using string logic

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidEmail(char *email) {
    int len = strlen(email);
    int atCount = 0;
    int dotCount = 0;
    int atIndex = -1;
    int lastDotIndex = -1;
    int i;
    
    // Email should have at least 5 characters (a@b.c)
    if (len < 5) {
        return 0;
    }
    
    // Email should not start or end with a dot or @
    if (email[0] == '.' || email[0] == '@' || email[len - 1] == '.' || email[len - 1] == '@') {
        return 0;
    }
    
    // Check for valid characters and count @ and .
    for (i = 0; i < len; i++) {
        char ch = email[i];
        
        // Valid characters: alphanumeric, dot, hyphen, underscore
        if (!isalnum(ch) && ch != '.' && ch != '@' && ch != '-' && ch != '_') {
            return 0;
        }
        
        if (ch == '@') {
            atCount++;
            atIndex = i;
        } else if (ch == '.') {
            dotCount++;
            lastDotIndex = i;
        }
    }
    
    // Email must have exactly one @
    if (atCount != 1) {
        return 0;
    }
    
    // Email must have at least one dot after @
    if (dotCount == 0 || lastDotIndex <= atIndex) {
        return 0;
    }
    
    // There must be at least one character between @ and .
    if (lastDotIndex - atIndex < 2) {
        return 0;
    }
    
    // Domain extension must be 2-6 characters
    int extensionLen = len - lastDotIndex - 1;
    if (extensionLen < 2 || extensionLen > 6) {
        return 0;
    }
    
    // Username part (before @) must not have consecutive dots
    for (i = 0; i < atIndex - 1; i++) {
        if (email[i] == '.' && email[i + 1] == '.') {
            return 0;
        }
    }
    
    // Domain part (after @) must not have consecutive dots
    for (i = atIndex + 1; i < len - 1; i++) {
        if (email[i] == '.' && email[i + 1] == '.') {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char email[100];
    
    printf("Enter an email ID: ");
    scanf("%s", email);
    
    if (isValidEmail(email)) {
        printf("\n'%s' is a valid email ID\n", email);
    } else {
        printf("\n'%s' is NOT a valid email ID\n", email);
    }
    
    return 0;
}