#include<bits/stdc++.h>    
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define pb push_back
#define inf 1e16
#define mod 1000000007
#define en '\n'
ll pw(ll b, ll r){
	ll ans = 1;
	while(r){
		if(r&1)ans = (ans*b)%mod;
		b = (b*b)%mod;
		r>>=1;
	}
	return ans;
}ll extended_euclidean(ll a, ll b, ll & x, ll & y) {
   if (a == 0) {
       x = 0;
       y = 1;
       return b;
   }
   ll x1, y1;
   ll d = extended_euclidean(b % a, a, x1, y1);
   x = y1 - (b / a) * x1;
   y = x1;
   return d;
}
 
ll modInv(ll a, ll m) {
   ll x, y;
   if (extended_euclidean(a, m, x, y) != 1)
       return -1;
   x = (x % m + m) % m;
   return x;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;cin>>n;
	ll ans = 1;
	ll arr[n][3];
	for(ll i = 0 ; i < n ; i ++ ){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
		ans = (ans*pw(arr[i][0],arr[i][1]))%mod;
	}
	for(ll i = 0; i < n; i ++ ){
		ll num = 1+(arr[i][2]-arr[i][1]!=0?pw(arr[i][0],arr[i][2]-arr[i][1]):0);
		num%=mod;
		ans = (ans*num)%mod;
	}
	cout<<ans<<en;
	return 0 ; 
}