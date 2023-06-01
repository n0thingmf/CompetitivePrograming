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
	int n;
	cin>>n;
	ll dp[2];
	dp[0]=dp[1]=-1;
	ll ans=-1;
	for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if((x&1)==1 && dp[1]!=-1) ans=max(ans,x+dp[1]);
        if((x&1)==0 && dp[0]!=-1) ans=max(ans,x+dp[0]);
        dp[x&1]=max(dp[x&1],x);
	}
	cout<<ans<<"\n";
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
