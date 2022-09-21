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
	vector<ll> a(n);
	ll sum=0;
	for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
	}
	if(sum&1){
        cout<<"N\n";
        return 0;
	}
	set<ll> prefix;
	ll now=0;
	ll cnt=0;
	prefix.insert(0);
	for(int i=0;i<n-1;i++){
        now+=a[i];
        prefix.insert(now);
        if(sum/2<=now){
            if(prefix.count(now-sum/2)) cnt++;
        }
	}
	if(cnt>=2) cout<<"Y\n";
	else cout<<"N\n";
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
