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
const int maxn=6e6+1;
int trie[maxn][2];
int node=0;
void insert(ll n){
    int pos=0;
    for(int i=59;i>=0;i--){
        int next=(n>>i)&1;
        if(trie[pos][next]==0) trie[pos][next]=++node;
        pos=trie[pos][next];
    }
}
ll answer(ll x){
    ll res=0;
    int pos=0;
    for(int i=59;i>=0;i--){
        int bit=(x>>i)&1;
        if(trie[pos][bit^1]){
            pos=trie[pos][bit^1];
            res|=(1ll*(bit^1))<<i;
        }
        else{
            pos=trie[pos][bit];
            res|=(1ll*(bit))<<i;
        }
    }
    return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll> a(n+1);
	a[0]=0;
	map<ll,int> mp;
	mp[0]=0;
	for(int i=1;i<n+1;i++){
        cin>>a[i];
        a[i]=a[i]^a[i-1];
	}
	ll ans=LLONG_MIN;
	int l,r;
	insert(a[0]);
	for(int i=1;i<=n;i++){
        ll res=answer(a[i]);
        if((res^a[i])>=ans){
            ans=res^a[i];
            l=mp[res]+1;
            r=i;
        }
        mp[a[i]]=i;
        insert(a[i]);
	}
	cout<<l<<" "<<r<<" "<<ans<<"\n";
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
