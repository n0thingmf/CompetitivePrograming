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

int n,m;
map<vector<int>,int> ban;
vector<vector<int>> a;
pair<ll,vector<int>> dfs(vector<int> now){
    if(ban.count(now)!=0 && ban[now]==1){
            ban[now]++;
            pair<ll,vector<int>> ans;
            ans.first=0;
            for(int i=0;i<n;i++){
                if(now[i]>1){
                    now[i]--;
                    pair<ll,vector<int>> res=dfs(now);
                    if(res.first>ans.first){
                        ans=res;
                    }
                    now[i]++;
                }
            }
            return ans;
    }else{
        ll val=0;
        for(int i=0;i<n;i++){
            val+=a[i][now[i]];
        }
        return {val,now};
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	vector<int> c(n);
	a.resize(n);
	for(int i=0;i<n;i++){
        cin>>c[i];
        a[i].resize(c[i]+1);
        for(int j=1;j<=c[i];j++) cin>>a[i][j];
	}
	cin>>m;
	for(int i=0;i<m;i++){
        vector<int> pos(n);
        for(int j=0;j<n;j++) cin>>pos[j];
        ban[pos]=1;
	}
	vector<int> ans=dfs(c).second;
	for(int i=0;i<n;i++) cout<<ans[i]<<" ";
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
