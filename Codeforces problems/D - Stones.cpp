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

const int maxn=1e4 + 1;
const int inf=1e8;
int n,k;
int dp[maxn][2];
vector<int> a;
int solve(int now,int player){
    if(dp[now][player]!=-1) return dp[now][player];
    if(now+a[0]>n){
        dp[now][player]=0;
        return 0;
    }
    if(player==0){
        int ans=-inf;
        for(int i=0;i<k && now+a[i]<=n;i++){
            int res=solve(now+a[i],1);
            //cout<<now+a[i]<<" "<<1<<" "<<res<<"\n";
            ans=max(ans,res+a[i]);
        }
        dp[now][player]=ans;
    }else{
        int ans=inf;
        for(int i=0;i<k && now+a[i]<=n;i++){
            int res=solve(now+a[i],0);
            //cout<<now+a[i]<<" "<<1<<" "<<res<<"\n";
            ans=min(ans,res);
        }
        dp[now][player]=ans;
    }
    return dp[now][player];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<maxn;i++) for(int j=0;j<2;j++) dp[i][j]=-1;
	cin>>n>>k;
	a.resize(k);
	for(int i=0;i<k;i++) cin>>a[i];
	cout<<solve(0,0)<<"\n";
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
