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
const int N=1e4+4;
int dp[N],dp2[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin>>n>>k;
	vector<int> a(k);
	for(int  i=0;i<k;i++)cin>>a[i];
	dp[0] = dp2[0] = 0;
	for(int i=1;i<=n;i++){
        dp2[i] = dp2[i-1];
        for(int j=0;j<k;j++){
            if(i>=a[j])
                dp2[i] = max(dp2[i],dp2[i-a[j]]+a[j]);
        }
	}

	for(int val=1;val<=n;val++){
        dp[val] = dp[val-1];
        for(int j=0;j<k;j++){
            if(val>=a[j]){
                dp[val] = max(dp[val],dp2[val-a[j]-dp[val-a[j]]]+a[j]);
            }
        }
	}

	cout<<dp[n]<<endl;

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
