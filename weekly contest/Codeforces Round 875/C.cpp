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
	cout << setprecision(12) << fixed;
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<vector<pair<int,int>>> adj(n);
        vector<int> tim(n,-1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb({v,i});
            adj[v].pb({u,i});
        }

        auto dfs=[&](int now,int par,int paid,auto&& dfs)->void{
            for(auto p:adj[now]){
                int next=p.first,id=p.second;
                if(next!=par){
                    tim[next]=tim[now];
                    if(id<paid) tim[next]++;
                    dfs(next,now,id,dfs);
                }
            }
        };
        tim[0]=1;
        dfs(0,-1,-1,dfs);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,tim[i]);
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
