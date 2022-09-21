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

const int maxn=1e5;
const ll mod=1000000007;

ll fact[maxn+1];

ll fpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll inv(ll x){
    return fpow(x,mod-2);
}

ll comb(ll a,ll b){
    if(a<b || b<0) return 0;
    ll ans=(fact[a]*inv(fact[b]))%mod;
    return (ans*inv(fact[a-b]))%mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	fact[0]=1;
	for(ll i=1;i<=maxn;i++) fact[i]=(fact[i-1]*i)%mod;
	int t;
	cin>>t;
	while(t--){
        ll A,B,C,K,c;
        cin>>A>>B>>C>>K>>c;
        ll ans=comb(A+B,K-c)-comb(A,K-c)-comb(B,K-c);
        ans=ans%mod;
        ans=(ans+mod)%mod;
        //ans=(ans-comb(A,K-c)+mod)%mod;
        //ans=(ans-comb(B,K-c)+mod)%mod;
        ans=(ans*comb(C,c))%mod;
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
