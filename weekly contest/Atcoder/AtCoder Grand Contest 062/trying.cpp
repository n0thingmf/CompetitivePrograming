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
	cin.tie(0);TECLADO
	vector<int> a={1,2,3,7,7,22};
	int n=a.size();
	set<ll> sms;
	for(ll mask=1;mask<(1ll<<n);mask++){
        ll sum=0;
        for(int i=0;i<n;i++){
            if((mask>>i)&1) sum+=a[i];
        }
        sms.insert(sum);
	}
	for(auto x:sms) cout<<x<<"\n";
	cout<<sms.size()<<" tamanio\n";
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
