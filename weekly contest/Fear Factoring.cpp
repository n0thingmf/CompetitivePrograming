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

const ll maxn=1e6;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a,b,ans=0;
	cin>>a>>b;
	for(ll i=1;i<=maxn;i++){
        for(ll j=((a+i-1)/i)*i;j<=b;j+=i){
            if(j%i==0){
                ans+=i;
                if((j/i)>maxn) ans+=j/i;
            }
        }
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
