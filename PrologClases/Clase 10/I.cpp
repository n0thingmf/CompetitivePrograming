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

const int maxn=1e6 +1;
vector<int> primes;
vector<int> lp(maxn);

void criba(){
    for(int i=0;i<maxn;i++) lp[i]=i;
    for(int i=2;i<maxn;i++){
        if(lp[i]==i) primes.pb(i);
        for(int j=0;j<primes.size() && i*primes[j]<maxn;j++){
            lp[i*primes[j]]=primes[j];
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	criba();
	int n,k;
	cin>>n>>k;
    map<int,int> lcm;
	for(int i=0;i<n;i++){
        int c;
        cin>>c;
        while(c>1){
            int p=lp[c],e=0;
            while(c%p==0) c/=p,e++;
            lcm[p]=max(lcm[p],e);
        }
	}
	bool ok=true;
	while(k>1){
        int p=lp[k],e=0;
        while(k%p==0) k/=p,e++;
        if(e>lcm[p]){
            ok=false;
            break;
        }
	}
	if(ok) cout<<"Yes\n";
	else cout<<"No\n";

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
