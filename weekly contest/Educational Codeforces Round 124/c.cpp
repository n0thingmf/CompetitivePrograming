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
        int n;
        cin>>n;
        vector<ll> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        if(n>=3){
            ll ans=LLONG_MAX;
            ans=min(ans,abs(a[0]-b[n-1])+abs(b[0]-a[n-1]));
            ans=min(ans,abs(a[0]-b[0])+abs(b[n-1]-a[n-1]));
            ll u=LLONG_MAX,v=LLONG_MAX,w=LLONG_MAX,x=LLONG_MAX,res=0;
            for(int i=1;i<n-1;i++){
                u=min(u,abs(a[0]-b[i]));
                v=min(v,abs(a[n-1]-b[i]));
                w=min(w,abs(b[0]-a[i]));
                x=min(x,abs(b[n-1]-a[i]));

            }
            ans=min(ans,abs(a[0]-b[0])+x+v);
            ans=min(ans,abs(a[n-1]-b[n-1])+u+w);
            ans=min(ans,abs(a[0]-b[n-1])+w+v);
            ans=min(ans,abs(a[n-1]-b[0])+u+x);
            ans=min(ans,u+v+w+x);
            cout<<ans<<"\n";
        }
	}
	//cout << setprecision(12) << fixed;
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
