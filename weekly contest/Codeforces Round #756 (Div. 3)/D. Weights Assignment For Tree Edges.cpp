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
vector<vector<int>> child;
vector<int> a;
vector<int> pos;
vector<int> d;
bool dfs(int now){
    for(int next:child[now]){
        if(dfs(next)){
            if(pos[now]<pos[next]){
                d[next]=pos[next]-pos[now];
            }
            else return false;
        }else return false;
    }
    return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,root;
        cin>>n;
        child=vector<vector<int>>(n);
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            p--;
            if(i==p) root=p;
            else child[p].pb(i);
        }
        a.resize(n);
        pos.resize(n);
        d.assign(n,0);
        for(int i=0;i<n;i++) cin>>a[i],a[i]--;
        for(int i=0;i<n;i++) pos[a[i]]=i;
        if(dfs(root)){
            for(int i=0;i<n;i++) cout<<d[i]<<" ";
            cout<<"\n";
        }else cout<<"-1\n";
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
