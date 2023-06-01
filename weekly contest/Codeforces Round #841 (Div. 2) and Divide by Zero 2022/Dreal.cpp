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

int mlog(ll x) {
    return __builtin_clzll(1ll) - __builtin_clzll(x);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin>>a[i][j];
        }

        int left=1,right=n;
        while(left<right){
            int mid=(left+right+1)>>1;
            bool ok=false;
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    dp[i+1][j+1]=(a[i][j]>=mid);
                }
            }
            for(int i=0;i<=n;i++){
                for(int j=1;j<=m;j++){
                    dp[i][j]+=dp[i][j-1];
                }
            }
            for(int j=0;j<=m;j++){
                for(int i=1;i<=n;i++){
                    dp[i][j]+=dp[i-1][j];
                }
            }
            for(int i=0;i+mid<=n;i++){
                for(int j=0;j+mid<=m;j++){
                    int sum=dp[i+mid][j+mid]-dp[i][j+mid]-dp[i+mid][j]+dp[i][j];
                    if(sum==mid*mid) ok=true;
                }
            }
            if(ok) left=mid;
            else right=mid-1;
        }
        cout<<left<<"\n";

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
