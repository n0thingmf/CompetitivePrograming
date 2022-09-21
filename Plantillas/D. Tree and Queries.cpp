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

const int maxn=1e5+3;
vector<int> adj[maxn];

int cnt[maxn],sz[maxn],col[maxn],ft[maxn],ans[maxn],n;
vector<pair<int,int>> queries[maxn];
bool big[maxn];
void update(int pos,int val){
    for(++pos;pos<=maxn;pos+=pos&-pos){
        ft[pos]+=val;
    }
}
int sum(int pos){
    int ans=0;
    for(++pos;pos>0;pos&=pos-1){
        ans+=ft[pos];
    }
    return ans;
}
void dfssz(int v,int p){
    sz[v]=1;
    for(int u:adj[v]){
        if(u!=p){
            dfssz(u,v);
            sz[v]+=sz[u];
        }
    }
}
void add(int v,int p,int x){
    update(cnt[col[v]],-1);
    cnt[col[v]]+=x;
    update(cnt[col[v]],+1);
    for(int u:adj[v]){
        if(u!=p && !big[u]){
            add(u,v,x);
        }
    }
}
void dfs(int v,int p,bool keep){
    int maxsz=-1,maxv=-1;
    for(int u:adj[v]){
        if(u!=p && sz[u]>maxsz){
            maxsz=sz[u],maxv=u;
        }
    }
    for(int u:adj[v]){
        if(u!=p && u!=maxv) dfs(u,v,false);
    }
    if(maxv!=-1){
        dfs(maxv,v,true);
        big[maxv]=true;
    }
    add(v,p,1);
    //answer queries
    for(auto x:queries[v]){
        int k=x.first,index=x.second;
        ans[index]=n-sum(k-1);
    }
    if(maxv!=-1) big[maxv]=false;
    if(!keep){
        add(v,p,-1);
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>col[i];
	for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].pb(b);
        adj[b].pb(a);
	}
	for(int i=0;i<m;i++){
        int v,k;
        cin>>v>>k;
        v--;
        queries[v].pb({k,i});
	}
	update(0,n);
	dfssz(0,-1);
	dfs(0,-1,false);
	for(int i=0;i<m;i++) cout<<ans[i]<<"\n";
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
