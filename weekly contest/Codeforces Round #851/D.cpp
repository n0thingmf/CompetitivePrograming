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

const ll mod = 1e9+7;
ll fpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<int> dpow(n+1);
	dpow[0]=1;
	for(int i=1;i<=n;i++) dpow[i]=(dpow[i-1]*2)%mod;
	vector<ll> x(n);
	for(int i=0;i<n;i++) cin>>x[i];
	ll ans=(fpow(2,n)-n-1+mod)%mod;
	for(int i=1;i<n;i++){
        int l=i,r=i+1;
        for(int j=i+1;j<n-1;j++){
            ll d=x[j]-x[i];
            r=max(r,j);
            while(l>=1 && x[i]-x[l-1]<=d){
                l--;
            }
            while(r+1<n && x[r+1]-x[j]<d){
                r++;
            }
            ll delta1=(dpow[i]-dpow[l]+mod)%mod;
            ll delta2=(dpow[n-1-j]-dpow[2,n-1-r]+mod)%mod;
            ans+=(delta1*delta2)%mod;
            ans%=mod;
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
