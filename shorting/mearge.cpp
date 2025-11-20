#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted halves
void merge(int arr[], int start, int mid, int end) {

    // Create temporary array
    vector<int> temp(end - start + 1);

    int left = start;      // pointer for left half
    int right = mid + 1;   // pointer for right half
    int index = 0;         // pointer for temp array

    // Merge elements in sorted order
    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            temp[index++] = arr[left++];
        } else {
            temp[index++] = arr[right++];
        }
    }

    // Copy remaining elements of left half
    while (left <= mid) {
        temp[index++] = arr[left++];
    }

    // Copy remaining elements of right half
    while (right <= end) {
        temp[index++] = arr[right++];
    }

    // Copy merged elements back to original array
    for (int i = 0; i < temp.size(); i++) {
        arr[start + i] = temp[i];
    }
}

// Merge Sort function
void mergeSort(int arr[], int start, int end) {

    // Base case
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    // Left half
    mergeSort(arr, start, mid);

    // Right half
    mergeSort(arr, mid + 1, end);

    // Merge both halves
    merge(arr, start, mid, end);
}

int main() {
    int arr[] = {8, 2, 9, 4, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    // Print sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}