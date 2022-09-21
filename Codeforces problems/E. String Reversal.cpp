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
const int maxn=2e5;
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
	memset(ft,0,sizeof(ft));
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<vector<int>> mp(26);
	for(int i=n-1,j=1;i>=0;i--,j++) mp[s[i]-'a'].pb(j);
	vector<int> a(n);
	vector<int> pos(26,0);
	for(int i=0;i<n;i++){
        a[i]=mp[s[i]-'a'][pos[s[i]-'a']];
        pos[s[i]-'a']++;
	}
	vector<int> f(26,0);
	ll inv=0;
	for(int i=0;i<n;i++){
        //cout<<a[i]<<"\n";
        inv+=i-sum(a[i]);
        add(a[i],1);
	}
	cout<<inv<<"\n";
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
