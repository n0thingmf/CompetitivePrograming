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
	int n;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ll ans=LLONG_MAX;
	for(int k=0;k<n;k++){
        ll res=0;
        vector<ll> b(n,0);
        for(int i=k-1;i>=0;i--){
            ll cnt=(-b[i+1])/a[i]+1;
            res+=cnt;
            b[i]=-a[i]*cnt;
        }
        for(int i=k+1;i<n;i++){
            ll cnt=(b[i-1])/a[i]+1;
            res+=cnt;
            b[i]=a[i]*cnt;
        }
        ans=min(ans,res);
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
