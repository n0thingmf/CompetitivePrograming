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
	int n,m;
	cin>>n;
	ll sum=0;
	vector<ll> a(n);
	for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
	}
	sort(all(a));
	cin>>m;
	while(m--){
        ll x,y;
        cin>>x>>y;
        int k=lower_bound(all(a),x)-a.begin();
        if(k==0){
            cout<<max(0ll,x-a[0])+max(0ll,y-sum+a[0])<<"\n";
        }else if(k==n){
            cout<<max(0ll,x-a[n-1])+max(0ll,y-sum+a[n-1])<<"\n";
        }else{
            ll o1=max(0ll,x-a[k-1])+max(0ll,y-sum+a[k-1]),o2=max(0ll,x-a[k])+max(0ll,y-sum+a[k]);
            cout<<min(o1,o2)<<"\n";
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
