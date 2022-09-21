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

const ll mod=98765431;

ll fpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll inv(ll n){
    return fpow(n,mod-2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,t,s=0;
	cin>>n>>t;
	vector<ll> c(n);
	for(int i=0;i<n;i++) cin>>c[i],s=(s+c[i])%mod;
	ll p=fpow(n-1,t),e=(t%2?-1:1),in=inv(n);
	for(int i=0;i<n;i++){
        ll ans=(p-e+mod)%mod;
        ans=(ans*in)%mod;
        ans=(ans*s)%mod;
        ans=(ans+e*c[i]+mod)%mod;
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
