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

const int inf=1e5;
int sz;
map<pair<int,int>,int> cap;
vector<vector<int>> adj;

int bfs(int s,int t,vector<int> &path){
    for(int i=0;i<sz;i++) path[i]=-1;
    path[s]=-2;
    queue<pair<int,int>> Q;
    Q.push({s,INT_MAX});
    while(!Q.empty()){
        int now=Q.front().first;
        int flow=Q.front().second;
        Q.pop();
        for(int next:adj[now]){
            int e_cap=cap[{now,next}];
            if(path[next]==-1 && e_cap>0){
                flow=min(flow,e_cap);
                path[next]=now;
                if(next==t){
                    return flow;
                }
                Q.push({next,flow});
            }
        }
    }
    return 0;
}
//Edmonds-Karp Algorithm(Ford fulkerson implementation)
int MaxFlow(int s,int t){
    int max_flow=0,new_flow;
    vector<int> path(sz);
    while(new_flow=bfs(s,t,path)){
        int e1,e2=t;
        while(e2!=s){
            e1=path[e2];
            cap[{e1,e2}]-=new_flow;
            cap[{e2,e1}]+=new_flow;
            e2=e1;
        }
        max_flow+=new_flow;
    }
    return max_flow;
}

void dfs(int s,vector<bool> &vis){
    vis[s]=true;
    for(int nxt:adj[s]){
        if(cap[{s,nxt}]>0 && !vis[nxt]) dfs(nxt,vis);
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,m;
        cin>>n>>m;
        sz=n+2;
        vector<pair<int,int>> e(m);

        for(int i=0;i<m;i++){
            cin>>e[i].first>>e[i].second;
        }
        int k;
        cin>>k;
        vector<int> mark(n,-1);
        vector<int> ans(n,0);
        for(int i=0;i<k;i++){
            int u,p;
            cin>>u>>p;
            u--;
            mark[u]=p;
            ans[u]=p;
        }
        for(int bit=0;bit<31;bit++){
            adj.clear();
            cap.clear();
            adj.resize(n+2);
            int u=0,v=0;
            for(int j=0;j<n;j++){
                if(mark[j]==-1) continue;
                if((mark[j]>>bit)&1) adj[0].pb(j+1),cap[{0,j+1}]=inf,u++;
                else adj[j+1].pb(n+1),cap[{j+1,n+1}]=inf,v++;
            }
            if(u==0 || v==0){
                if(u>0){
                    for(int i=0;i<n;i++){
                        if(mark[i]==-1){
                            ans[i]+=1<<bit;
                        }
                    }
                }
                continue;
            }
            for(int i=0;i<m;i++){
                adj[e[i].first].pb(e[i].second);
                adj[e[i].second].pb(e[i].first);
                cap[{e[i].first,e[i].second}]=1,cap[{e[i].second,e[i].first}]=1;

            }
            MaxFlow(0,n+1);
            vector<bool> vis(sz);
            dfs(0,vis);
            for(int i=0;i<n;i++) if(mark[i]==-1 && vis[i+1]) ans[i]+=1<<bit;
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<"\n";
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
