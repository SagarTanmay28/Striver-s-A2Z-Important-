3. Insertion Sort

Builds the sorted array one element at a time — takes each element and inserts it into its correct position among the already-sorted part.
Time Complexity: O(n²) worst/avg, O(n) best (already sorted)
Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int j = i;
        // keep swapping arr[j] backward while it's smaller than arr[j-1]
        while (j >= 1 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

int main() {
    vector<int> nums = {5, 1, 4, 2, 8, 0, 3};

    insertionSort(nums);

    for (int x : nums) cout << x << " ";
    // Output: 0 1 2 3 4 5 8
}
