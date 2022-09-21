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
const ll mod=1e9 +7 ;
const int maxn=1e6;
ll dp[maxn+1];

void init(){
    memset(dp,0,sizeof(dp));
    ll totnak=2;
    for(int i=1;i<=maxn;i++){
        for(int j=i*2;j<=maxn;j+=i){
            dp[j]=dp[j]+totnak-dp[i];
            dp[j]%=mod;
            dp[j]=(dp[j]+mod)%mod;
        }
        totnak=(totnak*2)%mod;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();

	int t;
	cin>>t;
	while(t--){
        int k;
        cin>>k;
        cout<<dp[k]<<"\n";
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
