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
        vector<vector<int>> adj(n+2);
        for(int i=1;i<=n;i++){
            int b;
            cin>>b;
            adj[b].pb(i);
        }
        vector<vector<int>> a(n+1);
        int l=0,r=n;
        auto dfs = [&](int u,int d,bool up,auto&& dfs) -> void{
            int x=-1;
            for(int v:adj[u]){
                if(up) r=min(r,v-1);
                else l=max(l,v);
                dfs(v,d+1,!up,dfs);
                if(adj[v].size()>0) x=v;
                else a[d].pb(v);
            }
            if(x!=-1) a[d].pb(x);
        };
        dfs(0,0,true,dfs);
        dfs(n+1,0,false,dfs);
        cout<<l<<"\n";
        for(int i=0;i<=n;i++){
            for(int j=0;j<a[i].size();j++) cout<<a[i][j]<<" ";
        }
        cout<<"\n";
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
