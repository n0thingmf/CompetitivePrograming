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
	int t;
	cin>>t;
	while(t--){
        ll n,s=0;
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin>>a[i],s+=a[i];

        if((2*s)%n==0){
            ll k=(2*s)/n,ans=0;
            map<ll,ll> f;
            for(int i=0;i<n;i++){
                ans+=f[k-a[i]];
                f[a[i]]++;
            }
            cout<<ans<<"\n";
        }else cout<<"0\n";
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
