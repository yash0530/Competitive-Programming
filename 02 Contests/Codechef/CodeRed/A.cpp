#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
    	ll n;
    	cin>>n;
    	ll a[n];
    	for(ll i=0;i<n;i++)cin>>a[i];
    	if(n==1)cout<<a[0]<<endl;
    	else cout<<max(a[0],a[n-1])<<endl;
	}
	
return 0;
}
