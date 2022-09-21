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
const int maxn=5e3 + 5;
int dp[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        dp[a][b]+=1;
        dp[a][b+1]+=-1;
        dp[a+x+1][b]+=-1;
        dp[a+x+2][b+1]+=1;
        dp[a+x+1][b+x+2]+=1;
        dp[a+x+2][b+x+2]+=-1;
	}
        for(int i=0;i<maxn;i++){
            for(int j=1;j<=i;j++){
                dp[i][j]+=dp[i][j-1];
            }
        }
        for(int i=0;i<maxn;i++){
            for(int j=i+1;j<maxn;j++){
                dp[j][i]+=dp[j-1][i];
            }
        }
        for(int i=0;i<maxn;i++){
            for(int j=1;i+j<maxn;j++){
                dp[i+j][j]+=dp[i+j-1][j-1];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                //cout<<dp[i][j]<<" ";
                if(dp[i][j]>0) ans++;
            }
           // cout<<"\n";
        }
        cout<<ans<<"\n";
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
