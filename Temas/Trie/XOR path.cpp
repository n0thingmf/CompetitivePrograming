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
const int maxn=20;
int a[maxn][maxn];
vector<int> l[maxn];
vector<int> r[maxn];
vector<vector<int>> trie;
int n,node;
void insert(int x){
    int pos=0;
    for(int i=29;i>=0;i--){
        int next=(x>>i)&1;
        if(trie[pos][next]==0){
            trie[pos][next]=++node;
            trie.pb(vector<int>(2,0));
        }
        pos=trie[pos][next];
    }
}
int answer(int x){
    int pos=0,ans=0;
    for(int i=29;i>=0;i--){
        int need=(x>>i)&1;
        int next=need;
        if(trie[pos][next]==0) next=need^1;
        pos=trie[pos][next];
        ans|=next<<i;
    }
    return ans^x;
}
void dfs1(int x,int y,int val){
    val^=a[x][y];
    if(x+y==n-1){
        l[x].pb(val);
        return;
    }
    if(x<n-1) dfs1(x+1,y,val);
    if(y<n-1) dfs1(x,y+1,val);
}
void dfs2(int x,int y,int val){
    val^=a[x][y];
    if(x+y==n-1){
        r[x].pb(val^a[x][y]);
        return;
    }
    if(x>0) dfs2(x-1,y,val);
    if(y>0) dfs2(x,y-1,val);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
	}
	dfs1(0,0,0);
	dfs2(n-1,n-1,0);
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
        trie.assign(1,vector<int>(2,0));
        node=0;
        for(int j=0;j<l[i].size();j++){
            insert(l[i][j]);
        }
        for(int j=0;j<r[i].size();j++){
            ans=min(ans,answer(r[i][j]));
        }
	}
	cout<<ans<<"\n";
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
