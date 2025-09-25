#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// Forward declarations
int find_cached_seed(int arr[], int size);
void save_to_cache(int arr[], int size, unsigned int seed);
void array_to_hash(int arr[], int size, char hash_str[]);

/**
 * Check if an array is sorted in ascending order
 * @param arr The array to check
 * @param size The size of the array
 * @return true if sorted, false otherwise
 */
bool is_sorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

/**
 * Shuffle an array randomly using Fisher-Yates algorithm
 * @param arr The array to shuffle
 * @param size The size of the array
 */
void shuffle_array(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/**
 * Print an array (for debugging/testing only)
 * @param arr The array to print
 * @param size The size of the array
 */
void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Simple Magic Bogosort - sorts array in-place by finding the magic seed
 * This is the production version - never gives up until it finds the magic seed
 * @param arr The array to sort (modified in-place)
 * @param size The size of the array
 * @return the magic seed that was used to sort the array
 */
unsigned int magicbogosort(int arr[], int size) {
    // Create a copy of original array for cache lookup
    int *original = malloc(size * sizeof(int));
    if (original == NULL) {
        return false; // Memory allocation failed
    }
    
    for (int i = 0; i < size; i++) {
        original[i] = arr[i];
    }
    
    // Check cache first
    int cached_seed = find_cached_seed(original, size);
    if (cached_seed != -1) {
        // Use cached seed
        srand((unsigned int)cached_seed);
        shuffle_array(arr, size);
        free(original);
        return (unsigned int)cached_seed;
    }
    
    // No cache hit, search for magic seed - never give up!
    unsigned int seed = 0;
    while (true) {
        // Reset array to original state
        for (int i = 0; i < size; i++) {
            arr[i] = original[i];
        }
        
        // Try this seed
        srand(seed);
        shuffle_array(arr, size);
        
        if (is_sorted(arr, size)) {
            // Found magic seed, save to cache
            save_to_cache(original, size, seed);
            free(original);
            return seed;
        }
        
        // Move to next seed (with wraparound protection)
        if (seed == (unsigned int)-1) {
            // We've tried all possible seeds - this should theoretically never happen
            // but just in case, reset to 0 to continue the search
            seed = 0;
        } else {
            seed++;
        }
    }
}

/**
 * Generate a hash string representation of an array
 * @param arr The array to hash
 * @param size The size of the array
 * @param hash_str Buffer to store the hash string (must be large enough)
 */
void array_to_hash(int arr[], int size, char hash_str[]) {
    strcpy(hash_str, "");
    char temp[20];
    for (int i = 0; i < size; i++) {
        sprintf(temp, "%d", arr[i]);
        strcat(hash_str, temp);
        if (i < size - 1) {
            strcat(hash_str, ",");
        }
    }
}

/**
 * Search for a cached seed for the given array
 * @param arr The array to search for
 * @param size The size of the array
 * @return The cached seed, or -1 if not found
 */
int find_cached_seed(int arr[], int size) {
    FILE *file = fopen("cache.txt", "r");
    if (file == NULL) {
        return -1; // Cache file doesn't exist
    }
    
    char array_hash[1000];
    array_to_hash(arr, size, array_hash);
    
    char line[1500];
    while (fgets(line, sizeof(line), file)) {
        // Parse line: array_data|seed
        char *pipe = strchr(line, '|');
        if (pipe != NULL) {
            *pipe = '\0'; // Split the string
            char *cached_array = line;
            int cached_seed = atoi(pipe + 1);
            
            if (strcmp(cached_array, array_hash) == 0) {
                fclose(file);
                return cached_seed;
            }
        }
    }
    
    fclose(file);
    return -1; // Not found in cache
}

/**
 * Save array and its working seed to cache
 * @param arr The original array
 * @param size The size of the array
 * @param seed The seed that worked for this array
 */
void save_to_cache(int arr[], int size, unsigned int seed) {
    FILE *file = fopen("cache.txt", "a");
    if (file == NULL) {
        return; // Silently fail if can't open cache
    }
    
    char array_hash[1000];
    array_to_hash(arr, size, array_hash);
    
    fprintf(file, "%s|%u\n", array_hash, seed);
    fclose(file);
}
