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
        int n,k;
        ll s=0;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i],s+=a[i];
        sort(all(a));
        //ll sx=0,sy=0;
        vector<ll> x(k+1),y(k+1);
        x[0]=0;
        y[0]=0;
        for(int i=0;i<k;i++){
            x[i+1]=x[i]+a[2*i]+a[2*i+1];
            y[i+1]=y[i]+a[n-1-i];
            //sy+=y[i];
        }
        ll ans=LLONG_MAX;
        for(int i=0;i<=k;i++){
            ans=min(ans,x[i]+y[k-i]);
        }

        cout<<s-ans<<"\n";
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
