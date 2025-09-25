#ifndef MAGICBOGOSORT_H
#define MAGICBOGOSORT_H

#include <stdbool.h>

/**
 * Simple Magic Bogosort - sorts array in-place by finding the magic seed
 * This is the main production function - never gives up until it finds the magic seed
 * @param arr The array to sort (modified in-place)
 * @param size The size of the array
 * @return the magic seed that was used to sort the array
 */
unsigned int magicbogosort(int arr[], int size);

/**
 * Check if an array is sorted in ascending order
 * @param arr The array to check
 * @param size The size of the array
 * @return true if sorted, false otherwise
 */
bool is_sorted(int arr[], int size);

/**
 * Shuffle an array randomly using Fisher-Yates algorithm
 * @param arr The array to shuffle
 * @param size The size of the array
 */
void shuffle_array(int arr[], int size);

/**
 * Print an array (for debugging/testing only)
 * @param arr The array to print
 * @param size The size of the array
 */
void print_array(int arr[], int size);

#endif // MAGICBOGOSORT_H