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
#define pout cout << fixed << setprecision(12)
double distance(double x1, double y1, double x2, double y2){
    double ans = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return ans;
}

double dist(double x1, double x2, double p , double q){
    double a = x2 - x1;
    double b = distance(x1, 0, p , q);
    double c= distance(x2, 0, p, q);

    return acos((b*b + c*c - a*a)/(2*b*c));
}

int32_t main() { fastio;
    int t;
    cin >> t;

    while(t--){
        int n ;
        cin >> n;

        vector<double> x(n);

        for(int i = 0 ; i < n ; i++){
            cin >> x[i];
        }
        sort(x.begin(),x.end());

        double p , q;

        cin >> p >> q;

        int i = 0 , j = n-1;

        double dista = 0;
        while(i < j){
            dista += dist(x[i] , x[j] , p , q);
            i++;
            j--;
        }

        pout << dista << endl;
    }
    return 0;
}