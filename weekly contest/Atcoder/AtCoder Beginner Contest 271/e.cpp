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
const ll inf = 1e18;

class edge{
public:
    int u,v;
    ll c;
    edge(){
        c=0;
    }
    edge(int x,int y, ll z){
        u=x,v=y,c=z;
    }
};
vector<edge> e;
vector<vector<int>> adj;
//vector<int> a;
vector<vector<int>> pos;

int update(int id,int curr){
    int idd=upper_bound(all(pos[id]),curr)-pos[id].begin();
    return idd;
}
void dijkstra(int s, vector<ll> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, inf);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<ll, pair<int,int>>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, {s,0}});
    while (!q.empty()) {
        int v = q.top().second.first;
        int curr = q.top().second.second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (int id : adj[v]) {
            int new_ix = update(id,curr);
            if(new_ix >= pos[id].size()) continue;
            int to=e[id].v;
            ll len=e[id].c;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], {to , pos[id][new_ix]}});
            }
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	adj.resize(n);
	e.resize(m);
	pos.resize(m);
	for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        e[i]=edge(u-1,v-1,c);
        adj[u-1].pb(i);
	}
	for(int i=0;i<k;i++){
        int x;
        cin>>x;
        pos[x-1].pb(i+1);
	}

	vector<ll> d;
	vector<int> p;
	dijkstra(0,d,p);
	if(d[n-1]==inf) cout<<"-1\n";
    else cout<<d[n-1]<<"\n";
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
