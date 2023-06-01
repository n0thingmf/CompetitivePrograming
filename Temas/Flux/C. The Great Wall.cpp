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


const ll inf = 1e8;
class edge{
public:
	int u,v;
	ll cap,flow = 0;
	edge(int _u,int _v,long long _cap){
		u=_u,v=_v,cap=_cap;
	}
};
class dinic{
public:
	vector<edge> e;
	vector<vector<int>> adj;
	vector<int> d,ptr;
	int n,m=0,s,t;
	queue<int> q;
	dinic(int _n, int _s, int _t){
		n=_n,s=_s,t=_t;
		adj.resize(n);
		d.resize(n);
		ptr.resize(n);
	}
	void add_edge(int u, int v, ll cap){
		e.pb(edge(u, v, cap));
		e.pb(edge(v, u, 0));
		adj[u].pb(m++);
		adj[v].pb(m++);
	}

	void add_bidirectional_edge(int u,int v,ll cap){
        e.pb(edge(u,v,cap));
        e.pb(edge(v,u,cap));
        adj[u].pb(m++);
        adj[v].pb(m++);
	}

	bool bfs(){
		while(!q.empty()){
			int now = q.front();
			q.pop();
			for(int id:adj[now]){
				if(e[id].cap - e[id].flow <= 0) continue;
				if(d[e[id].v] != -1) continue;
				d[e[id].v] = d[now] + 1;
				q.push(e[id].v);
			}
		}
		return d[t] != -1;
	}

	ll dfs(int now,ll flow){
		if(now==t || flow == 0) return flow;
		for(;ptr[now] < adj[now].size(); ptr[now]++){
			int id = adj[now][ptr[now]];
			if(d[e[id].v] != d[now] + 1 || e[id].cap - e[id].flow < 1) continue;
			ll res = min(flow, e[id].cap - e[id].flow);
            if(int new_flow = dfs(e[id].v,res)){
                e[id].flow += new_flow;
                e[id ^ 1].flow -= new_flow;
                return new_flow;
			}
		}
        return 0;
	}

	ll flow(){
		ll flow = 0;
		while(true){//V iteraciones
			fill(d.begin(), d.end(), -1);
			d[s] = 0;
			q.push(s);
			if(!bfs()) break;
			fill(ptr.begin(),ptr.end(),0);
			while(ll curr_flow = dfs(s,inf)){//Complejidad V*E

				flow += curr_flow;
			}
		}
		return flow;
	}
    void vdfs(int now,vector<bool> &vis){
        vis[now] = true;
        for(int id:adj[now]){
            if(!vis[e[id].v] && e[id].cap-e[id].flow>0) vdfs(e[id].v,vis);
        }
	}
	void minCut(vector<bool> &cut){
        cut.assign(n,false);
        vdfs(s,cut);
	}


};

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
	/*ios::sync_with_stdio(false);
	cin.tie(0);*/
    int n,m,u,wu;
    cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<m;j++){
            if(s[i][j]=='A') u=i*m+j;
            if(s[i][j]=='B') wu=i*m+j;
        }
    }
    dinic g=dinic(2*n*m,2*u,2*wu+1);
    g.add_edge(2*u,2*u+1,inf);
    g.add_edge(2*wu,2*wu+1,inf);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int id=i*m+j;
            if(s[i][j]=='-') g.add_edge(2*id,2*id+1,inf);
            if(s[i][j]=='.') g.add_edge(2*id,2*id+1,1);
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x>=0 && x<n && y>=0 && y<m){
                    int new_id=x*m+y;
                    g.add_edge(2*id+1,2*new_id,inf);
                }
            }
        }
    }
    ll max_flow=g.flow();
    if(max_flow==inf){
        cout<<"-1\n";
        return 0;
    }else cout<<max_flow<<"\n";
    vector<bool> vis;
    g.minCut(vis);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int id=i*m+j;
            if(s[i][j]=='.' && vis[2*id] && !vis[2*id+1]) s[i][j]='+';
        }
    }
    for(int i=0;i<n;i++) cout<<s[i]<<"\n";
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
