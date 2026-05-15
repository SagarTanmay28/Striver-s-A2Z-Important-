vector<int> v = {5,2,8,1,9,3};

// default ascending
sort(v.begin(), v.end());
// v = {1,2,3,5,8,9}

// descending with comparator
sort(v.begin(), v.end(), greater<int>());
// v = {9,8,5,3,2,1}

// custom: sort by second element of pair
vector<pair<int,int>> p = {{1,3},{2,1},{3,2}};
sort(p.begin(), p.end(), [](auto& a, auto& b){
  return a.second < b.second;
});
// p = {{2,1},{3,2},{1,3}}

Binary search on sorted ranges. lower_bound → first element ≥ val. upper_bound → first element > val.

vector<int> v = {1, 2, 4, 4, 6};

// lower_bound returns iterator to first occurrence of 4
auto lo = lower_bound(v.begin(), v.end(), 4);

// upper_bound returns iterator to first element greater than 4
auto hi = upper_bound(v.begin(), v.end(), 4);

// *iterator gives value
cout << "*lo = " << *lo << endl;   // 4
cout << "*hi = " << *hi << endl;   // 6

// iterator - begin() gives index
cout << "Index of lo = " << lo - v.begin() << endl; // 2
cout << "Index of hi = " << hi - v.begin() << endl; // 4

// Number of times 4 appears
int cnt = hi - lo;

cout << "Count of 4 = " << cnt << endl; // 2

Dynamic array. Most common container. O(1) amortized push_back, O(n) insert/erase.

vector<int> v = {1,2,3};

v.push_back(4);     // {1,2,3,4}
v.pop_back();      // {1,2,3}
v.insert(v.begin()+1, 99); // {1,99,2,3}
v.erase(v.begin()+1);     // {1,2,3}
v.resize(5, 0);    // {1,2,3,0,0}
v.assign(3, 7);    // {7,7,7}

map: sorted key-value, O(log n). unordered_map: hash-based, O(1) avg. Use unordered_map for speed.

map<string,int> freq;
freq["apple"]++;  freq["mango"] = 3;

// check existence
if (freq.count("apple")) { /* exists */ }
if (freq.find("apple") != freq.end()) { /* exists */ }

set: sorted unique elements, O(log n). multiset: allows duplicates. unordered_set: O(1) lookup.

set<int> s = {3,1,4,1,5}; // {1,3,4,5}

s.insert(2);   // {1,2,3,4,5}
s.erase(3);    // {1,2,4,5}
s.count(4);    // 1 (exists)

// lower/upper bound work on set too!
auto it = s.lower_bound(3); // points to 4

// multiset — keeps duplicates
multiset<int> ms = {1,2,2,3};
ms.erase(ms.find(2)); // removes ONE 2 → {1,2,3}
ms.erase(2);         // removes ALL 2s!

Stack 
LIFO. Used in DFS, balanced parentheses, monotonic stack problems.

stack<int> st;
st.push(1); st.push(2); st.push(3);
st.top();   // 3
st.pop();   // removes 3
st.size();  // 2
st.empty(); // false

// Monotonic stack — next greater element
vector<int> v = {2,1,5,6,2,3};
stack<int> mono;
vector<int> nge(v.size(), -1);
for (int i = 0; i < v.size(); i++) {
  while (!mono.empty() && v[mono.top()] < v[i]) {
    nge[mono.top()] = v[i]; mono.pop();
  }
  mono.push(i);
}
// nge = {5,5,6,-1,3,-1}

Queue 
queue: FIFO for BFS. deque: double-ended, O(1) push/pop from both ends.

queue<int> q;
q.push(1); q.push(2); q.push(3);
q.front();  // 1
q.back();   // 3
q.pop();    // removes 1, front = 2

// deque — sliding window max
deque<int> dq;
dq.push_back(1);
dq.push_front(0);
dq.pop_back();
dq.pop_front();
dq.front(); dq.back();

Priority Queue 
// max-heap (default)
priority_queue<int> pq;
pq.push(3); pq.push(1); pq.push(5);
pq.top();  // 5
pq.pop();  // removes 5

// min-heap
priority_queue<int, vector<int>, greater<int>> minpq;
minpq.push(3); minpq.push(1);
minpq.top();  // 1

// pair min-heap (Dijkstra style)
priority_queue<
  pair<int,int>,
  vector<pair<int,int>>,
  greater<pair<int,int>>
> dist_pq;
dist_pq.push({0, 1}); // {distance, node}

String 

string s = "Hello World";

s.length() / s.size(); // 11
s.substr(6, 5);         // "World" (start, len)
s.find("World");        // 6 (index)
s.find("xyz");          // string::npos
s.replace(6,5,"C++");   // "Hello C++"
s.insert(5, ",");        // "Hello, C++"
s.erase(5, 1);          // remove 1 char at 5

// conversions
stoi("42");     // string → int
stoll("123");   // string → long long
stod("3.14");   // string → double
to_string(42); // int → string

string s = "abcdefghij";
    
