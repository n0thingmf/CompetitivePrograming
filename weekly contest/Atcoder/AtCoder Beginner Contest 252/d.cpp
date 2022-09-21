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

const int maxn=2e5;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll> f(maxn+1,0);
	vector<int> a(n);
	for(int i=0;i<n;i++){
        cin>>a[i];
	};
	int cnt=1;
	ll ans=0,prod=0;
	f[a[0]]++;
	for(int i=1;i<n;i++){
        if(f[a[i]]==0){
            ans+=prod;
            prod+=i;
            cnt++;
        }
        else{
            ans+=prod-f[a[i]]*(i-f[a[i]]);
            prod+=i-f[a[i]];
        }
        f[a[i]]++;
	}
	cout<<ans<<"\n";
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
