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

ll solve(ll o,ll e){
    ll ans=0;
        if(o>e){
            ans=2*o-1;
        }else{
            ll delta=(e-o)/3;
            e-=delta;
            o+=2*delta;
            if(o>e) ans=2*o-1;
            else ans=2*e;
            e-=1;
            o+=2;
            if(e>=0){
                if(o>e) ans=min(ans,2*o-1);
                else ans=min(ans,2*e);
            }
        }
        return ans;

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,mh=0;
        ll ans;
        cin>>n;
        vector<int> h(n);
        for(int i=0;i<n;i++) cin>>h[i],mh=max(mh,h[i]);
        ll o=0,e=0;
        for(int i=0;i<n;i++){
            o+=(mh-h[i])&1;
            e+=(mh-h[i])>>1;
        }
        ans=solve(o,e);
        o=0,e=0;
        for(int i=0;i<n;i++){
            o+=(mh+1-h[i])&1;
            e+=(mh+1-h[i])>>1;
        }
        ans=min(ans,solve(o,e));
        cout<<ans<<"\n";
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
