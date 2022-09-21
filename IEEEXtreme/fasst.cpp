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
const ll mod=1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll dp[26];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	vector<set<int>> wall[26];
	wall[0].pb(set<int>());
	for(int i=0;i<=25;i++){
        if(i+2<=25){
            dp[i+2]+=dp[i];
            for(int j=0;j<wall[i].size();j++){
                set<int> now=wall[i][j];
                now.insert(i+2);
                wall[i+2].pb(now);
            }
        }
        if(i+3<=25){
            dp[i+3]+=dp[i];
            for(int j=0;j<wall[i].size();j++){
                set<int> now=wall[i][j];
                now.insert(i+3);
                wall[i+3].pb(now);
            }
        }
	}
	int n,m;
	cin>>n>>m;
	int k=dp[m];
	vector<vector<int>> go(k);
	for(int i=0;i<k;i++){
        wall[m][i].erase(m);
	}
	for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(i==j) continue;
            bool ok=true;
            for(int x:wall[m][i]){
                if(wall[m][j].count(x)!=0){
                    ok=false;
                    break;
                }
            }
            if(ok) go[i].pb(j);
        }
	}
	vector<ll> ans(k,1);
	vector<ll> ans2(k,0);
	for(int i=0;i<n-1;i++){
        for(int j=0;j<k;j++){
            for(int next:go[j]){
                ans2[next]=(ans2[next]+ans[j])%mod;
            }
        }
        ans=ans2;
        ans2=vector<ll>(k,0);
	}
	ll res=0;
	for(int i=0;i<k;i++) res=(res+ans[i])%mod;
	cout<<res<<"\n";
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
