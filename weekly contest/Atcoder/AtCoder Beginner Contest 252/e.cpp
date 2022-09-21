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
const int maxn=2e5;

class e{
public:
    int to,id;
    ll w;
    e(int a,int b,int c){
        to=a,w=b,id=c;
    }
};
int n;
vector<e> adj[maxn];
ll d[maxn];
pair<int,int> p[maxn];
bool vis[maxn];

void dijkstra(int s) {
    for(int i=0;i<maxn;i++) d[i]=inf;

    d[s] = 0;
    p[s]={-1,-1};
    using pii = pair<ll, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.to;
            ll len = edge.w;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = {v,edge.id};
                q.push({d[to], to});
            }
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        adj[a].pb(e(b,c,i));
        adj[b].pb(e(a,c,i));
    }
    dijkstra(0);
    memset(vis,false,sizeof(vis));
    set<int> ans;
    vector<pair<ll,int>> order;
    for(int i=1;i<n;i++) order.pb({d[i],i});
    sort(all(order));
    for(int i=order.size()-1;i>=0;i--){
        if(!vis[order[i].second]){
            int now=order[i].second;
            while(p[now].first!=-1){
                vis[now]=true;
                int to=p[now].first;
                ans.insert(p[now].second);
                now=to;
            }
        }
    }
    for(int x:ans) cout<<x+1<<" ";
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
