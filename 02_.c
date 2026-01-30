// program to allocate and free dynamic memory

#include <stdio.h>
#include <stdlib.h> // Essential for malloc and free

int main() {
    // 1. Declare a pointer
    int *ptr;
    int n = 5;

    // 2. Allocate memory for 5 integers
    printf("Allocating memory for %d integers...\n", n);
    ptr = (int*)malloc(n * sizeof(int)); // sizeof(int) ensures correct byte allocation

    // Always check if allocation failed
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 3. Use the memory
    for (int i = 0; i < n; i++) {
        ptr[i] = i + 100; // Assign values
    }

    printf("Values stored in dynamic memory: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // 4. FREE the memory
    free(ptr);
    printf("Memory successfully freed.\n");

    // 5. Best Practice: Avoid "Dangling Pointers"
    ptr = NULL; 

    return 0;
}