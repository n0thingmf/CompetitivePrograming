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
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.pb(x);
	}
	sort(all(a));
	a.erase(unique(all(a)),a.end());
	ll l=0,r=1e9;
	while(l<r){
        ll m=(l+r+1)>>1;
        ll id=upper_bound(all(a),m)-a.begin();
        if(m>id+(n-id)/2) r=m-1;
        else l=m;
	}
    cout<<l<<"\n";
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
