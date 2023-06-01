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

ll msqrt(ll x){
    ll l=1,r=1e9;
    while(l<r){
        ll m=(l+r+1)/2;
        if(m*m<=x) l=m;
        else r=m-1;
    }
    return l;
}
ll f(ll x){
    if(x==0) return 0;
    ll r=msqrt(x);
    if(r*r+2*r<=x) return 3+3*(r-1);
    else if(r*r+r<=x) return 2+3*(r-1);
    else return 1+3*(r-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        ll l,r;
        cin>>l>>r;
        cout<<f(r)-f(l-1)<<"\n";
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
