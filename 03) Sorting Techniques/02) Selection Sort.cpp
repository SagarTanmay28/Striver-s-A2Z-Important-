2. Selection Sort

Finds the minimum element from the unsorted part and places it at the beginning.
Time Complexity: O(n²) always (even if sorted)
Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        int mini   = INT_MAX;
        int minIdx = -1;
        for (int j = i; j < n; j++) {
            if (nums[j] < mini){
                mini = nums[j];
                minIdx = j;
            }
        }
        
        swap(nums[i], nums[minIdx]);
    }
}

int main() {
    vector<int> nums = {5, 1, 4, 2, 8, 0, 3};

    selectionSort(nums);

    for (int x : nums) cout << x << " ";
    // Output: 0 1 2 3 4 5 8
}
