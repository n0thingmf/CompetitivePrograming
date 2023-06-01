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
        int n,s;
        cin>>n>>s;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        /*ll ans=0;
        if(a[0]<=a[n-1]){
            ll lst=a[0];
            for(int i=1;i<n-1;i++){
                ll l=min(s,a[i]-s),r=max(s,a[i]-s);
                ans+=lst*l;
                lst=r;
            }
            ans+=lst*a[n-1];
        }else{
            ll lst=a[n-1];
            for(int i=n-1;i>0;i--){
                ll l=min(s,a[i]-s),r=max(s,a[i]-s);
                ans+=lst*l;
                lst=r;
            }
            ans+=lst*a[0];
        }
        cout<<ans<<"\n";*/
        ll dp[n][2],l[n],r[n];
        for(int i=0;i<n;i++){
            if(i==0 || i==n-1){
                l[i]=r[i]=a[i];
            }else{
                l[i]=max(0,min(s,a[i]-s));
                r[i]=a[i]-l[i];
                //l[i]=min(s,a[i]-s);
                //r[i]=max(s,a[i]-s);
            }

        }
        dp[0][0]=dp[0][1]=0;
        for(int i=1;i<n;i++){
            dp[i][1]=min(dp[i-1][0]+r[i-1]*r[i],dp[i-1][1]+l[i-1]*r[i]);
            dp[i][0]=min(dp[i-1][0]+r[i-1]*l[i],dp[i-1][1]+l[i-1]*l[i]);
        }
        cout<<dp[n-1][0]<<"\n";
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
