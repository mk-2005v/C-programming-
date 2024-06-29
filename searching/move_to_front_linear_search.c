/**
 * @file move_to_front_linear_search.c
 * @brief Implementation of the Move-To-Front Linear Search algorithm.
 * @details
 * This algorithm searches for an element in an array and, if found,
 * moves it to the front of the array to speed up future searches.
 * It has a time complexity of O(n) in the worst case, where n is the size of
 * the array, and a space complexity of O(1). The algorithm works by iterating
 * through the array and comparing each element with the target element. If a
 * match is found, the element is moved to the front of the array by shifting
 * all previous elements one position to the right. This improves the search
 * time for future occurrences of the same element.
 *
 * For further information: https://ics.uci.edu/~dan/pubs/searchsurv.pdf
 *
 * @see https://ics.uci.edu/~dan/pubs/searchsurv.pdf
 *
 * @authors
 * - [Kiran](https://github.com/kiranj26)
 */

#include <assert.h>   /// for assert
#include <stdbool.h>  /// for bool
#include <stdio.h>    /// for printf

/**
 * @brief Perform Move-To-Front Linear Search on the given array
 * @param arr Array to search
 * @param n Size of the array
 * @param x Element to search for
 * @return Index of the found element, or -1 if not found
 */
int move_to_front_linear_search(int arr[], int n, int x)
{
    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
        // Check if the current element matches the target element
        if (arr[i] == x)
        {
            // Move the found element to the front of the array
            int temp = arr[i];
            for (int j = i; j > 0; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[0] = temp;
            return i;  // Return the index of the found element
        }
    }
    return -1;  // Return -1 if the element is not found
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void tests()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Test case: Element found at the beginning of the array
    assert(move_to_front_linear_search(arr, n, 1) == 0);
    assert(arr[0] == 1);  // Ensure the element is moved to front

    // Test case: Element found at the end of the array
    assert(move_to_front_linear_search(arr, n, 5) == 4);
    assert(arr[0] == 5);  // Ensure the element is moved to front

    // Test case: Element not found in the array
    assert(move_to_front_linear_search(arr, n, 10) == -1);

    // Test case: Empty array
    int empty_arr[] = {};
    int empty_n = sizeof(empty_arr) / sizeof(empty_arr[0]);
    assert(move_to_front_linear_search(empty_arr, empty_n, 1) == -1);

    // Test case: Element found in the middle of the array
    int mid_arr[] = {1, 2, 3, 4, 5};
    int mid_n = sizeof(mid_arr) / sizeof(mid_arr[0]);
    assert(move_to_front_linear_search(mid_arr, mid_n, 3) == 2);
    assert(mid_arr[0] == 3);  // Ensure the element is moved to front

    // Test case: Element found multiple times in the array
    int multi_arr[] = {1, 2, 3, 2, 4, 2, 5};
    int multi_n = sizeof(multi_arr) / sizeof(multi_arr[0]);
    assert(move_to_front_linear_search(multi_arr, multi_n, 2) == 1);
    assert(multi_arr[0] == 2);  // Ensure the element is moved to front

    // Test case: Element found at the last position of the array
    int last_arr[] = {1, 2, 3, 4, 5};
    int last_n = sizeof(last_arr) / sizeof(last_arr[0]);
    assert(move_to_front_linear_search(last_arr, last_n, 5) == 4);
    assert(last_arr[0] == 5);  // Ensure the element is moved to front

    printf("All additional tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    tests();  // run self-test implementations
    return 0;
}
