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

const int maxn=5e3+1;
ll mod;

ll fact[maxn];
ll ifact[maxn];

ll fpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll comb(ll a,ll b){
    if(b==0) return 1;
    ll ans=(fact[a]*ifact[b])%mod;
    return (ans*ifact[a-b])%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n>>mod;

	fact[0]=1;
	for(int i=1;i<maxn;i++) fact[i]=(fact[i-1]*i)%mod;
	ifact[maxn-1]=fpow(fact[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--) ifact[i]=(ifact[i+1]*(i+1))%mod;
    //cout<<ifact[0]<<"\n";
	ll ans=0;
	for(int d=(n+2)/2,e=n/2;d<=n && e>0;d++,e--){
        for(int f=0;f<max(1,n-d);f++){
            int x=n-d-1;
            ll res=(1ll*e*n*comb(x,f))%mod;
            ll points=d==n?2:3;
            res*=fact[n-points-f];
            res%=mod;
            //cout<<fact[n-points-f]<<" "<<f<<" ff\n";
            //cout<<"res "<<res<<"\n";
            ans=(ans+res)%mod;
        }
        //cout<<d<<" "<<e<<"\n";
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
