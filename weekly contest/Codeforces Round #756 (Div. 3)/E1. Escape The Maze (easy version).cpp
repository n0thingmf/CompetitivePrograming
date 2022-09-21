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
const int inf=1e9;

vector<vector<int>> adj;
vector<bool> f;
vector<int> d;
void dfs(int now,int par){
    if(f[now]) d[now]=0;
    for(int next:adj[now]){
        if(next==par) continue;
        dfs(next,now);
        d[now]=min(d[now],d[next]+1);
    }
   // cout<<now<<" "<<d[now]<<"\n";
}
bool dfs2(int now,int par,int dist){
    if(dist>=d[now]) return false;
    for(int next:adj[now]){
        if(next==par) continue;
        if(dfs2(next,now,dist+1)) return true;
    }
    if(par!=-1 && adj[now].size()==1) return true;
    return false;
}
int ans(int now,int par,int dist){
    if(dist>=d[now]) return 1;
    int res=0;
    for(int next:adj[now]){
        if(next==par) continue;
        res+=ans(next,now,dist+1);
    }
    return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,k;
        cin>>n>>k;
        adj.assign(n,vector<int>());
        f.assign(n,false);
        d.assign(n,inf);
        for(int i=0;i<k;i++){
            int pos;
            cin>>pos;
            f[pos-1]=true;
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(0,-1);
        if(dfs2(0,-1,0)) cout<<"-1\n";
        else cout<<ans(0,-1,0)<<"\n";
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
