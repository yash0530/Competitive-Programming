#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 
ll MaxSumDifference(ll a[], ll n) { 
    vector<ll> finalSequence;  
    sort(a, a + n); 
   
    for (ll i = 0; i < n / 2; ++i) { 
        finalSequence.push_back(a[i]); 
        finalSequence.push_back(a[n - i - 1]); 
    } 
   
    if (n % 2 != 0) 
        finalSequence.push_back(a[n/2]); 
 
    ll MaximumSum = 0; 
 
    ll minSub=INT_MAX;
  
    for (ll i = 0; i < n - 1; ++i) { 
        MaximumSum = MaximumSum + abs(finalSequence[i] -  
                                  finalSequence[i + 1]);
        minSub = min(abs(finalSequence[i] -  
                                  finalSequence[i + 1]), minSub); 
    } 
  
  
    MaximumSum = MaximumSum + abs(finalSequence[n - 1] - 
                                      finalSequence[0]);
 
    minSub = min(abs(finalSequence[n - 1] - 
                                      finalSequence[0]), minSub);                 
                                
    
    MaximumSum = MaximumSum - minSub;
  
    // return the value 
    return MaximumSum; 
}
 
int main(){
  fastio
  ll n;
  cin>>n;
  ll a[n];
  for(ll i=0; i<n; i++){
    cin>>a[i];
  }
  ll ans = MaxSumDifference(a,n);
  cout<<ans<<"\n";
  return 0; 
}