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
const ll mod = 998244353;
const int maxn=251;

ll c[maxn][maxn];

ll fpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
void init(){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<=i;j++){
            if(i==j || j==0){
                c[i][j]=1;
                continue;
            }
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	//cout<<c[8][3]<<"\n";
	int n,k;
	cin>>n>>k;
	vector<vector<ll>> dp(n,vector<ll>(k));
	for(int i=0;i<k;i++) dp[0][i]=1;

	for(int i=1;i<n;i++){
        dp[i][0]=fpow(k,(i*(i-1))/2);
        for(int j=1;j<k;j++){
            ll big=0,rest=k-j;
            dp[i][j]=dp[i][j-1];
            for(int u=i-1;u>=0;u--){
                big+=u;
                ll cnt=(c[i][u]*dp[u][j-1])%mod;
                if(big!=0) cnt=(cnt*fpow(rest,big))%mod;
                dp[i][j]+=cnt;
                dp[i][j]%=mod;
            }
        }
	}
	/*for(int i=0;i<n;i++){
        for(int j=0;j<k;j++) cout<<dp[i][j]<<" ";
        cout<<"\n";
	}*/
	cout<<dp[n-1][k-1]<<"\n";
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
