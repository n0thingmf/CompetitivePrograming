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

const int maxn=15e6+1;

int lp[maxn];
vector<int> primes;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<maxn;i++) lp[i]=i;
	for(int i=2;i<maxn;i++){
        if(lp[i]==i){
            primes.pb(i);
        }
        //primes tiene todos los primos hasta i
        for(int j=0;j<primes.size() && primes[j]*i<maxn;j++){
            lp[primes[j]*i]=primes[j]; // actualiza
        }
	}
	int x;
	cin>>x;
	vector<pair<int,int>> fact;
	while(x>1){
        int e=0,f=lp[x];
        while(x%f==0) x/=f,e++;
        fact.pb({f,e});
	}
	for(auto ff:fact){
        cout<<ff.first<<" ^ "<<ff.second<<"\n";
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
