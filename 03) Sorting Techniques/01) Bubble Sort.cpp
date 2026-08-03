1. Bubble Sort

Repeatedly swaps adjacent elements if they're in the wrong order — largest "bubbles up" to the end each pass.
Time Complexity: O(n²) worst/avg, O(n) best (already sorted)
Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // already sorted, stop early
    }
}

int main() {
    vector<int> nums = {5, 1, 4, 2, 8, 0, 3};

    bubbleSort(nums);

    for (int x : nums) cout << x << " ";
    // Output: 0 1 2 3 4 5 8
}
