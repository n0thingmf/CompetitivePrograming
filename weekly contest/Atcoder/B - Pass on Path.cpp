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
	int n,l;
	cin>>n>>l;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ll ans=2*l,delta=LLONG_MAX;
	for(int i=0;i<n;i++){
        ll x=a[i],y=l-a[i];
        int j=lower_bound(all(a),y)-a.begin();
        if(j==n){
            delta=min(delta,(y-a[j-1]));
        }else if(j==0){
            delta=min(delta,a[0]-y);
        }else{
            ll d1=a[j]-y,d2=y-a[j-1];
            delta=min(delta,min(d1,d2));
        }
	}
	cout<<ans+2*delta<<"\n";
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
