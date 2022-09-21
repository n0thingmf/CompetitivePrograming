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
	//cout << setprecision(12) << fixed;
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> picos,prev;
	vector<int> l(n),r(n);
	for(int i=0;i<n;i++){
        if(i>0 && i<n-1 && a[i-1]<=a[i] && a[i]>=a[i+1]) picos.pb(i);
        if(picos.empty()) l[i]=-1;
        else l[i]=picos.back();
	}
	for(int i=n-1;i>=0;i++){
        if(i>0 && i<n-1 && a[i-1]<=a[i] && a[i]>=a[i+1]) prev.pb(i);
        if(prev.empty()) r[i]=-1;
        else r[i]=prev.back();
	}
	for(int k=3;k<n;k++){

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
