#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

struct lib {
  int signup, books_perday;
  vector<int> books_ids;
};

int D;
vector<int> books_scores;
unordered_set<int> alreadySelected;

int sum_of_scores_by_id(vector<int> book_ids) {
  int sum = 0;
  for(auto i : book_ids) {
    sum += books_scores[i];
  }
  return sum;
}

bool bookSorter(int id1, int id2) {
  return books_scores[id1] > books_scores[id2];
}
vector<int> getBestAllowedFromSortedBooks(vector<int> ids, int allowed_num) {
  vector<int> v;
  for(int id : ids) {
    if(alreadySelected.count(id) == 0) {
      v.push_back(id);
    }
  }
  return v;
  // return vector<int> (l.books_ids.begin(), l.books_ids.begin() + allowed_num);
}

vector<int> getBestBooksIds(lib l) {
  if(D <= l.signup) {
    return vector<int>();
  } else if(D >= l.signup + (l.books_ids.size() / l.books_perday)) {
    return l.books_ids;
  } else {
    int allowed_num = (D - l.signup) * l.books_perday;
    sort(l.books_ids.begin(), l.books_ids.end(), bookSorter);
    return getBestAllowedFromSortedBooks(l.books_ids, allowed_num);
    // return vector<int> (l.books_ids.begin(), l.books_ids.begin() + allowed_num);
  }
}
int getDays(lib l) {
  if(D <= l.signup) {
    return D;
  } else if(D >= l.signup + (l.books_ids.size() / l.books_perday)) {
    return l.signup + (l.books_ids.size() / l.books_perday);
  } else {
    return D;
  }
}
// comparator for Libraries
bool comp_library_asc_importance(pair<int, lib> a, pair<int, lib> b) {
	lib lib1 = a.second;
  lib lib2 = b.second;
  double score1 = sum_of_scores_by_id(getBestBooksIds(lib1)) / (double)getDays(lib1);
  double score2 = sum_of_scores_by_id(getBestBooksIds(lib2)) / (double) getDays(lib2);
  return score1 < score2;
}

int32_t main() { fastio;
  // no of books, libraries, days
  int B, L;
  cin >> B >> L >> D;
  
  // books_scores.resize(B);
  for (int i = 0; i < B; i++) {
    int t;
    cin >> t;
    books_scores.push_back(t);
    // cin >> books_scores[i];
  }
  int a, b, c;

  // contains metadata for all libraries
  // index and struct of lib
  vector<pair<int, lib>> libraries(L);
  
  for (int i = 0; i < L; i++) {
    cin >> a >> b >> c;
    libraries[i] = { i, {b, c, vector<int>()} };
    
    for (int j = 0; j < a; j++) {
      int t;
      cin>>t;
      libraries[i].second.books_ids.push_back(t);
    }
  }

// INPUT DONE
  vector<pair<int, vector<int> > > selected;
  // D is days rem
  while(D>0) {
    sort(libraries.begin(), libraries.end(), comp_library_asc_importance);
    pair<int, lib> l_chosen = libraries.back();
    libraries.pop_back();
    int lib_id = l_chosen.first;
    lib l = l_chosen.second;
    vector<int> best = getBestBooksIds(l);
    if(best.size() == 0) {
      break;
    }
    alreadySelected.insert(best.begin(), best.end());
    selected.push_back({ lib_id, best });
    if(selected.size() == L) {
      break;
    }
    D -= l.signup;

    // Opt1. Delete books selected
    // Opt2. Select one with lesser waiting time. But will require some forsight
  }

  // OUTPUT
  cout<<selected.size()<<endl;
  for(auto temp: selected) {
    cout<<temp.first<<" "<<temp.second.size()<<endl;
    for(int book_id : temp.second) {
      cout<<book_id<<" ";
    }
    cout<<endl;
  }
  
  // DEBUG SCORE
  int score = 0;
  for(auto s: alreadySelected) {
    score += books_scores[s];
  }
  deb(score);
    // cerr << score << endl;
  
  return 0;
}