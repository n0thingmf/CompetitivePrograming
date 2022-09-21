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

const ll mod=1e9 +7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s,b;
	cin>>s>>b;
	b-=s;
	vector<vector<ll>> dp(s+1,vector<ll>(b+1,0));
	dp[0][0]=1;
	for(int j=0;j<=b;j++) dp[1][j]=1;
	for(int i=2;i<=s;i++){
        dp[i][0]=1;
        for(int j=1;j<=b;j++){
            dp[i][j]=(2*dp[i-1][j]-dp[i-2][j])%mod;
            dp[i][j]=(dp[i][j]+mod)%mod;
            if(j>=i) dp[i][j]=(dp[i][j]+dp[i][j-i])%mod;
        }
	}
	cout<<dp[s][b]<<"\n";
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
