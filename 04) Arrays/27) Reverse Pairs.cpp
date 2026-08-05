Problem Statement

Count pairs (i, j) such that i < j and nums[i] > 2 * nums[j].

Approach: Merge Sort with Extra Counting Pass — O(n log n)
cpp
#include <iostream>
#include <vector>
using namespace std;

int countAndMerge(vector<int>& arr, int low, int mid, int high) {
    int count = 0;
    int j = mid + 1;

    // count pairs across the two halves
    for(int i = low; i <= mid; i++){
        while(j <= high && (long long)arr[i] > 2LL * arr[j]){
            j++;
        }
        count += (j - (mid + 1));
    }

    // standard merge
    vector<int> temp;
    int left = low, right = mid + 1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }
    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);

    for(int i = low; i <= high; i++) arr[i] = temp[i - low];

    return count;
}

int mergeSortCount(vector<int>& arr, int low, int high) {
    if(low >= high) return 0;

    int mid = (low + high) / 2;
    int count = 0;

    count += mergeSortCount(arr, low, mid);
    count += mergeSortCount(arr, mid + 1, high);
    count += countAndMerge(arr, low, mid, high);

    return count;
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << mergeSortCount(nums, 0, nums.size() - 1);   // 2
}
Why j never resets within the counting loop

As i increases, arr[i] (within the sorted left half) only increases, so the pointer j (searching the sorted right half for elements satisfying arr[i] > 2*arr[j]) only moves forward — this keeps the counting pass O(mid-low + high-mid) = O(n) total per merge level, giving overall O(n log n).

(Full step-by-step trace of this exact problem was covered in detail earlier in this conversation — refer back to that for the complete walkthrough.)

Complexity: O(n log n) time, O(n) space (merge sort's auxiliary array).
