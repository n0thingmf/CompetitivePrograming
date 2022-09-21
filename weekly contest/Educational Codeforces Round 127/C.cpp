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
        int n;
        ll x,ans=0,s=0;
        cin>>n>>x;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(all(a));
        for(int i=1;i<n;i++) a[i]+=a[i-1];
        vector<ll> t(n);
        for(int i=0;i<n;i++){
            if(x-a[i]>=0) t[i]=(x-a[i])/(i+1);
            else t[i]=-1;
        }
      //  cout<<"\n";
        for(int i=n-1;i>=0;i--){
            if(s<=t[i]){
                ans+=1ll*(i+1)*(t[i]-s+1);
                s=t[i]+1;
            }
        }
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
