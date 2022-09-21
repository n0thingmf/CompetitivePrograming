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
#define p pair<ll,ll>
#define x first
#define y second

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        ll minx=LLONG_MAX,maxx=LLONG_MIN,miny=LLONG_MAX,maxy=LLONG_MIN;
        cin>>n;
        set<p> pt;
        for(int i=0;i<n;i++){
            ll x,y;
            cin>>x>>y;
            pt.insert({x,y});
            minx=min(minx,x);
            maxx=max(maxx,x);
            miny=min(miny,y);
            maxy=max(maxy,y);
        }
        p c={minx+maxx,miny+maxy};
        bool ok=true;
        for(auto u:pt){
            p inv;
            inv.x=c.x-u.x;
            inv.y=c.y-u.y;
            if(pt.count(inv)==0) ok=false;
        }
        if(ok) cout<<"yes\n";
        else cout<<"no\n";
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
