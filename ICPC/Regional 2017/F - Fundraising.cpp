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

ll ft[maxn+1];
void update(int pos,ll newv){
    for(++pos;pos<=maxn;pos+=pos&-pos){
        ft[pos]=max(ft[pos],newv);
    }
}
ll query(int pos){
    ll ans=0;
    for(++pos;pos>0;pos&=(pos-1)){
        ans=max(ans,ft[pos]);
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(ft,0,sizeof(ft));
	int n,ind=0;
	cin>>n;
	map<int,int> mp;
	map<int,map<int,ll>> f;
	for(int i=0;i<n;i++){
        int x,y;
        ll v;
        cin>>x>>y>>v;
        f[x][y]+=v;
        mp[y]=0;
	}
	for(auto m:mp){
        mp[m.first]=ind++;
	}
	for(auto p:f){
        vector<pair<int,ll>> updates;
        for(auto pr:p.second){
            if(mp[pr.first]>0) updates.pb({mp[pr.first],query(mp[pr.first]-1)+pr.second});
            else updates.pb({mp[pr.first],pr.second});
        }
        for(auto pr:updates){
            update(pr.first,pr.second);
        }
	}
	cout<<query(maxn-1);
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
