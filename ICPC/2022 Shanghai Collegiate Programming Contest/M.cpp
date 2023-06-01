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

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	adj.resize(n);
	adj_rev.resize(n);
    for(int i=0;i<m;i++){
        vector<int> s(n);
        for(int i=0;i<n;i++) cin>>s[i];
        for(int i=0;i<n-1;i++){
            adj[s[i]-1].pb(s[i+1]-1);
            adj_rev[s[i+1]-1].pb(s[i]-1);
        }
    }
    used.assign(n,false);
    for(int i=0;i<n;i++){
        if(!used[i]) dfs1(i);
    }
    used.assign(n,false);
    reverse(all(order));

    vector<int> roots(n, 0);
    vector<int> root_nodes;
    vector<int> root_size(n,0);
    vector<set<int>> adj_scc(n);

    for(auto v:order){
        if(!used[v]){
            dfs2(v);
            int root = component.front();
            for(auto u:component) roots[u]=root,root_size[u]=component.size();
            root_nodes.push_back(root);

            component.clear();
        }
    }
    for(int v=0;v<n;v++){
        for(auto u:adj[v]){
            int root_v=roots[v],root_u=roots[u];
            if(root_u!=root_v){
                adj_scc[root_v].insert(root_u);
            }
        }
    }
    vector<int> ans(n,-1);

    auto dfs = [&](int u,auto &&dfs) ->void{
        ans[u]=root_size[u];
        for(auto v:adj_scc[u]){
            if(ans[v]==-1) dfs(v,dfs);
            ans[u]+=ans[v];
        }
    };

    for(auto u:root_nodes){
        if(ans[u]==-1) dfs(u,dfs);
    }

    for(int i=0;i<n;i++) cout<<ans[roots[i]]-1<<" ";
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
