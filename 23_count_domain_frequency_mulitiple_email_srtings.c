// count domain frequency from multiple email strings

#include <stdio.h>
#include <string.h>

typedef struct {
    char domain[100];
    int count;
} DomainFreq;

int main() {
    char emails[50][100];
    DomainFreq domains[50];
    int numEmails = 0;
    int numDomains = 0;
    int i, j, k;
    char domain[100];
    int atIndex, dotIndex;
    int found;
    
    printf("Enter number of emails: ");
    scanf("%d", &numEmails);
    
    // Input emails
    printf("Enter %d email addresses:\n", numEmails);
    for (i = 0; i < numEmails; i++) {
        printf("Email %d: ", i + 1);
        scanf("%s", emails[i]);
    }
    
    printf("\n------- Domain Frequency Report -------\n\n");
    
    // Extract and count domain frequency
    for (i = 0; i < numEmails; i++) {
        // Find @ symbol
        atIndex = -1;
        for (j = 0; j < strlen(emails[i]); j++) {
            if (emails[i][j] == '@') {
                atIndex = j;
                break;
            }
        }
        
        if (atIndex != -1) {
            // Extract domain (part after @)
            strcpy(domain, emails[i] + atIndex + 1);
            
            // Check if domain already exists
            found = 0;
            for (k = 0; k < numDomains; k++) {
                if (strcmp(domains[k].domain, domain) == 0) {
                    domains[k].count++;
                    found = 1;
                    break;
                }
            }
            
            // If domain not found, add it
            if (!found) {
                strcpy(domains[numDomains].domain, domain);
                domains[numDomains].count = 1;
                numDomains++;
            }
        }
    }
    
    // Display results
    printf("Domain Name                  | Frequency\n");
    printf("------------------------------+-----------\n");
    
    for (i = 0; i < numDomains; i++) {
        printf("%-28s | %d\n", domains[i].domain, domains[i].count);
    }
    
    // Find most frequent domain
    printf("\n");
    int maxCount = domains[0].count;
    int maxIndex = 0;
    for (i = 1; i < numDomains; i++) {
        if (domains[i].count > maxCount) {
            maxCount = domains[i].count;
            maxIndex = i;
        }
    }
    
    printf("Most Frequent Domain: %s (%d occurrences)\n", domains[maxIndex].domain, maxCount);
    
    return 0;
}