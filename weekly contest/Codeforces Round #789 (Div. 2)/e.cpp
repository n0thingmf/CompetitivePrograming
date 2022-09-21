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
        vector<int> p(n+1);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            p[x]=i;
        }
        for(int i=0;i<n;i++){
            int y;
            cin>>y;
            if(i!=p[y]){
                adj[i].pb(p[y]);
                adj[p[y]].pb(i);
            }
        }
        vector<int> vis(n,false);
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i] && adj[i].size()>0){
                int len=1;
                vis[i]=true;
                queue<int> q;
                q.push(adj[i].back());
                while(!q.empty()){
                    int now=q.front();
                    vis[now]=true;
                    len++;
                    q.pop();
                    for(int next:adj[now]){
                        if(!vis[next]){
                            q.push(next);
                        }
                    }
                }
                res+=len/2;
            }
        }
        ll ans=0;
        for(int i=0;i<res;i++){
            ans+=1ll*2*(n-2*i-1);
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