int n = s.length();
reverse(s.begin(),s.end()); // jihgfedcba
cout<<s<<endl;
reverse(s.begin()+2,s.end()); // jiabcdefgh
cout<<s<<endl;
reverse(s.begin()+2,s.end()-1); // jigfedcbah
cout<<s<<endl;

string t = "abcdefghij";
cout<<t<<endl; // abcdefghij
reverse(t.begin()+2,t.begin()+5); // +5 aahe but 4 paryantch reverse hot 1 jast lihaych asa asl tar
cout<<t<<endl; // abedcfghij


string str = " Tanmay is a MSD fan ";
    stringstream ss(str);
    string temp;

    while(ss>>temp){
        cout<<temp<<endl;
    }

min(3, 7);           // 3
max(3, 7);           // 7
min({1,4,2,9,3});   // 1 (initializer list)


// min/max element in array
vector<int> v = {3,1,4,1,5,9};
auto mn = *min_element(v.begin(), v.end()); // 1
auto mx = *max_element(v.begin(), v.end()); // 9

vector<int> v = {1,2,3,4,5};

// sum
int sum = accumulate(v.begin(), v.end(), 0); // 15

// product
int prod = accumulate(v.begin(), v.end(), 1,
  [](int a, int b){ return a * b; }); // 120

// prefix sum array
vector<int> prefix(v.size());
partial_sum(v.begin(), v.end(), prefix.begin());
// prefix = {1,3,6,10,15}

// range sum query with prefix:
// sum(l..r) = prefix[r] - (l>0 ? prefix[l-1] : 0)

vector<int> v = {1,2,3,2,4,2,5};

count(v.begin(), v.end(), 2);  // 3

count_if(v.begin(), v.end(),
  [](int x){ return x % 2 == 0; }); // 4 (even)

auto it = find(v.begin(), v.end(), 3);
// *it = 3

auto it2 = find_if(v.begin(), v.end(),
  [](int x){ return x > 3; });
// *it2 = 4 (first element > 3)


// Left Rotate 
rotate(nums.begin(),nums.begin()+k,nums.end());
// Right Rotate 
std::rotate(nums.begin(),nums.end()-k,nums.end());

// Permutation 
next_permutation(nums.begin(),nums.end());
prev_permutation(nums.begin(), nums.end());

// Binary Search Grid - Flatten 
m = grid[0].size();
row = mid / m;
col = mid % m;

// remove duplicates (array must be sorted first)
vector<int> u = {1,1,2,2,3,3};
sort(u.begin(), u.end());
u.erase(unique(u.begin(), u.end()), u.end());
// u = {1,2,3}


__gcd(12, 8);              // 4
gcd(12, 8);               // 4 (C++17, <numeric>)
lcm(4, 6);                // 12 (C++17)

// absolute value
abs(-5);                  // 5

// power — from <cmath>
pow(2, 10);               // 1024.0 (returns double!)
(int)pow(2, 10);          // cast to int


int x = 12; // binary: 1100

__builtin_popcount(x);   // 2 (number of 1-bits)
__builtin_clz(x);        // 28 (leading zeros, 32-bit)
__builtin_ctz(x);        // 2 (trailing zeros)
__builtin_parity(x);     // 0 (even number of 1s)

// for long long use ll variants
__builtin_popcountll(1LL << 40); // 1

// bit tricks
x & (x-1);   // clear lowest set bit
x & (-x);    // isolate lowest set bit
x | (x+1);   // set lowest 0 bit
(x >> k) & 1; // k-th bit value

// from <limits> or <climits>
int INF = numeric_limits<int>::max();   // 2147483647
int NINF = numeric_limits<int>::min();  // -2147483648

// handy macros from <climits>
INT_MAX;    // 2^31 - 1
INT_MIN;    // -2^31
LLONG_MAX;  // 2^63 - 1
LLONG_MIN;  // -2^63

// common pattern for Dijkstra / DP init
vector<int> dist(n, INT_MAX);
const int INF2 = 1e9; // safer (no overflow on +1)

struct Job { int start, end, profit; };
vector<Job> jobs = {{1,3,50},{2,5,10},{0,6,70}};

// sort by end time
sort(jobs.begin(), jobs.end(),
  [](const Job& a, const Job& b){
    return a.end < b.end;
  });

// multi-key: first by x ascending, then y descending
vector<pair<int,int>> pts = {{1,3},{1,5},{2,1}};
sort(pts.begin(), pts.end(),
  [](auto& a, auto& b){
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second; // y descending
  });

vector<int> a = {100, 5, 300, 5, 200};

vector<int> sorted_unique = a;
sort(sorted_unique.begin(), sorted_unique.end());
sorted_unique.erase(
  unique(sorted_unique.begin(), sorted_unique.end()),
  sorted_unique.end()
);
// sorted_unique = {5,100,200,300}

for (auto& x : a) {
  x = lower_bound(sorted_unique.begin(),
        sorted_unique.end(), x)
      - sorted_unique.begin();
}
// a = {1,0,3,0,2} (0-indexed ranks)





