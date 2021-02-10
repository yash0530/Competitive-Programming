// Statically verifying Monty Hall Problem

#include <bits/stdc++.h>
using namespace std;

int doors, games;

// getting input for number of doors and games
void getInput() {
	int t = 0;
	while (t < 3) {
		cout << "Enter vaild door count: ";
		cin >> t;
	}
	doors = t;
	t = 0;
	while (t < 1) {
		cout << "Enter valid game count: ";
		cin >> t;
	}
	games = t;
}

int main() {
	getInput();
	int won = 0;
	for (int i = 0; i < games; i++) {
		srand(chrono :: steady_clock :: now().time_since_epoch().count());
		int prize = rand() % doors;
		int chose = rand() % doors;
		if (prize != chose) {
			won++;
		}
	}
	cout << "Wins: " << won << endl;
	cout << "Win Percent Expected: " << ((double) (doors - 1) / (doors)) * 100 << endl;
	cout << "Win Percent Statical: " << ((double) (won) / games) * 100 << endl;
}