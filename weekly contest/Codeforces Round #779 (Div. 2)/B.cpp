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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> f(501);
	f[0]=1;
	for(ll i=1;i<=500;i++) f[i]=(f[i-1]*i)%mod;
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        if(n%2) cout<<"0\n";
        else{
            ll ans=(f[n/2]*f[n/2])%mod;
            cout<<ans<<"\n";
        }
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
