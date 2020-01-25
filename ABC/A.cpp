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
}
bool cmp(string a, string b){
	if(a.length()==b.length()){
		return a.compare(b)<0;
	}
	return a.length()<b.length();
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;cin>>n;
	string arr[n];for(int i = 0 ; i < n ; i ++ )cin>>arr[i];
	sort(arr,arr+n,cmp);
	for(int i = 0 ; i < n;  i ++ )cout<<arr[i]<<en;
	return 0 ; 
}


