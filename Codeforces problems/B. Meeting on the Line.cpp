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
        int n,mt=0;
        cin>>n;
        vector<int> x(n),t(n);
        for(int i=0;i<n;i++) cin>>x[i];
        for(int i=0;i<n;i++) cin>>t[i],mt=max(mt,t[i]);
        int l=INT_MAX,r=INT_MIN;
        for(int i=0;i<n;i++){
            int dt=mt-t[i];
            l=min(l,x[i]+dt);
            r=max(r,x[i]-dt);
        }
        cout<<((l+r)>>1)<<"";
        if((l+r)&1) cout<<".5\n";
        else cout<<"\n";
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
