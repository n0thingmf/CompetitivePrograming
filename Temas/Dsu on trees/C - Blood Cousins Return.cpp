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
vector<int> child[maxn];
int sz[maxn],ans[maxn];
map<string,int> cnt[maxn];
string name[maxn];
vector<pair<int,int>> queries[maxn];
bool big[maxn];

void dfssz(int v){
    sz[v]=1;
    for(int u:child[v]){
        dfssz(u);
        sz[v]+=sz[u];
    }
}
void add(int v,int d){
    cnt[d][name[v]]++;
    for(int u:child[v]){
        if(!big[u]){
            add(u,d+1);
        }
    }
}
void sub(int v,int d){
    cnt[d][name[v]]--;
    if(cnt[d][name[v]]==0) cnt[d].erase(name[v]);
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
        if(d+kth>maxn) ans[index]=0;
        else ans[index]=cnt[d+kth].size();
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
	for(int i=0;i<n;i++){
        int par;
        cin>>name[i];
        cin>>par;
        if(par==0){
            parents.pb(i);
        }else {
            child[par-1].pb(i);
        }
	}
	cin>>m;
	for(int i=0;i<m;i++){
        int v,k;
        cin>>v>>k;
        queries[v-1].pb({k,i});
	}
	for(int par:parents){
        dfssz(par);
        dfs(par,0,false);
	}
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
