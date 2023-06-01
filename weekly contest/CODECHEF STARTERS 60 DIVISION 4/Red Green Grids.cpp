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
const int maxn=2e3;
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<maxn;i++){
        for(int j=0;j<=i;j++){
            if(i==j || j==0){
                c[i][j]=1;
                continue;
            }
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
	}
	int t;
	cin>>t;
	while(t--){
        int n,m;
        cin>>n>>m;
        if((n+m-1)%2==1){
            cout<<"0\n";
            continue;
        }
        ll ans=(c[n+m-2][n-1]*c[n+m-1][(n+m-1)/2])%mod;
        ans=(ans*fpow(2,n*m-n-m+1))%mod;
        cout<<ans<<"\n";
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
