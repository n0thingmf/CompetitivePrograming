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
        map<int,int> f;
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            f[c]++;
        }
        if(f.size()==1){
            int v=f.begin()->first;
            for(int i=0;i<n;i++) cout<<v<<" ";
            cout<<"\n";
            continue;
        }
        vector<pair<int,int>> ff;
        for(pair<int,int> x:f){
            ff.pb({x.second,x.first});
        }
        sort(all(ff));
        for(int i=0;i<ff.size();i++){
            ff[i]={ff[i].second,ff[i].first};
        }
        vector<vector<int>> child(n+1);
        int j=ff.size()-2,parent=ff[ff.size()-1].first;
        ff[ff.size()-1].second++;
        for(int i=ff.size()-1;i>=0;i--){
            for(int k=0;j>=0 && k<ff[i].second-1;k++,j--){
                child[ff[i].first].pb(ff[j].first);
            }
        }

        vector<int> ans;
        auto dfs = [&](int u, auto&& dfs) -> void {
            int cnt=f[u];
            for (int v : child[u]){
                ans.pb(u);
                dfs(v,dfs);
                cnt--;
            }
            for(int i=0;i<cnt;i++) ans.pb(u);
        };
        dfs(parent,dfs);
        while(j>=0){
            for(int k=0;k<ff[j].second;k++) ans.pb(ff[j].first);
            j--;
        }
        for(int x:ans) cout<<x<<" ";
        cout<<"\n";
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
