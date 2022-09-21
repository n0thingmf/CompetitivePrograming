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
vector<vector<int>> adj;
vector<int> visit;
vector<int> ans;
bool dfs(int now){
    visit[now]=1;
    for(int next:adj[now]){
        if(visit[next]==1) return false;
        if(visit[next]==2) continue;
        if(!dfs(next)) return false;
    }
    visit[now]=2;
    ans.pb(now+1);
    return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	adj.resize(n);
	visit.resize(n,false);
	vector<int> a(k);
 	for(int i=0;i<k;i++) cin>>a[i];
 	for(int i=0;i<n;i++){
        int m,v;
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>v;
            v--;
            adj[i].pb(v);
        }
 	}
 	for(int i=0;i<k;i++){
        if(visit[a[i]-1]==0){
            if(!dfs(a[i]-1)){
                cout<<"-1\n";
                return 0;
            }
        }
 	}
 	cout<<ans.size()<<"\n";
 	for(int aa:ans) cout<<aa<<" ";
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
