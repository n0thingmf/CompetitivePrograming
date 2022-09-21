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
const int maxn=1e5;

int ft[maxn+1];
void update(int i){
    for(;i<=maxn;i+=i&-i){
        ft[i]++;
    }
}
int query(int i){
    int ans=0;
    for(;i>0;i=i&(i-1)){
        ans+=ft[i];
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(ft,0,sizeof(ft));
	vector<int> a(maxn+1);
	vector<bool> prime(maxn+1,true);
	for(int i=2;i<=maxn;i++){
        if(!prime[i]) continue;
        a[i]=i;
        for(int j=2;1ll*i*j<=maxn;j++){
            prime[i*j]=false;
            a[i*j]=i;
        }
	}
	int q;
	cin>>q;
	vector<set<pair<int,int>>> b(maxn+1);
	vector<int> ans(q);
	for(int i=0;i<q;i++){
        int n,k;
        cin>>n>>k;
        b[n].insert({k,i});
	}
	for(int i=2;i<=maxn;i++){
        update(a[i]);
        for(auto pr:b[i]){
            ans[pr.second]=query(pr.first);
        }
	}
	for(int i=0;i<q;i++){
        cout<<ans[i]<<"\n";
	}
	//for(int i=2;i<=100;i++) cout<<i<<" "<<a[i]<<"\n";
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
