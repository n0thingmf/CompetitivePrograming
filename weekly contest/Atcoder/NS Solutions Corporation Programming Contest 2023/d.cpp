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
	ll x,y,z;
	cin>>x>>y>>z;
	string s;
	cin>>s;
	int n=s.size();
	vector<vector<ll>> dp(n+1,vector<ll>(2));
	dp[0][0]=0;
	dp[0][1]=z;
	for(int i=0;i<n;i++){
        if(s[i]=='a'){
            dp[i+1][0]=min(min(dp[i][0]+x,dp[i][1]+z+x),dp[i][1]+y+z);
            dp[i+1][1]=min(dp[i][1]+y,dp[i][0]+x+z);

        }else{
            dp[i+1][1]=min(min(dp[i][1]+x,dp[i][0]+z+x),dp[i][0]+y+z);
            dp[i+1][0]=min(dp[i][0]+y,dp[i][1]+x+z);

        }
	}
	cout<<min(dp[n][0],dp[n][1])<<"\n";
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
