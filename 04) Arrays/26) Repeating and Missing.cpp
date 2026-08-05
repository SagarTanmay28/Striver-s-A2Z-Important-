Find the Repeating and Missing Number
Problem Statement

Given an array of size n containing numbers from 1 to n, where one number is missing and one number is repeated (appears twice), find both the missing number and the repeating number.

Example
cpp
arr = {3, 1, 2, 5, 3}
n = 5

Numbers 1 to 5 should all appear once.
3 appears twice (repeating), 4 is missing.

Output: repeating = 3, missing = 4
Approach 1: Brute Force — O(n²)

For each number 1 to n, count its occurrences in the array.

cpp
pair<int,int> findRepeatingMissingBrute(vector<int>& arr, int n) {
    int repeating = -1, missing = -1;

    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == i) count++;
        }

        if(count == 2) repeating = i;
        else if(count == 0) missing = i;
    }

    return {repeating, missing};
}

Time: O(n²), Space: O(1)

Approach 2: Hashing / Frequency Array — O(n) time, O(n) space
cpp
pair<int,int> findRepeatingMissingHash(vector<int>& arr, int n) {
    vector<int> freq(n + 1, 0);

    for(int x : arr) freq[x]++;

    int repeating = -1, missing = -1;
    for(int i = 1; i <= n; i++){
        if(freq[i] == 2) repeating = i;
        else if(freq[i] == 0) missing = i;
    }

    return {repeating, missing};
}

Time: O(n), Space: O(n) — better, but still uses extra space.

Approach 3: Mathematical (Sum & Sum of Squares) — O(n) time, O(1) space

Key idea: Use two equations based on known formulas.

Let repeating = X, missing = Y.

Sum of 1 to n = n(n+1)/2 = S
Actual sum of array = S'
Since the array has X twice and is missing Y: S' = S - Y + X → X - Y = S' - S ... (Equation 1)
Sum of squares of 1 to n = n(n+1)(2n+1)/6 = S2
Actual sum of squares of array = S2'
Similarly: S2' = S2 - Y² + X² → X² - Y² = S2' - S2 ... (Equation 2)

Divide Equation 2 by Equation 1:

(X² - Y²) / (X - Y) = (S2' - S2) / (S' - S)
(X + Y)(X - Y) / (X - Y) = ...
X + Y = (S2' - S2) / (S' - S)   ... (Equation 3)

Now we have two linear equations (1) and (3) in X and Y → solve simultaneously.

cpp
#include <iostream>
#include <vector>
using namespace std;

pair<int,int> findRepeatingMissingMath(vector<int>& arr, int n) {
    long long S = (long long)n * (n + 1) / 2;
    long long S2 = (long long)n * (n + 1) * (2*n + 1) / 6;

    long long actualS = 0, actualS2 = 0;
    for(int x : arr){
        actualS += x;
        actualS2 += (long long)x * x;
    }

    long long diffS = actualS - S;       // X - Y
    long long diffS2 = actualS2 - S2;    // X^2 - Y^2

    long long sumXY = diffS2 / diffS;    // X + Y

    long long X = (diffS + sumXY) / 2;   // solving the 2 equations
    long long Y = sumXY - X;

    return {(int)X, (int)Y};
}

int main() {
    vector<int> arr = {3, 1, 2, 5, 3};
    auto [repeating, missing] = findRepeatingMissingMath(arr, 5);
    cout << "Repeating: " << repeating << ", Missing: " << missing;
    // Repeating: 3, Missing: 4
}
Trace on {3, 1, 2, 5, 3}, n = 5
S = 5*6/2 = 15
S2 = 5*6*11/6 = 55

actualS = 3+1+2+5+3 = 14
actualS2 = 9+1+4+25+9 = 48

diffS = 14-15 = -1        -> X - Y = -1
diffS2 = 48-55 = -7       -> X^2 - Y^2 = -7

sumXY = -7 / -1 = 7        -> X + Y = 7

X = (diffS + sumXY)/2 = (-1+7)/2 = 3
Y = 7 - 3 = 4

Repeating = 3, Missing = 4 ✅

⚠️ Overflow caution: n*(n+1)*(2n+1) can be very large — always use long long for these sums.

Complexity: O(n) time, O(1) extra space — best approach.

Approach 4: XOR-based (Bit Manipulation) — O(n) time, O(1) space

Alternative to the math approach, using XOR properties (avoids overflow risk entirely).

cpp
pair<int,int> findRepeatingMissingXOR(vector<int>& arr, int n) {
    int xorAll = 0;

    // XOR all array elements with all numbers 1 to n
    for(int x : arr) xorAll ^= x;
    for(int i = 1; i <= n; i++) xorAll ^= i;

    // xorAll now = missing XOR repeating

    // find rightmost set bit to differentiate the two numbers
    int rightmostSetBit = xorAll & (-xorAll);

    int num1 = 0, num2 = 0; // will hold missing and repeating (not yet known which is which)

    for(int x : arr){
        if(x & rightmostSetBit) num1 ^= x;
        else num2 ^= x;
    }
    for(int i = 1; i <= n; i++){
        if(i & rightmostSetBit) num1 ^= i;
        else num2 ^= i;
    }

    // determine which of num1/num2 is the repeating one (appears in array)
    int countNum1 = 0;
    for(int x : arr) if(x == num1) countNum1++;

    if(countNum1 == 2) return {num1, num2};  // {repeating, missing}
    else return {num2, num1};
}

Why this works: XOR-ing all array elements with 1..n cancels out every number that appears exactly once, leaving missing XOR repeating. Since missing != repeating, at least one bit differs between them — the rightmost set bit of the XOR result identifies a bit where they differ. Splitting all numbers into two groups based on that bit separates missing and repeating into different groups, letting XOR isolate each one individually.

Complexity: O(n) time, O(1) space — avoids overflow risk of the math approach, generally preferred in practice.
