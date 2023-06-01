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

ll f(ll x){
    if(x<=9) return x*(x+1)/2;
    return 45*(x/10)+(x%10)*(x%10+1)/2+f(x/10);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll l,r;
	while(cin>>l>>r && l>=0 && r>=0){
        if(l==0) cout<<f(r)<<"\n";
        else cout<<f(r)-f(l-1)<<"\n";
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
