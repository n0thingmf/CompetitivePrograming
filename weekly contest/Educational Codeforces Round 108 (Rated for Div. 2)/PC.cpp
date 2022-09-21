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
	int test;
	cin>>test;
	while(test--){
        int n;
        cin>>n;
        vector<int> u(n),s(n);
        vector<ll> ans(n,0);
        vector<vector<int>> t(n);
        for(int i=0;i<n;i++) cin>>u[i];
        for(int i=0;i<n;i++) cin>>s[i];
        for(int i=0;i<n;i++) t[u[i]-1].pb(s[i]);
        for(int i=0;i<n;i++){
            int m=t[i].size();
            sort(all(t[i]));
            if(m>0){
                vector<ll> sum(m,0);
                sum[0]=t[i][0];
                for(int j=1;j<m;j++) sum[j]=sum[j-1]+t[i][j];
                for(int j=1;j<=m;j++){
                    int rest=m%j;
                    if(rest>0) ans[j-1]+=sum[m-1]-sum[rest-1];
                    else ans[j-1]+=sum[m-1];
                }
            }
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
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
