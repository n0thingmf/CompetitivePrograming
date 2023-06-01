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
	int n,m;
	cin>>n>>m;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<set<ll>> b(n);
	for(int i=1;i<=n;i++){
        int k;
        if(a[i-1]>=0) k=0;
        else k=(-a[i-1]+i-1)/i;
        while(a[i-1]+k*i<n){
            b[a[i-1]+k*i].insert(k);
            k++;
        }
	}
	for(int i=1;i<=m;i++){
        int j;
        for(j=0;j<n && b[j].count(i)>0;j++);
        cout<<j<<"\n";
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
