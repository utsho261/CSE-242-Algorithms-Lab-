#include <bits/stdc++.h>
using namespace std;

// Function to perform the partition
int partition(int arr[], int p, int r)
{
    int pivot = arr[p]; // Choosing the first element as the pivot
    int i = p + 1;

    for (int j = i; j < r; j++)   // Note the change here to j < r
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            // Using a temporary variable for swapping
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;    // increment the index of smaller element
        }
    }
    // Swap pivot into the correct position using a temporary variable
    int temp = arr[p];
    arr[p] = arr[i - 1];
    arr[i - 1] = temp;

    return i - 1; // Return the new pivot index
}

// Function to perform QuickSort
void quicksort(int arr[], int p, int r)
{
    if (p < r - 1)   // Adjusting the condition to stop before the last element (INT_MAX)
    {
        int q = partition(arr, p, r); // Getting the pivot index
        quicksort(arr, p, q); // Recursively sorting the left half
        quicksort(arr, q + 1, r); // Recursively sorting the right half
    }
}

int main()
{
    int n; // Number of elements
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n + 1]; // Array to be sorted, with an extra space for INT_MAX

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    arr[n] = INT_MAX; // Setting the last element to INT_MAX

    quicksort(arr, 0, n + 1); // Calling quicksort on the array including INT_MAX

    cout << "Sorted array (excluding INT_MAX):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
