#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;
vector<int> prefix_function(string s){
    int n=s.size();
    vector<int> pi(n,0);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[j]!=s[i]) j=pi[j-1];
        j+=s[j]==s[i];
        pi[i]=j;
    }
    return pi;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
    vector<int> pi=prefix_function(s);
	for(int i=0;i<s.size();i++) cout<<pi[i]<<" ";
	return 0;
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* bitwise and boolean operations
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
