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

const int maxn=1e6;
const ll mod=1e9 +7;
vector<int> primes;
int lp[maxn+1];
int nd[maxn+1];
void init(){
	memset(lp,0,sizeof(lp));
	for(int i=2;i<=maxn;i++){
		if(lp[i]==0){
			lp[i]=i;
			primes.pb(i);
		}
		for(int j=0;j<primes.size() && primes[j]<=lp[i] && 	i*primes[j]<=maxn;j++){
			lp[i*primes[j]]=primes[j];
		}
	}
	nd[1]=1;
	for(int i=2;i<=maxn;i++){
        int k=i;
        nd[i]=1;
        while(k>1){
            int p=lp[k],e=0;
            while(k%p==0){
                k/=p;
                e++;
            }
            nd[i]*=e+1;
        }
	}
}
ll fpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
    int t;
    cin>>t;

    while(t--){
        int k;
        ll ans=2;
        cin>>k;
        if(k==1){
            cout<<"0\n";
            continue;
        }
        for(int i=2;i*i<=k;i++){
            if(k%i==0){
                ll delta=(fpow(2,i)-2+mod)%mod;
                delta*=3-nd[k/i];
                delta=((delta%mod)+mod)%mod;
                ans=(ans+delta)%mod;
                if(k/i!=i){
                    delta=(fpow(2,k/i)-2+mod)%mod;
                    delta*=3-nd[i];
                    delta=((delta%mod)+mod)%mod;
                    ans=(ans+delta)%mod;
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
