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


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<n;j++){
                if(s[j]=='1') adj[i].pb(j);
            }
        }
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        vector<bool> vis(n,false);
        auto dfs = [&](int now, auto&& dfs) -> void {
            vis[now]=true;
            for(int next:adj[now]){
                for(int i=0;i<n;i++) dp[next][i]|=dp[now][i];
                if(!vis[next]) dfs(next,dfs);
            }
        };

        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,dfs);
        }

        for(int i=0;i<n;i++){
            vector<int> res;
            for(int j=0;j<n;j++) if(dp[i][j]) res.pb(j+1);
            cout<<res.size()<<" ";
            for(int j:res) cout<<j<<" ";
            cout<<"\n";
        }
	}
	cout << setprecision(12) << fixed;
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
