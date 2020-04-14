#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

vector<vector<pair<int, int>>> primes;

class Graph {

	private:
		int n, tick, log;
		vector<vector<int>> edges;
		vector<int> tin, tout;
		vector<vector<vector<pair<int, int>>>> cache;
		vector<int> value;

		void depthFirstSearch(int node, int parent) {
			tin[node] = tick;
			tick++;

			if (node != parent) {
				cache[node][0] = primes[value[parent]];
			}
		}


	public:
		Graph(int vertices) {
			n = vertices + 2;
			log = log2(n) + 1;
			edges = vector<vector<int>>(n);
			tin = vector<int>(n);
			tout = vector<int>(n);
			cache = vector<vector<vector<int>>> (n, vector<vector<pair<int, int>>> (log));
		}

		void addedge(int u, int v) {
			edges[u].push_back(v);
			edges[v].push_back(u);
		}

		void 

		void preprocess() {
			tick = 0;
			depthFirstSearch(1, 1);
		}
};

int main() {

	for (int i = 2; i < )

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		Graph G(n);
	}
}