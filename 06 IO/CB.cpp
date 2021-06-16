#include <bits/stdc++.h>
using namespace std;

// template <typename T>
// class Stack {
// private:
// 	vector<T> st;

// public:
// 	void push(T val) {
// 		st.push_back(val);
// 	}

// 	void pop() {
// 		if (!isEmpty()) {
// 			st.pop_back();
// 		}
// 	}

// 	T top() {
// 		return st[ st.size() - 1 ];
// 	}

// 	bool isEmpty() {
// 		return (st.size() == 0);
// 	}
// };

int main() {

	// Stack<char> st;

	// for (char c = 'A'; c <= 'F'; c++) {
	// 	st.push(c);
	// }
	// // A B C D E F

	// while (!st.isEmpty()) {
	// 	cout << st.top() << endl;
	// 	st.pop();
	// }

	stack<int> st;

	for (int i = 1; i <= 5; i++) {
		st.push(i * i);
	}
	// 1 4 9 16 25

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}

	return 0;
}
