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

const int maxn=1e5+2,maxl=ceil(log2(maxn))+1;
vector<int> child[maxn];
int sz[maxn],ans[maxn],up[maxn][maxl];
int cnt[maxn];
vector<pair<int,int>> queries[maxn];
bool big[maxn];

void dfssz(int v){
    sz[v]=1;
    for(int i=1;i<maxl;i++){
        up[v][i]=up[up[v][i-1]][i-1];
    }
    for(int u:child[v]){
        dfssz(u);
        sz[v]+=sz[u];
    }
}
void add(int v,int d){
    cnt[d]++;
    for(int u:child[v]){
        if(!big[u]){
            add(u,d+1);
        }
    }
}
void sub(int v,int d){
    cnt[d]--;
    for(int u:child[v]){
        if(!big[u]){
            sub(u,d+1);
        }
    }
}
void dfs(int v,int d,bool keep){
    int maxsz=-1,bigchild=-1;
    for(int u:child[v]){
        if(maxsz<sz[u]) maxsz=sz[u],bigchild=u;
    }
    for(int u:child[v]){
        if(u!=bigchild) dfs(u,d+1,false);
    }
    if(bigchild!=-1) dfs(bigchild,d+1,true),big[bigchild]=true;
    add(v,d);
    //answer
    for(auto x:queries[v]){
        int kth=x.first,index=x.second;
        ans[index]=cnt[d+kth]-1;
    }
    if(bigchild!=-1) big[bigchild]=false;
    if(!keep) sub(v,d);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n;
	vector<int> parents;
	for(int i=1;i<=n;i++){
        int par;
        cin>>par;
        up[i][0]=par;
        if(par) child[par].pb(i);
        else parents.pb(i);
	}
	for(int par:parents) dfssz(par);
	cin>>m;
	for(int i=0;i<m;i++){
        int v,p,u;
        cin>>v>>p;
        u=v;
        for(int i=0;i<maxl;i++){
            if(p&(1<<i)) u=up[u][i];
        }
        if(u) queries[u].pb({p,i});
        else ans[i]=0;
	}
	for(int par:parents) dfs(par,0,false);
	for(int i=0;i<m;i++) cout<<ans[i]<<" ";
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
