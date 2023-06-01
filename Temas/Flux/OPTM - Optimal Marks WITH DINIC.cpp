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
	const ll inf = 1e18;
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

	void add_undir_edge(int u, int v, ll cap){
        e.pb(edge(u, v, cap));
		e.pb(edge(v, u, cap));
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


const ll inf = 1e18;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> e(m);
        vector<bool> known(n,false);
        vector<int> value(n,0);
        for(int i = 0; i < m; i++){
            cin>>e[i].first>>e[i].second;
        }
        int k;
        cin>>k;
        for(int i = 0;i < k; i++){
            int u,p;
            cin>>u>>p;
            known[u-1] = true;
            value[u-1] = p;
        }
        for(int id = 0; id < 31; id++){
            dinic g = dinic(n+2, 0, n+1);
            int v1=0,v0=0;
            for(int i = 0; i < n; i++){
                if(known[i]){
                    if((value[i]>>id)&1) g.add_edge(0,i+1,inf),v1++;
                    else g.add_edge(i+1,n+1,inf),v0++;
                }
            }
            if(v1==0 || v0==0){
                if(v1>0){
                    for(int i=0;i<n;i++) if(!known[i]) value[i]+=1<<id;
                    continue;
                }
            }
            for(int i = 0; i < m; i++){
                g.add_undir_edge(e[i].first, e[i].second, 1);
            }

            g.flow();
            vector<bool> cut;
            g.minCut(cut);
            for(int i=0;i<n;i++){
                if(!known[i] && cut[i+1]) value[i]+=1<<id;
            }
        }
        for(int i=0;i<n;i++) cout<<value[i]<<"\n";
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
