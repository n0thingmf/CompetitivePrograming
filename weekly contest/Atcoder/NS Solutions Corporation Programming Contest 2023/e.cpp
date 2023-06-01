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

vector<vector<int>> adj;
vector<int> deg;
vector<bool> vis;
void dfs(int now,int depth){
    vis[now]=true;
    for(int next:adj[now]){
        if(!vis[next]){
            if((depth+1)%3==0 && deg[next]>1){
                deg[now]--;
                deg[next]--;
            }
            dfs(next,depth+1);
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	adj.resize(n);
	deg.resize(n,0);
	vector<pair<int,int>> e;
	for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        e.pb({u,v});
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
	}
	vis.resize(n,false);
	for(int i=0;i<n;i++){
        if(deg[i]==1){
            dfs(i,0);
            break;
        }
	}
	/*for(int i=0;i<n-1;i++){
        int u=e[i].first,v=e[i].second;
        if(deg[u]==2 && deg[v]==2){
            adj[u].erase(v);
            adj[v].erase(u);
            if(deg[*adj[u].begin()]>1 && deg[*adj[v].begin()]>1){
                deg[u]--,deg[v]--;
            }else{
                adj[u].insert(v);
                adj[v].insert(u);
            }
        }
	}*/
	vector<int> ans;
	for(int i=0;i<n;i++){
        if(deg[i]>=2){
            ans.pb(deg[i]);
        }
	}
	sort(all(ans));
	for(int xx:ans) cout<<xx<<" ";
    cout<<"\n";
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
