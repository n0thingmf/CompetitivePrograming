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
        ll n,c,q;
        cin>>n>>c>>q;
        string s;
        cin>>s;
        vector<ll> sz(c);
        vector<pair<ll,ll>> cs(c);
        for(int i=0;i<c;i++) cin>>cs[i].first>>cs[i].second;
        sz[0]=s.size();
        for(int i=0;i<c-1;i++) sz[i+1]=sz[i]+cs[i].second-cs[i].first+1;
        while(q--){
            ll x;
            cin>>x;
            for(int i=c-1;i>=0;i--){
                if(x>sz[i]) x-=sz[i],x+=cs[i].first-1;
            }
            cout<<s[x-1]<<"\n";
        }
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
