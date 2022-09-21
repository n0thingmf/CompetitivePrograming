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
        vector<vector<int>> y(n+1);
        vector<int> cntx(n+1,0);
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            cntx[a]++;
            y[b].pb(a);
        }
        ll ans=0,total=(1ll*n*(n-1)*(n-2))/6;
        for(int i=1;i<=n;i++){
            for(int x:y[i]){
                ans+=1ll*(y[i].size()-1)*(cntx[x]-1);
            }
        }
        cout<<total-ans<<"\n";
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
