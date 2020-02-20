#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

struct lib {
  int books, signup, books_perday, total_score;
};

// comparator for Libraries
bool comp_library(pair<int, lib> a, pair<int, lib> b) {
  
	double scoreA, scoreB, booksA,booksB;
	scoreA=a.second.total_score;scoreB=b.second.total_score;booksA=a.second.books;booksB=b.second.books;
	return (scoreA/booksA)*a.second.books_perday > (scoreB/booksB)*b.second.books_perday;
}

// comparator for Libraries, based on signup days
bool comp_library_signup(pair<int, lib> a, pair<int, lib> b) {
	return a.second.signup < b.second.signup;
}

// comparator for books
bool comp_book(pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}

int32_t main() { fastio;

  // no of books, libraries, days  
  int B, L, D;

  cin >> B >> L >> D;
  vector<int> books(B);
  for (int i = 0; i < B; i++) {
    cin >> books[i];
  }
  int a, b, c;

  // contains metadata for all libraries
  vector<pair<int, lib>> library(L);

  // conatins array of books id for all libraries
  vector<vector<pair<int, int>>> books_libs(L);
  
  for (int i = 0; i < L; i++) {
    cin >> a >> b >> c;
    library[i] = { i, { a, b, c, 0 } };
    vector<pair<int, int>> books_lib(a);
    
    for (int i = 0; i < a; i++) {
      cin >> books_lib[i].first;
      books_lib[i].second = books[books_lib[i].first];
    }
    int sum = 0;
    for (auto bl : books_lib) {
      sum += bl.second;
    }
    library[i].second.total_score = sum;
    
    sort(books_lib.begin(), books_lib.end(), comp_book);
    books_libs[i] = books_lib;
  }

  //Sort Library using the Estimated Total second for each Library 
  sort(library.begin(), library.end(), comp_library);

  int count = 0, days = 0;
  for (auto l : library) {
    days += l.second.signup;
    if (D < days) {
      break;
    }
    count++;
  }

  // This gives the no of libraries that can be signed up
  cout << count << endl;
  int days_past = 0;
  for (auto l : library) {
    cout << l.first << " ";
    days_past += l.second.signup;
    int days_rem = D - days_past;
    int books_can_send = min(days_rem * l.second.books_perday, (int) books_libs[l.first].size());
    cout << books_can_send << endl;
    for (int  i = 0; i < books_can_send; i++) {
      cout << books_libs[l.first][i].first << " ";
    } cout << endl;
  }
  
  return 0;
}