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
const ll maxn=3e5 + 1;
bool prime[maxn];

void init(){
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(ll i=2;i*i<maxn;i++){
        if(prime[i]){
            for(ll j=i*i;j<maxn;j+=i){
                prime[j]=false;
            }
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	ll n,m;
	cin>>n>>m;
	ll coef=1;
	ll ans=1,tot=1,res=0;
	for(ll i=1;i<=n;i++){
        tot=(tot*(m%mod))%mod;
        if(prime[i]){
            if(coef<=m) coef*=i;
            //else if(coef>LLONG_MAX/i) cout<<coef<<"\n";
        }
        ll pos=m/coef;
        pos%=mod;
        //cout<<coef<<" "<<pos<<"\n";
        ans=(ans*pos)%mod;
        res+=(tot-ans+mod)%mod;
        res%=mod;
	}
	cout<<res<<"\n";
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
