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
const int maxn=1e7;

int phi[maxn+1];
void init(){
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= maxn; i++)
        phi[i] = i;

    for (int i = 2; i <= maxn; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= maxn; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t;
	cin>>t;
	while(t--){
        ll n;
        cin>>n;
        ll ans=0;
        for(ll i=1;i*i<=n;i++){
            if(n%i==0){
                ans+=1ll*phi[i]*phi[i];
                if(i!=n/i){
                    ans+=1ll*phi[n/i]*phi[n/i];
                }
            }
        }
        cout<<ans<<"\n";
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
