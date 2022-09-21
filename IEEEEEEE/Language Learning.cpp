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

const ll mod=1e9+7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,k;
        cin>>n>>k;
        vector<string> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<string> b=a;
        sort(all(b));
        b.erase(unique(all(b)),b.end());
        vector<int> vec(n);
        map<string,int> mp;
        for(int i=0;i<b.size();i++) mp[b[i]]=i;
        for(int i=0;i<n;i++) vec[i]=mp[a[i]];
        map<int,int> last;
        vector<ll> dp(n+1,0),endi(n+1,0);
        dp[0]=1,endi[0]=0;
        for(int i=1;i<=n;i++){
            if(i-k-1>=0) dp[i]=dp[i-k-1];
            else dp[i]=1;
            endi[i]=dp[i];
            dp[i]=(dp[i]+dp[i-1])%mod;
            //cout<<i<<" "<<dp[i]<<"\n";
            if(last.count(vec[i-1])){
                dp[i]=((dp[i]-endi[last[vec[i-1]]])%mod+mod)%mod;
            }
            //cout<<i<<" "<<dp[i]<<"\n";
            last[vec[i-1]]=i;
        }
        //for(int i=1;i<=n;i++) cout<<dp[i]<<"\n";
        cout<<(dp[n]-1+mod)%mod<<"\n";
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
