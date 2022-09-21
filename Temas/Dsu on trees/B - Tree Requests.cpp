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
const int maxn=5e5+2;
vector<int> child[maxn];

int sz[maxn],ans[maxn],cnt[maxn][26];
string s;
vector<pair<int,int>> queries[maxn];
bool big[maxn];

void dfssz(int v){
    sz[v]=1;
    for(int u:child[v]){
        dfssz(u);
        sz[v]+=sz[u];
    }
}
void add(int v,int d,int x){
    cnt[d][s[v]-'a']+=x;
    for(int u:child[v]){
        if(!big[u]){
            add(u,d+1,x);
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
    add(v,d,1);
    //answer
    for(auto x:queries[v]){
        int depth=x.first,index=x.second,odd=0,even=0;
        for(int i=0;i<26;i++){
            if(cnt[depth][i]&1) odd++;
        }
        if(odd>1) ans[index]=0;
        else ans[index]=1;
    }
    if(bigchild!=-1) big[bigchild]=false;
    if(!keep) add(v,d,-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<n;i++){
        int p;
        cin>>p;
        p--;
        child[p].pb(i);
	}
	cin>>s;
	for(int i=0;i<q;i++){
        int v,h;
        cin>>v>>h;
        v--,h--;
        queries[v].pb({h,i});
	}
	dfssz(0);
	dfs(0,0,true);
	for(int i=0;i<q;i++){
        if(ans[i]) cout<<"Yes\n";
        else cout<<"No\n";
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
