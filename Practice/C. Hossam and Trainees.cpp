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

const int maxp = 31623;
int lp[maxp];
vector<int> primes;
void init(){
    for(int i=0;i<maxp;i++) lp[i]=i;
    for(int i=2;i<maxp;i++){
        if(lp[i]==i){
            primes.pb(i);
        }
        for(int j=0;j<primes.size() && i*primes[j]<maxp;j++){
            lp[i*primes[j]]=primes[j];
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
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        unordered_map<int,int> pms;
        for(int i=0;i<n;i++){
            for(int j=0;j<primes.size() && primes[j]<=a[i];j++){
                if(a[i]%primes[j]==0){
                    while(a[i]%primes[j]==0) a[i]/=primes[j];
                    pms[primes[j]]++;
                }
            }
            if(a[i]>1) pms[a[i]]++;
        }
        bool ok=false;
        for(auto x:pms){
            if(x.second>1){
                ok=true;
                break;
            }
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
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
