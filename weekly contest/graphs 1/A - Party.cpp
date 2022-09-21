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
int dfs(int now){
    int ans=0;
    for(int next:child[now]){
        ans=max(ans,dfs(next));
    }
    return ans+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	child.resize(n);
	vector<int> parents;
	for(int i=0;i<n;i++){
        int p;
        cin>>p;
        if(p==-1) parents.pb(i);
        else child[p-1].pb(i);
	}
	int ans=0;
	for(int p:parents){
        ans=max(ans,dfs(p));
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
