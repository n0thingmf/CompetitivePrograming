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
	int n,k;
	cin>>n>>k;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(all(a));
	/*for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<"sorted\n";*/
	ll sum=0;
	vector<ll> ans;
	for(int i=0;i<n && ans.size()<k;i++){
        /*cout<<sum<<" "<<a[i]<<"\n";
        for(int x:ans) cout<<x<<" ";
        cout<<"ans\n";*/
        if(sum+1<a[i]){
            vector<ll> adding;
            int m=ans.size();
            for(int j=0;j<m;j++) if(ans[j]+a[i]>sum) adding.pb(ans[j]+a[i]);
            for(ll j=sum+1;j<a[i] && ans.size()<k;j++) ans.pb(j);
            for(ll x=0;x<adding.size() && ans.size()<k;x++) ans.pb(adding[x]);

        }else{
            int m=ans.size();
            for(int j=0;j<m && ans.size()<k;j++) if(ans[j]+a[i]>sum) ans.pb(ans[j]+a[i]);
        }
        sum+=a[i];
	}
	if(ans.size()<k){
        for(ll i=sum+1;ans.size()<k;i++) ans.pb(i);
	}
	for(int i=0;i<k;i++) cout<<ans[i]<<" ";
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
