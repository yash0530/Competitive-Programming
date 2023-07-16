#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Monster {
  int health;
  int power;
};

bool isAlive(const Monster& monster) {
  return monster.health > 0;
}

bool compareMonsters(const Monster& a, const Monster& b) {
  return a.power < b.power;
}

string genos_can_kill_monsters(int n, int k, vector<int> h, vector<int> p) {
  vector<Monster> monsters(n);
  for (int i = 0; i < n; i++) {
    monsters[i] = {h[i], p[i]};
  }

  sort(monsters.begin(), monsters.end(), compareMonsters);

  while (any_of(monsters.begin(), monsters.end(), isAlive)) {
    for (auto& monster : monsters) {
      monster.health -= k;
    }

    monsters.erase(remove_if(monsters.begin(), monsters.end(),
                             [](const Monster& m) { return !isAlive(m); }),
                   monsters.end());

    if (monsters.empty()) {
      return "YES";
    }

    k -= monsters.front().power;
  }

  return "NO";
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;

    vector<int> h(n), p(n);
    for (int j = 0; j < n; j++) {
      cin >> h[j] >> p[j];
    }

    cout << genos_can_kill_monsters(n, k, h, p) << endl;
  }

  return 0;
}
