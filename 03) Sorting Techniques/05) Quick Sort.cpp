Quick Sort
Idea

Pick a pivot element, partition the array so all elements smaller than the pivot go left, all larger go right, 
then recursively sort both sides. Unlike merge sort, quicksort sorts in-place (no extra arrays needed).

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];   // choose last element as pivot
    int i = low - 1;          // boundary of "smaller than pivot" region

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  // place pivot in its correct position
    return i + 1;                  // return pivot's final index
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // pi = pivot index (already sorted position)

        quickSort(arr, low, pi - 1);   // sort left of pivot
        quickSort(arr, pi + 1, high);  // sort right of pivot
    }
}

int main() {
    vector<int> nums = {5, 1, 4, 2, 8, 0, 3};

    quickSort(nums, 0, nums.size() - 1);

    for (int x : nums) cout << x << " ";
    // Output: 0 1 2 3 4 5 8
}
