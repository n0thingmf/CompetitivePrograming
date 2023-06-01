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
const int maxn=1e7+1;

int lp[maxn];
vector<int> primes;
void init(){
    for(int i=0;i<maxn;i++) lp[i]=i;
    for(int i=2;i<maxn;i++){
        if(lp[i]==i){
            primes.pb(i);
        }
        for(int j=0;j<primes.size() && i*primes[j]<maxn;j++){
            lp[i*primes[j]]=primes[j];
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        if(__gcd(x,y)!=1){
            cout<<"0\n";
            continue;
        }
        int d=abs(x-y);
        if(d==1){
            cout<<"-1\n";
            continue;
        }
        ll ans=LLONG_MAX;
        while(d>1){
            ll p=lp[d];
            ll ans1=((x+p-1)/p)*p-x;
            ll ans2=((y+p-1)/p)*p-y;
            ans=min(ans,min(ans1,ans2));
            d/=p;
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
