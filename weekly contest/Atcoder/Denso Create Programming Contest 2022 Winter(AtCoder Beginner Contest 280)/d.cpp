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

const ll maxn=1e12;
ll check(ll a,ll p){
    ll ans=0;
    while(a>=p){
        ans+=a/p;
        a=a/p;
    }
    return ans;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	ll k,delta=1;
	cin>>k;
	vector<pair<ll,ll>> fact;
	for(ll i=2;i*i<=k;i++){
        if(k%i==0){
            int e=0;
            while(k%i==0) e++,k/=i;
            fact.pb({i,e});
        }
	}
	if(k>1){
        fact.pb({k,1});
	}
	ll ans=0;
	for(auto x:fact){
        ll l=x.first,r=maxn;
        while(l<r){
            ll m=(l+r)/2;
            if(check(m,x.first)<x.second) l=m+1;
            else r=m;
        }
        ans=max(ans,l);
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
