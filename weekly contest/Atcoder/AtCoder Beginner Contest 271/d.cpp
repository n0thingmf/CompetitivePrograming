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

const int maxn=1e4+1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,s;
	cin>>n>>s;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	vector<vector<int>> dp(n,vector<int>(maxn,-1));
	dp[0][a[0]]=0;
	dp[0][b[0]]=1;
	for(int i=0;i<n-1;i++){
        for(int j=0;j<maxn;j++){
            if(dp[i][j]==-1) continue;
            if(j+a[i+1]<maxn) dp[i+1][j+a[i+1]]=0;
            if(j+b[i+1]<maxn) dp[i+1][j+b[i+1]]=1;
        }
	}
	if(dp[n-1][s]==-1) cout<<"No\n";
	else{
        cout<<"Yes\n";
        string ans;
        for(int i=n-1;i>=0;i--){
            if(dp[i][s]) s-=b[i],ans.pb('T');
            else s-=a[i],ans.pb('H');
        }
        reverse(all(ans));
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
