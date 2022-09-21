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
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
        ll val;
        cin>>val;
        insert(val);
	}
	while(q--){
        ll x;
        cin>>x;
        cout<<answer(x)<<"\n";
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
