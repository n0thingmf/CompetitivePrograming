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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	int q;
	cin>>n>>m>>q;
	ll g=__gcd(n,m);
	while(q--){
        ll sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        ll cmp1,cmp2;
        if(sx==1){
            cmp1=(sy-1)/(n/g);
        }else{
            cmp1=(sy-1)/(m/g);
        }
        if(ex==1){
            cmp2=(ey-1)/(n/g);
        }else{
            cmp2=(ey-1)/(m/g);
        }
        if(cmp1==cmp2) cout<<"YES\n";
        else cout<<"NO\n";
	}
	cout << setprecision(12) << fixed;
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