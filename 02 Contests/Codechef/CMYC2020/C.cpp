// CPP program to find the kth smallest element in a range 
#include <bits/stdc++.h> 
using namespace std; 
#define N (int)5e5 

// Declaring a global segment tree 
vector<int> seg[N]; 

// Function to build the merge sort 
// segment tree of indices 
void build(int ci, int st, int end, 
		pair<int, int>* B) 
{ 
	if (st == end) { 
		// Using second property of B 
		seg[ci].push_back(B[st].second); 
		return; 
	} 

	int mid = (st + end) / 2; 
	build(2 * ci + 1, st, mid, B); 
	build(2 * ci + 2, mid + 1, end, B); 

	// Inbuilt merge function 
	// this takes two sorted arrays and merge 
	// them into a sorted array 
	merge(seg[2 * ci + 1].begin(), seg[2 * ci + 1].end(), 
		seg[2 * ci + 2].begin(), seg[2 * ci + 2].end(), 
		back_inserter(seg[ci])); 
} 

// Function to return the index of 
// kth smallest element in range [l, r] 
int query(int ci, int st, int end, 
		int l, int r, int k) 
{ 
	// Base case 
	if (st == end) 
		return seg[ci][0]; 

	// Finding value of 'p' as described in article 
	// seg[2*ci+1] is left node of seg[ci] 
	int p = upper_bound(seg[2 * ci + 1].begin(), 
						seg[2 * ci + 1].end(), r) 
			- lower_bound(seg[2 * ci + 1].begin(), 
						seg[2 * ci + 1].end(), l); 

	int mid = (st + end) / 2; 
	if (p >= k) 
		return query(2 * ci + 1, st, mid, l, r, k); 
	else
		return query(2 * ci + 2, mid + 1, end, l, r, k - p); 
} 

// Driver code 
int main() 
{ 
	int n = 1e5 + 5;

	int arr[n];
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i < n; i++) {
		arr[i] = arr[i - 1] ^ i;
	}
	// for (int i = 0; i <= 10; i++) cerr << arr[i] << " ";

	pair<int, int> B[n]; 

	for (int i = 0; i < n; i++) { 
		B[i] = { arr[i], i }; 
	} 

	// After sorting, B's second property is 
	// something upon which we will build our Tree 
	sort(B, B + n); 

	// Build the tree 
	build(0, 0, n - 1, B); 

	int t; cin >> t;
	while (t--) {
		int x, k;
		cin >> x >> k;

		if (x > 1e5 or k > x or k < 1 or x < 1) {
			cout << -1 << endl;
			continue;
		}

		cout << arr[query(0, 0, n - 1, 1, x, x - k + 1)] << endl;
	}
} 
