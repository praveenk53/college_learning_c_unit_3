// extract username from an email address

#include <stdio.h>
#include <string.h>

int main() {
    char email[100];
    char username[100];
    int i = 0;
    int atIndex = -1;
    
    printf("Enter an email address: ");
    scanf("%s", email);
    
    // Find the position of @ symbol
    for (i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            atIndex = i;
            break;
        }
    }
    
    // Extract username (characters before @)
    if (atIndex != -1) {
        for (i = 0; i < atIndex; i++) {
            username[i] = email[i];
        }
        username[atIndex] = '\0';
        
        printf("\nEmail address: %s\n", email);
        printf("Username: %s\n", username);
    } else {
        printf("\nInvalid email address: @ symbol not found\n");
    }
    
    return 0;
}