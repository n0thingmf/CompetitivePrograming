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
const int maxn=2e5+1;

ll f[maxn];
ll fpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll inv(ll a){
    return fpow(a,mod-2);
}
ll comb(ll a,ll b){
    if(b==0) return 1;
    ll down=inv(f[b])*inv(f[a-b]);
    down%=mod;
    return (f[a]*down)%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0]=1;
	for(int i=1;i<maxn;i++) f[i]=(f[i-1]*i)%mod;
	ll n,p;
	cin>>n>>p;
	ll pone=((100-p)*inv(100))%mod;
	ll ptwo=((p)*inv(100))%mod;
	ll ans=0;
	for(ll two=0;two*2<=n;two++){
        ll one=n-two*2;
        ll prod=(fpow(pone,one)*fpow(ptwo,two))%mod;
        prod=(comb(one+two,one)*prod)%mod;
        prod=(prod*(one+two))%mod;
        ans=(ans+prod)%mod;
	}
	for(ll two=0;(two+1)*2<=n+1;two++){
        ll one=n+1-(two+1)*2;
        ll prod=(fpow(pone,one)*fpow(ptwo,two+1))%mod;
        prod=(comb(one+two,one)*prod)%mod;
        prod=(prod*(one+two+1))%mod;
        ans=(ans+prod)%mod;
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
