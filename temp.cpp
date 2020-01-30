#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); //int var=0; //while(var<3) { //fstream fs; //ofstream fo; //fs.open("C:\Users\vaibhav\Desktop\rushil\codeuncode\one\input\input3"+to_string(var)+".txt"); //fo.open("C:\Users\vaibhav\Desktop\rushil\codeuncode\one\output\output3"+to_string(var)+".txt"); int n; cin>>n; //fs>>n; int temp; map mp; priority_queue> pq; for(int i=0;i>temp; //fs>>temp; mp[temp]++; 
} for(auto i:mp) { pq.push(make_pair(i.second,i.first)); } int count=0; vector,int>> ans; while(pq.size()>=3) { count++; pair one = pq.top(); pq.pop(); pair two = pq.top(); pq.pop(); pair three = pq.top(); pq.pop(); one.first--; two.first--; three.first--; if(one.first>0) pq.push(one); if(two.first>0) pq.push(two); if(three.first>0) pq.push(three); } cout<