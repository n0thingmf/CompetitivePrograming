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

const ll mod=1e9+7;
const ll maxn=1e6+1;
ll f[maxn];
ll p3[maxn];

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

ll fact(ll a){
    return f[a];
}
ll comb(ll a,ll b){
    if(b==0) return 1;
    if(b<0 || a<b) return 0;
    ll ans=inv(((fact(b)*fact(a-b)))%mod);
    return (ans*fact(a))%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0]=1;
	for(ll i=1;i<maxn;i++) f[i]=(f[i-1]*i)%mod;
	p3[0]=1;
	for(ll i=1;i<maxn;i++) p3[i]=(p3[i-1]*3)%mod;
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	if(k==0){
        ans=p3[n];
	}
	for(int m=1;m<=k;m++){
        ll pw;
        if(n-2*m>=0){
            pw=p3[n-2*m]%mod;
            pw=(pw*comb(k-1,m-1))%mod;
            pw=(pw*comb(n-k,m))%mod;
            ans=(ans+pw)%mod;
        }
        if(n-2*m+1>=0){
            pw=p3[n-2*m+1]%mod;
            pw=(pw*comb(k-1,m-1))%mod;
            pw=(pw*comb(n-k,m-1))%mod;
            ans=(ans+pw)%mod;
        }
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
