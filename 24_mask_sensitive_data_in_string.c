// mask sensitive data in a string (e.g. phone number)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void maskPhoneNumber(char *phone, char *masked) {
    int len = strlen(phone);
    strcpy(masked, phone);
    
    // Mask all digits except last 4
    for (int i = 0; i < len - 4; i++) {
        if (isdigit(masked[i])) {
            masked[i] = '*';
        }
    }
}

void maskCreditCard(char *card, char *masked) {
    int len = strlen(card);
    strcpy(masked, card);
    
    // Show only last 4 digits, mask the rest
    for (int i = 0; i < len - 4; i++) {
        if (isdigit(masked[i])) {
            masked[i] = '*';
        }
    }
}

void maskEmail(char *email, char *masked) {
    int len = strlen(email);
    strcpy(masked, email);
    
    // Find @ symbol
    int atIndex = -1;
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            atIndex = i;
            break;
        }
    }
    
    // Mask username part (keep first and last character)
    if (atIndex > 2) {
        for (int i = 1; i < atIndex - 1; i++) {
            masked[i] = '*';
        }
    }
}

void maskSSN(char *ssn, char *masked) {
    int len = strlen(ssn);
    strcpy(masked, ssn);
    
    // Mask first 5 digits, show last 4
    for (int i = 0; i < len - 4; i++) {
        if (isdigit(masked[i])) {
            masked[i] = '*';
        }
    }
}

int main() {
    char input[100];
    char masked[100];
    int choice;
    
    printf("===== Sensitive Data Masking Tool =====\n\n");
    printf("Choose what to mask:\n");
    printf("1. Phone Number\n");
    printf("2. Credit Card Number\n");
    printf("3. Email Address\n");
    printf("4. Social Security Number (SSN)\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    printf("\nEnter the data to mask: ");
    scanf("%s", input);
    
    switch (choice) {
        case 1:
            maskPhoneNumber(input, masked);
            printf("\nOriginal Phone: %s\n", input);
            printf("Masked Phone:   %s\n", masked);
            break;
            
        case 2:
            maskCreditCard(input, masked);
            printf("\nOriginal Card:  %s\n", input);
            printf("Masked Card:    %s\n", masked);
            break;
            
        case 3:
            maskEmail(input, masked);
            printf("\nOriginal Email: %s\n", input);
            printf("Masked Email:   %s\n", masked);
            break;
            
        case 4:
            maskSSN(input, masked);
            printf("\nOriginal SSN:   %s\n", input);
            printf("Masked SSN:     %s\n", masked);
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}