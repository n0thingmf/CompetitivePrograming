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
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        ll mx=0,s=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mx>a[i]+s){
                while(mx>a[i]+s) {
                    ans.pb(i+1);
                    s+=ans.size();
                }
            }
            mx=max(mx,a[i]+s);
        }
        for(int i=0;i<n;i++){
            if(i<ans.size()) cout<<ans[i]<<" ";
            else cout<<1<<" ";
        }
        cout<<"\n";

	}
	cout << setprecision(12) << fixed;
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
