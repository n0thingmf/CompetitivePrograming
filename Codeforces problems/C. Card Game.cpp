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

const int maxn=61;
const ll mod=998244353;
ll dp[maxn][maxn];
void init(){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<=i;j++){
            if(j==i || j==0){
                dp[i][j]=1;
                continue;
            }
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            dp[i][j]%=mod;
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	//for(int i=0;i<4;i++)
        //for(int j=0;j<4;j++) cout<<dp[i][j]<<"\n";
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        ll tot=dp[n][n/2];
        ll ans=dp[n-1][n/2-1];
        for(int i=(n/2)-3;i>=0;i-=2){
            ans+=dp[i*2+1][i]+dp[i*2+2][i];
            ans%=mod;
        }
        //cout<<ans<<"\n";
        cout<<ans<<" "<<((tot-ans-1)%mod+mod)%mod<<" "<<1<<"\n";
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
