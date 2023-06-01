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
        vector<vector<int>> adj(n);
        string s;
        cin>>s;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<vector<int>> path(n,vector<int>(n));
        auto dfs = [&](int now,int p,int root,auto&& dfs) -> void{
            path[root][now]=p;
            for(int next:adj[now]){
                if(next!=p){
                    dfs(next,now,root,dfs);
                }
            }
        };
        for(int i=0;i<n;i++) dfs(i,-1,i,dfs);
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<path[i][j]<<" ";
            }
            cout<<"\n";
        }*/

        vector<vector<int>> dp(n,vector<int>(n,-1));
        auto solve = [&](int u,int v,auto&& solve) -> int{
            //cout<<u<<" "<<v<<"\n";
            if(u==-1 || v==-1){
                return 0;
            }
            if(u==v){
                dp[u][v]=1;
            }else if(path[u][v]==u){
                //cout<<"kekw\n";
                if(s[u]==s[v]) dp[u][v]=2;
                else dp[u][v]=1;
            }
            if(dp[u][v]!=-1) return dp[u][v];
            if(s[u]==s[v]) dp[u][v]=max(dp[u][v],solve(path[v][u],path[u][v],solve)+2);
            else dp[u][v]=max(dp[u][v],max(solve(path[v][u],v,solve),solve(u,path[u][v],solve)));
            return dp[u][v];
        };
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int delta=solve(i,j,solve);
                //cout<<delta<<" xd\n";
                ans=max(ans,delta);
            }
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
