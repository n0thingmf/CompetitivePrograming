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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	map<char,int> mp;
	for(int i=0;i<s.size();i++){
        mp[s[i]]++;
	}
	if(mp.size()==1){
        cout<<"NO\n";
	}else{
        if(s.size()%2==1 && mp[s[s.size()/2]]==1 && mp.size()==2) cout<<"NO\n";
        else cout<<"YES\n";
	}
	}
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
