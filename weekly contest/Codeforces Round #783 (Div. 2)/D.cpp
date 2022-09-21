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
const int maxn=5e5;

ll ft[maxn+2];
ll dp[maxn+1];
void update(int pos,ll newval){
    for(++pos;pos<=maxn+1;pos+=pos&-pos){
        ft[pos]=max(ft[pos],newval);
    }
}
ll query(int pos){
    ll ans=LLONG_MIN;
    for(++pos;pos>0;pos&=pos-1){
        ans=max(ans,ft[pos]);
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n+2;i++) ft[i]=LLONG_MIN;
        vector<ll> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<ll> p(n+1);
        p[0]=0;
        for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
        vector<ll> xp(all(p));
        sort(all(xp));
        xp.erase(unique(all(xp)),xp.end());
        for(int i=0;i<=n;i++){
            p[i]=(int)(lower_bound(all(xp),p[i])-xp.begin());
          //  cout<<p[i]<<" ";
        }
       // cout<<"\n";
        dp[0]=0;
        update(p[0],dp[0]-0);
        for(int i=1;i<=n;i++){
            if(a[i]<0) dp[i]=dp[i-1]-1;
            if(a[i]==0) dp[i]=dp[i-1];
            if(a[i]>0) dp[i]=dp[i-1]+1;
            dp[i]=max(dp[i],i+query(p[i]-1));
            update(p[i],dp[i]-i);
        }
        cout<<dp[n]<<"\n";
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
