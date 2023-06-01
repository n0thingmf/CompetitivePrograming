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

ll a,b;
long double fun(ll x){
    return ((long double)b)*x+((long double)1/sqrtl(x+1))*a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//ll a,b;
	cin>>a>>b;
	ll l=0,r=1e18;
	while(l<r){
        ll m=(l+r)/2;
        if(fun(m)<=fun(m+1)) r=m;
        else l=m+1;
	}
	cout << setprecision(12) << fixed;
	//cout<<l<<"\n";
	cout<<fun(l)<<"\n";
	//cout<<fun(l-1)<<"\n";
	//cout<<fun(l+1)<<"\n";
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
