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

ll solve(ll n,ll g){
    ll k=n/g;
    return n*(k-1)/2 + k;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> f;
	for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            if(i*i!=n){
                f.pb(solve(n,i));
                f.pb(solve(n,n/i));
            }else{
                f.pb(solve(n,i));
            }
        }
	}
	sort(all(f));
	for(ll x:f){
        cout<<x<<" ";
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
