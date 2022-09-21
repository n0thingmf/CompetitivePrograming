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
ll dp[102][9];
ll delta[8];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h,w,k;
	cin>>h>>w>>k;
	delta[0]=1;
	delta[1]=1;
	for(int i=2;i<=7;i++) delta[i]=delta[i-1]+delta[i-2];
	dp[0][1]=1;
	for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            dp[i][j]=0;
            dp[i][j]+=dp[i-1][j]*delta[j-1]*delta[w-j];
            dp[i][j]%=mod;
            if(1<j){
                dp[i][j]+=dp[i-1][j-1]*delta[j-2]*delta[w-j];
                dp[i][j]%=mod;
            }
            if(j<w){
                dp[i][j]+=dp[i-1][j+1]*delta[j-1]*delta[w-j-1];
                dp[i][j]%=mod;
            }
        }
	}
	cout<<dp[h][k]<<"\n";
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
