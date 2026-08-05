#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxLen(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> firstIndex;  // prefixSum -> first index it occurred at
    int sum = 0;
    int maxLength = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];

        // case 1: prefix sum itself is 0 -> subarray from start to i
        if(sum == 0){
            maxLength = max(maxLength, i + 1);
        }

        // case 2: this exact prefix sum seen before -> subarray between them is 0
        if(firstIndex.find(sum) != firstIndex.end()){
            maxLength = max(maxLength, i - firstIndex[sum]);
        }
        else{
            // store only first occurrence
            firstIndex[sum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << maxLen(arr);   // 5
}
