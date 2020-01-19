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

int32_t main() { fastio;
    int t;
    cin >> t;
    while(t--){
        vector<vector<char> > arr(3,vector<char>(3));

        for(int i = 0; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                cin >> arr[i][j];
            }
        }

        bool poss = false;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(arr[i][j] == 'l' && i+1 < 3 && arr[i+1][j] == 'l' && j+1 < 3 && arr[i+1][j+1] == 'l'){
                    poss = true;
                    break;
                }
            }
        }
        if(poss)
            cout <<"yes\n";
            
        else
            cout << "no\n";
        
    }
    return 0;
}