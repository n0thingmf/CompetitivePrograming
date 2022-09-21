#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numAero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;

const ll mod=998244353;
int n;
string s;
vector<ll> dp;
string dfs(int v,int level){
    string ans(1,s[v]);
    if(level==n){
        dp[v]=1;
        return ans;
    }
    string u1=dfs(2*v+1,level+1),u2=dfs(2*v+2,level+1);
    if(u1==u2) dp[v]=(dp[2*v+1]*dp[2*v+2])%mod;
    else dp[v]=(dp[2*v+1]*dp[2*v+2]*2)%mod;
    return min(ans+u1+u2,ans+u2+u1);
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>s;
	dp.resize(1<<n,0);
	dfs(0,1);
	cout<<dp[0]<<"\n";
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
