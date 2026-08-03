## Merge Sort ## 
Time	O(n log n) — always (best, worst, average)
Space	O(n) — needs extra arrays for merging

#include <iostream>
#include <vector>
using namespace std;

// merges two sorted vectors a and b into v
void merge(vector<int>& a, vector<int>& b, vector<int>& v) {
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0, k = 0;

    // pick smaller of a[i], b[j] and place into v[k]
    while (i < n1 && j < n2) {
        if (a[i] <= b[j])
            v[k++] = a[i++];
        else
            v[k++] = b[j++];
    }

    // copy remaining elements of a, if any
    while (i < n1) v[k++] = a[i++];

    // copy remaining elements of b, if any
    while (j < n2) v[k++] = b[j++];
}

void mergeSort(vector<int>& v) {
    int n = v.size();
    if (n == 1) return;   // base case: single element is already "sorted"

    int n1 = n / 2, n2 = n - n / 2;
    vector<int> a(n1), b(n2);

    // copy pasting -> split v into two halves a and b
    for (int i = 0; i < n1; i++) {
        a[i] = v[i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = v[i + n1];
    }

    // magic aka recursion -> sort both halves independently
    mergeSort(a);
    mergeSort(b);

    // merge -> combine sorted halves back into v
    merge(a, b, v);
}

int main() {
    vector<int> nums = {5, 1, 4, 2, 8, 0, 3};

    mergeSort(nums);

    for (int x : nums) cout << x << " ";
    // Output: 0 1 2 3 4 5 8
}
