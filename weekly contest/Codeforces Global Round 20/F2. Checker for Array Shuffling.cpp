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
vector<bool> vis;
vector<bool> now;
bool dfs(int v){
    now[v]=true;
    vis[v]=true;
    for(int u:adj[v]){
        if(now[u]) return true;
        else{
            if(!vis[u] && dfs(u)) return true;
        }
    }
    now[v]=false;
    return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n),f(n+1,0);
        for(int i=0;i<n;i++) cin>>a[i],f[a[i]]++;
        for(int i=0;i<n;i++) cin>>b[i];
        int maxf=0,maxi;
        for(int i=0;i<=n;i++){
            if(f[i]>maxf){
                maxf=f[i];
                maxi=i;
            }
        }
        adj.assign(n,vector<int>());
        vis.assign(n,false);
        now.assign(n,false);
        for(int i=0;i<n;i++){
            //if(a[i]==b[i]) continue;
            adj[a[i]-1].pb(b[i]-1);
        }
        vis[maxi-1]=true;
        bool ok=true;
        for(int i=0;i<n;i++){
            if(!vis[i] && !now[i]){
                if(dfs(i)){
                    ok=false;
                   // cout<<i<<" "<<ok<<"\n";
                    break;
                }
            }
        }
        if(ok) cout<<"AC\n";
        else cout<<"WA\n";
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
