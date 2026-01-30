// program to allocate memory using malloc and display values

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

int main() {
    int n, i;
    int *ptr;

    // 1. Get the number of elements from the user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // 2. Allocate memory dynamically using malloc
    // Syntax: ptr = (castType*) malloc(size_in_bytes)
    ptr = (int*)malloc(n * sizeof(int));

    // 3. Check if the memory has been successfully allocated
    if (ptr == NULL) {
        printf("Memory not allocated. System out of resources.\n");
        return 1; // Better practice than exit(0) in main
    } else {
        printf("Memory successfully allocated using malloc.\n");

        // 4. Get the elements from the user
        printf("Enter the elements of the array:\n");
        for (i = 0; i < n; ++i) {
            scanf("%d", &ptr[i]);
        }

        // 5. Display the elements
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d ", ptr[i]);
        }
        printf("\n");
        
        // 6. Free the allocated memory (Crucial Step!)
        free(ptr);
        ptr = NULL; // Best practice: avoid dangling pointers
        printf("Memory successfully freed.\n");
    }

    return 0;
}