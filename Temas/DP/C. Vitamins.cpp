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

const ll inf=1e12;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll> c(n);
	vector<int> v(n,0);
	for(int i=0;i<n;i++){
        cin>>c[i];
        string s;
        cin>>s;
        for(char x:s) v[i]|=1<<(x-'A');
	}
	//for(int i=0;i<n;i++) cout<<v[i]<<"\n";
	vector<ll> dp(1<<3,inf);
    dp[v[0]]=c[0];
    dp[0]=0;
	for(int i=1;i<n;i++){
        for(int j=0;j<(1<<3);j++){
            dp[j|v[i]]=min(dp[j|v[i]],dp[j]+c[i]);
        }
	}
	if(dp[(1<<3)-1]==inf) cout<<"-1\n";
	else cout<<dp[(1<<3)-1]<<"\n";
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
