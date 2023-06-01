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
        int n,m;
        cin>>n>>m;
        vector<vector<ll>> adj(n);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            x--,y--;
            adj[min(x,y)].pb(max(x,y));
        }
        ll ans=0;
        vector<int> cnt(n,0);
        for(int i=0,j=0;i<n;i++){
            while(j<n && cnt[j]==0){
                for(int x:adj[j]) cnt[x]++;
                j++;
            }
            ans+=j-i;
            for(int x:adj[i]) cnt[x]--;
        }
        cout<<ans<<"\n";
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
