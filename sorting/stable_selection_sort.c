/**
 * @file stable_selection_sort.c
 * @brief Implementation of stable selection sort algorithm.
 *
 * This file contains the implementation of a stable selection sort algorithm
 * which maintains the relative order of equal elements while sorting the array.
 *
 * @details
 * The stable selection sort algorithm repeatedly selects the minimum element
 * from the unsorted portion of the array and inserts it at the beginning of the
 * unsorted portion, maintaining the relative order of equal elements.
 *
 * @note
 * - Time Complexity: O(n^2)
 * - Space Complexity: O(1)
 * - Stable: Yes
 *
 * @example
 * int arr[] = {4, 5, 3, 2, 4, 1};
 * int n = sizeof(arr) / sizeof(arr[0]);
 * stable_selection_sort(arr, n);
 * // Output: [1, 2, 3, 4, 4, 5]
 *
 * @author
 * Kiran Jojare
 *
 * @see
 * https://www.geeksforgeeks.org/stable-selection-sort/?ref=lbp
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints the elements of an array.
 *
 * This function prints the elements of the given array to the console.
 *
 * @param arr The array to be printed.
 * @param n The number of elements in the array.
 */
void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Shifts elements of the array to the right by one position.
 *
 * This function shifts the elements of the array from the specified start index
 * to the end index to the right by one position.
 *
 * @param arr The array whose elements are to be shifted.
 * @param start The starting index from where the shift begins.
 * @param end The ending index where the shift ends.
 */
void shift_right_by_1(int *arr, int start, int end)
{
    for (int i = end; i > start; i--)
    {
        arr[i] = arr[i - 1];
    }
}

/**
 * @brief Performs stable selection sort on the given array.
 *
 * This function sorts the given array in ascending order using the stable
 * selection sort algorithm, which maintains the relative order of equal
 * elements.
 *
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void stable_selection_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_val_index = i;
        for (int j = i + 1; j < n; j++)
        {
            // Find the minimum value in the unsorted part of the array
            if (arr[j] < arr[min_val_index])
            {
                min_val_index = j;
            }
        }

        // Store the minimum value temporarily
        int min_val = arr[min_val_index];
        // Shift elements to the right to make space for the minimum value
        shift_right_by_1(arr, i, min_val_index);
        // Place the minimum value at the correct position
        arr[i] = min_val;
    }
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    // Test case 1: Regular unsorted array
    int unsorted_array1[] = {64, 34, 25, 12, 22};
    int n1 = sizeof(unsorted_array1) / sizeof(unsorted_array1[0]);
    stable_selection_sort(unsorted_array1, n1);
    int expected1[] = {12, 22, 25, 34, 64};
    for (int i = 0; i < n1; i++)
    {
        assert(unsorted_array1[i] == expected1[i]);
    }

    // Test case 2: Array with negative numbers
    int unsorted_array2[] = {-3, 10, -1, 7, -20, 5};
    int n2 = sizeof(unsorted_array2) / sizeof(unsorted_array2[0]);
    stable_selection_sort(unsorted_array2, n2);
    int expected2[] = {-20, -3, -1, 5, 7, 10};
    for (int i = 0; i < n2; i++)
    {
        assert(unsorted_array2[i] == expected2[i]);
    }

    // Test case 3: Already sorted array
    int sorted_array[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(sorted_array) / sizeof(sorted_array[0]);
    stable_selection_sort(sorted_array, n3);
    int expected3[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < n3; i++)
    {
        assert(sorted_array[i] == expected3[i]);
    }

    // Test case 4: Array with all elements the same
    int same_elements_array[] = {5, 5, 5, 5};
    int n4 = sizeof(same_elements_array) / sizeof(same_elements_array[0]);
    stable_selection_sort(same_elements_array, n4);
    int expected4[] = {5, 5, 5, 5};
    for (int i = 0; i < n4; i++)
    {
        assert(same_elements_array[i] == expected4[i]);
    }

    // Test case 5: Array with a single element
    int single_element_array[] = {42};
    int n5 = sizeof(single_element_array) / sizeof(single_element_array[0]);
    stable_selection_sort(single_element_array, n5);
    int expected5[] = {42};
    for (int i = 0; i < n5; i++)
    {
        assert(single_element_array[i] == expected5[i]);
    }

    // Test case 6: Empty array
    int empty_array[] = {};
    int n6 = sizeof(empty_array) / sizeof(empty_array[0]);
    stable_selection_sort(empty_array, n6);
    int expected6[] = {};
    for (int i = 0; i < n6; i++)
    {
        assert(empty_array[i] == expected6[i]);
    }

    printf("All tests passed successfully.\n");
}

/**
 * @brief Main function to run the tests for the stable selection sort
 * algorithm.
 *
 * @return int Returns 0 on successful execution.
 */
int main()
{
    test();
    return 0;
}
