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
const ll mod=998244353;
ll c[5001][5001];

void init(){
    for(int i=0;i<=5000;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || i==j){
                c[i][j]=1;
                continue;
            }
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]%=mod;
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	string s;
	cin>>s;
	int n=s.size();
	vector<ll> f(26,0);
	for(int i=0;i<n;i++){
        f[s[i]-'a']++;
	}
	vector<vector<ll>> dp(26,vector<ll>(n+1,0));
	int sz=f[0];
	for(int i=0;i<=sz;i++){
        dp[0][i]=1;
	}
	for(int i=1;i<26;i++){
        sz+=f[i];
        for(int j=0;j<=sz;j++){
            for(int k=0;k<=f[i] && k<=j;k++){
                dp[i][j]+=(dp[i-1][j-k]*c[j][k])%mod;
                dp[i][j]%=mod;
            }
        }
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
        ans=(ans+dp[25][i])%mod;
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
