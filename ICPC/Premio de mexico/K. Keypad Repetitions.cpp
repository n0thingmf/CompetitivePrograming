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

int x[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
ll f(string &s){
    int n=s.size();
    ll ans=0,e=1;
    for(int i=n-1;i>=0;i--,e*=10){
        ans+=x[s[i]-'a']*e;
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	map<ll,int> mp;
	for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[f(s)]++;
	}
	for(int i=0;i<q;i++){
        ll k;
        cin>>k;
        cout<<mp[k]<<"\n";
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
