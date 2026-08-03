Problem Statement

Given an array nums, count the number of inversions — pairs (i, j) such that:

i < j  AND  nums[i] > nums[j]

An inversion measures "how far the array is from being sorted." A sorted array has 0 inversions. A reverse-sorted array has the maximum possible inversions.

#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& a, vector<int>& b, vector<int>& v) {
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0, k = 0;
    long long invCount = 0;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            v[k++] = a[i++];
        } else {
            // a[i] > b[j] -> a[i..n1-1] are all > b[j] (since a is sorted)
            invCount += (n1 - i);
            v[k++] = b[j++];
        }
    }

    while (i < n1) v[k++] = a[i++];
    while (j < n2) v[k++] = b[j++];

    return invCount;
}

long long mergeSortCount(vector<int>& v) {
    int n = v.size();
    if (n == 1) return 0;   // base case: no inversions possible

    int n1 = n / 2, n2 = n - n / 2;
    vector<int> a(n1), b(n2);

    for (int i = 0; i < n1; i++) a[i] = v[i];
    for (int i = 0; i < n2; i++) b[i] = v[i + n1];

    long long invCount = 0;
    invCount += mergeSortCount(a);   // inversions within left half
    invCount += mergeSortCount(b);   // inversions within right half
    invCount += merge(a, b, v);      // inversions across halves

    return invCount;
}

int main() {
    vector<int> nums = {2, 4, 1, 3, 5};
    cout << mergeSortCount(nums);   // 3
}
