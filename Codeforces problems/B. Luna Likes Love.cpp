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
ll ft[maxn+1];
void add(int pos,ll val){
    for(;pos<=maxn;pos+=pos&-pos){
        ft[pos]+=val;
    }
}
ll sum(int pos){
    ll ans=0;
    for(;pos>0;pos&=pos-1){
        ans+=ft[pos];
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(2*n);
	for(int i=0;i<2*n;i++) cin>>a[i];
	map<int,int> mp;
	for(int i=0,j=1;i<2*n;i++){
        if(mp.count(a[i])==0) mp[a[i]]=j++;
	}
	for(int i=0;i<2*n;i++) a[i]=mp[a[i]];
	ll ans=n;
	for(int i=0,j=0;i<2*n;i++){
        if(a[i]<=j){
            ans+=sum(maxn)-sum(a[i]);
            add(a[i],-1);
        }else{
            add(a[i],1);
            j=a[i];
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
