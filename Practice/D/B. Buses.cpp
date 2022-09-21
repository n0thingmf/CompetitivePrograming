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
const ll mod=1e9 + 7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
    set<ll> points;
	vector<pair<ll,ll>> e(m);
	for(int i=0;i<m;i++){
        cin>>e[i].first>>e[i].second;
        points.insert(e[i].first);
        points.insert(e[i].second);
	}
	if(points.count(0)==0 || points.count(n)==0){
        cout<<"0\n";
        return 0;
	}
	vector<vector<ll>> seg(points.size());
	map<ll,int> mp;
	int ii=0;
	for(int x:points){
        mp[x]=ii++;
	}
	for(int i=0;i<m;i++){
        seg[mp[e[i].second]].pb(e[i].first);
	}
	vector<ll> dp(points.size());
	vector<ll> sum(points.size()+1,0);
	dp[0]=1;
	sum[1]=1;
	for(int i=1;i<points.size();i++){
        for(int x:seg[i]){
            dp[i]+=(sum[i]-sum[mp[x]]+mod)%mod;
            dp[i]%=mod;
        }
        sum[i+1]=(sum[i]+dp[i])%mod;
	}
	cout<<dp[points.size()-1]<<"\n";
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
