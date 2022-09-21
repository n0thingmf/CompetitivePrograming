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

const int maxn=1e5+2;
vector<int> adj[maxn];
ll maxcnt=0,maxval=0;
int cnt[maxn],sz[maxn],col[maxn];
ll ans[maxn];
bool big[maxn];

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
    cnt[col[v]]+=x;
    if(x==1){
        if(cnt[col[v]]==maxval) maxcnt+=col[v];
        if(cnt[col[v]]>maxval) maxcnt=col[v],maxval=cnt[col[v]];
    }
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
    ans[v]=maxcnt;
    if(maxv!=-1) big[maxv]=false;
    if(!keep){
        add(v,p,-1);
        maxval=maxcnt=0;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>col[i];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfssz(0,-1);
    dfs(0,-1,true);
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
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
