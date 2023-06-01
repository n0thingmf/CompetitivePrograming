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
	int n,q;
	cin>>n>>q;
	vector<vector<int>> l(n+1);
	vector<vector<int>> r(n+1);
	vector<ll> cost(q);
	vector<pair<int,int>> ran(q);
	for(int i=0;i<q;i++){
        cin>>ran[i].first>>ran[i].second>>cost[i];
        l[ran[i].first].pb(i);
        r[ran[i].second].pb(i);
	}
	vector<ll> dp(n+1,0);
	dp[0]=0;
	multiset<ll> res;
	for(int i=1;i<=n;i++){
        for(int x:l[i]){
            res.insert(dp[i-1]+cost[x]);
        }
        dp[i]=*res.begin();
        for(int x:r[i]){
            res.erase(res.find(dp[ran[x].first-1]+cost[x]));
        }
	}
	cout<<dp[n]<<"\n";
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
