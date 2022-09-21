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
        int n,k;
        cin>>n>>k;
        map<int,int> f;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            f[x]++;
        }
        int need=0;
        int r;
        for( r=0;r<n;r++){
            if(f.count(r)==0){
                need++;
            }
            if(need>k) break;

        }
        if(need<=k) r++;
        vector<int> fs;
        for(auto x:f){
            if(x.first>=r) fs.pb(x.second);
        }
        sort(all(fs));
        int ans=0;
        for(int i=0,s=0;i<fs.size();i++){
            s+=fs[i];
            if(s>k){
                ans=fs.size()-i;
                break;
            }
        }
        cout<<ans<<"\n";
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
