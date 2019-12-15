#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
#include <boost/multiprecision/cpp_dec_float.hpp> 
#include <boost/math/constants/constants.hpp> 
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision;
using namespace std;
#define ll long long int
#define ld long double
#define MAX 10000000
cpp_int powi(ll x, ll y)
{
	cpp_int p = 1;
	for (int i = 0;i < y;i++)
	{
		p = p * x;
		if (p > 10000000)
			break;
	}
	return p;
}
int main() {
	long long int t;cin >> t;while (t--) {
		long long int n;cin >> n;
		string* s = new string[n];
		for (long long int i = 0;i < n;i++) {
			cin >> s[i];
		}
		bool* b = new bool[n];
		for (long long int i = 0;i < n;i++) {
			long long int countvowel = 0;
			long long int j = 0;
			for (j = 0;j < s[i].length();j++) {
				if (s[i][j] != 'a' && s[i][j] != 'e' && s[i][j] != 'i' && s[i][j] != 'o' && s[i][j] != 'u') {
					if ((j != s[i].length() - 1) && s[i][j + 1] != 'a' && s[i][j + 1] != 'e' && s[i][j + 1] != 'i' && s[i][j + 1] != 'o' && s[i][j + 1] != 'u') {
						break;
					}
					else continue;
				}
				if (s[i][j] == 'a' || s[i][j] == 'e' || s[i][j] == 'i' || s[i][j] == 'o' || s[i][j] == 'u') {
					if ((j!=s[i].length()-1)&&j!=0&&s[i][j + 1] != 'a' && s[i][j + 1] != 'e' && s[i][j + 1] != 'i' && s[i][j + 1] != 'o' && s[i][j + 1] != 'u' && s[i][j - 1] != 'a' && s[i][j - 1] != 'e' && s[i][j - 1] != 'i' && s[i][j - 1] != 'o' && s[i][j - 1] != 'u')break;
				}
				countvowel++;
			}
			if (j == s[i].length()) {
				if (s[i].length() & 1) {
					if (countvowel >= s[i].length() / 2 + 1)b[i] = false;
					else b[i] = true;
				}
				else {
					if (countvowel >= s[i].length() / 2)b[i] = false;
					else b[i] = true;
				}
			}
			else b[i] = true;
		}
		long long int freqA[27] = { 0 };
		long long int freqB[27] = { 0 };
		long long int freqA1[27] = { 0 };
		long long int freqB1[27] = { 0 };
		cpp_dec_float_100 xaprod = 1;
		cpp_dec_float_100 xbprod = 1;
		long long int N=0, M=0;
		for (long long int i = 0;i < n;i++) {
			if (b[i] == false) {
				long long int tempflagA[27] = { 0 };
				N++;
				for (long long int j = 0;j < s[i].length();j++) {
					freqA[s[i][j] - 'a']++;
					tempflagA[s[i][j] - 'a']++;
				}
				for (long long int i = 0;i < 26;i++) {
					if (tempflagA[i] != 0)freqA1[i]++;
				}
			}
			if (b[i] == true) {
				long long int tempflagB[27] = { 0 };
				M++;
				for (long long int j = 0;j < s[i].length();j++) {
					freqB[s[i][j] - 'a']++;
					tempflagB[s[i][j] - 'a']++;
				}
				for (long long int i = 0;i < 26;i++) {
					if (tempflagB[i] != 0)freqB1[i]++;
				}
			}
		}
		for (long long int i = 0;i < 26;i++) {
			if(freqA1[i]!=0)
			xaprod = (cpp_dec_float_100)(xaprod * ((cpp_dec_float_100)freqA1[i] / (cpp_dec_float_100)(powi(freqA[i], N))));
		}
		for (long long int i = 0;i < 26;i++) {
			if (freqB1[i] != 0)
			xbprod = (cpp_dec_float_100)(xbprod * ((cpp_dec_float_100)freqB1[i] / (cpp_dec_float_100)(powi(freqB[i], M))));
		}
		if(N==0)xaprod=0;
		cpp_dec_float_100 ans=xaprod/xbprod;
		if (ans > (cpp_dec_float_100) MAX||M==0)cout << "Infinity" << endl;
		else cout << std::fixed << std::setprecision(7) << ans << endl;
	}
}