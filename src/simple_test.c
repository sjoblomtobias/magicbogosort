#include <stdio.h>
#include <stdlib.h>
#include "magicbogosort.h"

int main(void) {
    printf("=== Simple Magic Bogosort Test ===\n\n");
    
    // Simple example array
    int arr[] = {3, 1, 4, 2, 92, 5, 7, 6, 11, 9, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    print_array(arr, size);
    
    // Run magic bogosort
    int magic_seed = magicbogosort(arr, size);
    printf("Sorted array with seed %d:   ", magic_seed);
    print_array(arr, size);

    
    return 0;
}