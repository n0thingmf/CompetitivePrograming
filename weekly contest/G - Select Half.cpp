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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	if(n&1){
        ll dp1=0,dp2=0,dp3=a[0];
        for(int i=1;2*i<n;i++){
            dp2=max(dp2+a[2*i-1],dp3);
            dp1=max(dp1+a[2*i],dp2);
            dp3+=a[2*i];
        }
        cout<<dp1<<"\n";
	}else{
	    ll dp1=0,dp2=0;
        for(int i=0;2*i+1<n;i++){
            dp2=dp2+a[2*i];
            dp1=max(dp1+a[2*i+1],dp2);
        }
        cout<<dp1<<"\n";
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
