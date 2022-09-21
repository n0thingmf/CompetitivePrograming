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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ll dp[n+1][5];
	dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=dp[0][4]=0;
	for(int i=1;i<=n;i++) for(int j=0;j<5;j++) dp[i][j]=LLONG_MAX;
	for(int i=0;i<n;i++){
        if(a[i]==0){
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]);
            dp[i+1][1]=min(dp[i+1][1],dp[i][0]+2);
            dp[i+1][2]=min(dp[i+1][2],dp[i][0]+1);
            dp[i+1][1]=min(dp[i+1][1],dp[i][1]+2);
            dp[i+1][2]=min(dp[i+1][2],dp[i][1]+1);
            dp[i+1][4]=min(dp[i+1][4],dp[i][1]);
            dp[i+1][2]=min(dp[i+1][2],dp[i][2]+1);
            dp[i+1][3]=min(dp[i+1][3],dp[i][2]+2);
            dp[i+1][4]=min(dp[i+1][4],dp[i][2]);
            dp[i+1][3]=min(dp[i+1][3],dp[i][3]+2);
            dp[i+1][4]=min(dp[i+1][4],dp[i][3]);
            dp[i+1][4]=min(dp[i+1][4],dp[i][4]);

        }else if(a[i]&1){
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]+a[i]);
            dp[i+1][1]=min(dp[i+1][1],dp[i][0]+1);
            dp[i+1][2]=min(dp[i+1][2],dp[i][0]);
            dp[i+1][1]=min(dp[i+1][1],dp[i][1]+1);
            dp[i+1][2]=min(dp[i+1][2],dp[i][1]);
            dp[i+1][4]=min(dp[i+1][4],dp[i][1]+a[i]);
            dp[i+1][2]=min(dp[i+1][2],dp[i][2]);
            dp[i+1][3]=min(dp[i+1][3],dp[i][2]+1);
            dp[i+1][4]=min(dp[i+1][4],dp[i][2]+a[i]);
            dp[i+1][3]=min(dp[i+1][3],dp[i][3]+1);
            dp[i+1][4]=min(dp[i+1][4],dp[i][3]+a[i]);
            dp[i+1][4]=min(dp[i+1][4],dp[i][4]+a[i]);
        }else{
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]+a[i]);
            dp[i+1][1]=min(dp[i+1][1],dp[i][0]);
            dp[i+1][2]=min(dp[i+1][2],dp[i][0]+1);
            dp[i+1][1]=min(dp[i+1][1],dp[i][1]);
            dp[i+1][2]=min(dp[i+1][2],dp[i][1]+1);
            dp[i+1][4]=min(dp[i+1][4],dp[i][1]+a[i]);
            dp[i+1][2]=min(dp[i+1][2],dp[i][2]+1);
            dp[i+1][3]=min(dp[i+1][3],dp[i][2]);
            dp[i+1][4]=min(dp[i+1][4],dp[i][2]+a[i]);
            dp[i+1][3]=min(dp[i+1][3],dp[i][3]);
            dp[i+1][4]=min(dp[i+1][4],dp[i][3]+a[i]);
            dp[i+1][4]=min(dp[i+1][4],dp[i][4]+a[i]);
        }
	}
	ll ans=LLONG_MAX;
	for(int i=0;i<5;i++) ans=min(ans,dp[n][i]);
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
