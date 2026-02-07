// check password strength based on rules

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkPasswordStrength(char *password) {
    int len = strlen(password);
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;
    int strength = 0;
    int i;
    
    // Check minimum length
    if (len < 8) {
        return 0;  // Too weak
    }
    
    // Check for uppercase letters
    for (i = 0; i < len; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
            break;
        }
    }
    
    // Check for lowercase letters
    for (i = 0; i < len; i++) {
        if (islower(password[i])) {
            hasLowercase = 1;
            break;
        }
    }
    
    // Check for digits
    for (i = 0; i < len; i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
            break;
        }
    }
    
    // Check for special characters
    for (i = 0; i < len; i++) {
        if (!isalnum(password[i])) {
            hasSpecialChar = 1;
            break;
        }
    }
    
    // Calculate strength score
    strength += hasUppercase;
    strength += hasLowercase;
    strength += hasDigit;
    strength += hasSpecialChar;
    
    // Bonus for length
    if (len >= 12) {
        strength += 1;
    }
    
    return strength;
}

int main() {
    char password[100];
    int strength;
    int i;
    
    printf("Enter a password: ");
    scanf("%s", password);
    
    strength = checkPasswordStrength(password);
    
    printf("\nPassword: %s\n", password);
    printf("Length: %d characters\n", (int)strlen(password));
    printf("Strength Score: %d/5\n", strength);
    
    // Display strength level
    switch (strength) {
        case 0:
            printf("Strength Level: Very Weak (minimum 8 characters required)\n");
            break;
        case 1:
            printf("Strength Level: Weak\n");
            break;
        case 2:
            printf("Strength Level: Fair\n");
            break;
        case 3:
            printf("Strength Level: Good\n");
            break;
        case 4:
            printf("Strength Level: Strong\n");
            break;
        case 5:
            printf("Strength Level: Very Strong\n");
            break;
    }
    
    return 0;
}