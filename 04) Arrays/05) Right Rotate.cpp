For Right Rotation by k steps:
Reverse the entire array
Reverse the first k elements
Reverse the remaining n - k elements


For Left Rotation by k steps:
Reverse the first k elements
Reverse the remaining n - k elements
Reverse the entire array

// Brute Force 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to rotate the array to the right by k positions
    void rotateRight(int arr[], int n, int k) {
        if (n == 0) return;

        // Normalize k if greater than n
        k = k % n;

        // Store last k elements in a temporary array
        int temp[k];
        for (int i = n - k; i < n; i++) {
            temp[i - n + k] = arr[i];
        }

        // Shift the first n-k elements to the right by k steps
        for (int i = n - k - 1; i >= 0; i--) {
            arr[i + k] = arr[i];
        }

        // Copy back the k elements to the start
        for (int i = 0; i < k; i++) {
            arr[i] = temp[i];
        }
    }

    // Function to rotate the array to the left by k positions
    void rotateLeft(int arr[], int n, int k) {
        if (n == 0) return;

        // Normalize k if greater than n
        k = k % n;

        // Store first k elements in temporary array
        int temp[k];
        for (int i = 0; i < k; i++) {
            temp[i] = arr[i];
        }

        // Shift remaining elements to the left by k positions
        for (int i = k; i < n; i++) {
            arr[i - k] = arr[i];
        }

        // Copy back the stored elements to the end
        for (int i = 0; i < k; i++) {
            arr[n - k + i] = temp[i];
        }
    }
};

// Optimal Approach 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to reverse a subarray from index start to end
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    // Function to rotate array left or right by k steps
    vector<int> rotateArray(vector<int>& nums, int k, string direction) {
        int n = nums.size();

        // Edge case: empty or no rotation
        if (n == 0 || k == 0) return nums;

        // Normalize k
        k = k % n;

        if (direction == "right") {
            // Step 1: Reverse the whole array
            reverseArray(nums, 0, n - 1);

            // Step 2: Reverse first k elements
            reverseArray(nums, 0, k - 1);

            // Step 3: Reverse remaining n-k elements
            reverseArray(nums, k, n - 1);
        } 
        else if (direction == "left") {
            // Step 1: Reverse first k elements
            reverseArray(nums, 0, k - 1);

            // Step 2: Reverse remaining n-k elements
            reverseArray(nums, k, n - 1);

            // Step 3: Reverse the whole array
            reverseArray(nums, 0, n - 1);
        }

        return nums;
    }
};





