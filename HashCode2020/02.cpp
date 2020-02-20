#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int)(1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x)           \
    cout << #x << "\n";   \
    for (auto a : x)      \
        cout << a << " "; \
    cout << "\n";
#define debm(x)               \
    cout << #x << "\n";       \
    for (auto a : x)          \
    {                         \
        for (auto b : a)      \
            cout << b << " "; \
        cout << "\n";         \
    }
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int>(m, val))
#define fastio                         \
    ios_base ::sync_with_stdio(false); \
    cin.tie(nullptr);                  \
    cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

struct lib
{
    int books, signup, books_perday, total_score;
};

// comparator for Libraries
bool comp_library(pair<int, lib> a, pair<int, lib> b)
{

    double scoreA, scoreB, booksA, booksB;
    scoreA = a.second.total_score;
    scoreB = b.second.total_score;
    booksA = a.second.books;
    booksB = b.second.books;
    return (scoreA / booksA) * a.second.books_perday > (scoreB / booksB) * b.second.books_perday;
}

int getScore(pair<int, lib> a) {
    double scoreA, scoreB, booksA, booksB;
    scoreA = a.second.total_score;
    booksA = a.second.books;
    return (scoreA / booksA) * a.second.books_perday;
}

// comparator for Libraries, based on signup days
bool comp_library_signup(pair<int, lib> a, pair<int, lib> b)
{
    //  return (rand() % 2>0?true:false);
    return a.second.signup < b.second.signup;
    // return a.second.signup*b.second.books < b.second.signup*a.second.books;
    // return a.second.books * a.second.books_perday/a.second.signup > b.second.books* b.second.books_perday/a.second.signup;
}

// comparator for Libraries, based on signup days
bool comp_library_signup_new(pair<int, lib> a, pair<int, lib> b)
{
    //  return a.second.signup < b.second.signup;
    return a.second.signup * b.second.books < b.second.signup * a.second.books;
}

// comparator for books
bool comp_book(pair<int, int> a, pair<int, int> b)
{
    // return (rand() % 2>0?true:false);
    return a.second > b.second;
    // return a.first > b.first;
}

int32_t main()
{
    fastio;
    srand(time(NULL));

    // no of books, libraries, days
    int B, L, D;

    cin >> B >> L >> D;
    vector<int> books(B);

    vector<bool> used(B);

    for (int i = 0; i < B; i++)
    {
        cin >> books[i];
    }
    int a, b, c;
    // contains metadata for all libraries
    vector<pair<int, lib>> library(L);

    // conatins array of books id for all libraries
    vector<vector<pair<int, int>>> books_libs(L);

    for (int i = 0; i < L; i++)
    {
        cin >> a >> b >> c;
        library[i] = {i, {a, b, c, 0}};
        vector<pair<int, int>> books_lib(a);

        for (int i = 0; i < a; i++)
        {
            cin >> books_lib[i].first;
            books_lib[i].second = books[books_lib[i].first];
        }
        int sum = 0;
        for (auto bl : books_lib)
        {
            sum += bl.second;
        }
        library[i].second.total_score = sum;

        sort(books_lib.begin(), books_lib.end(), comp_book);
        books_libs[i] = books_lib;
    }

    //Sort Library using the Estimated Total second for each Library
    sort(library.begin(), library.end(), comp_library_signup_new);

    int count = 0, days = 0;
    int threshold = 20;
    for (auto l : library)
    {
        days += l.second.signup;
        if (D < days)
        {
            break;
        }
        count++;
    }

    int score = 0;

    // This gives the no of libraries that can be signed up
    cout << count << endl;
    int days_past = 0;
    for (auto l : library)
    {
        days_past += l.second.signup;
        int days_rem = D - days_past;
        if (days_rem > 0)
        {
            int books_can_send = min(days_rem * l.second.books_perday, (int)books_libs[l.first].size());
            // cout << books_can_send << endl;
            vector<int> res;
            for (int i = 0, j = 0; j < books_can_send and i < books_libs[l.first].size(); i++)
            {
                // cout << books_libs[l.first][i].first << " ";

                    if (!used[books_libs[l.first][i].first]) {
                        used[books_libs[l.first][i].first] = true;
                        res.push_back(books_libs[l.first][i].first);
                        score += books_libs[l.first][i].second;
                        j++;
                    }
                    
            }
            if (res.size() != 0) {
                cout << l.first << " " << res.size() << endl;
                for (auto r : res) {
                    cout << r << " ";
                }
                cout << endl;
            } else {
                // cout << 1 << endl;
                // cout << books_libs[l.first][0].first << endl;
                days_past -= l.second.signup;
            }
        }
    }

    //   deb(score);
    cerr << score << endl;

    return 0;
}