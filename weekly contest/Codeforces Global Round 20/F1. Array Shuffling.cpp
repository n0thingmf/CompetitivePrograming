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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            f[a[i]]++;
        }
        vector<pair<int,int>> fs;
        vector<vector<int>> x;
        for(auto u:f) fs.pb({u.second,u.first});
        sort(all(fs));
        x.resize(fs.size());
        for(int i=0;i<n;i++){
            int j=lower_bound(all(fs),make_pair(f[a[i]],a[i]))-fs.begin();

            x[j].pb(i);
        }
        vector<int> b(n);
        for(int i=0;i<fs.size()-1;i++){
            for(int j=0;j<x[i].size();j++) b[x[i][j]]=a[x[i+1].back()];
        }
        for(int i=0,index=0;i<fs.size();i++){
            if(i==0){
                for(int j=0;j<x[i].size();j++,index++) b[x.back()[index]]=a[x[i][j]];
            }else{
                for(int j=0;j<x[i].size()-x[i-1].size();j++,index++) b[x.back()[index]]=a[x[i][j]];
            }

        }
        for(int i=0;i<n;i++) cout<<b[i]<<" ";
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
