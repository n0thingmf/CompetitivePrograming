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
const int maxn=5e5+1;
const ll big = 1e9;
int ft[maxn];

void update(int pos,int val){
    for(++pos;pos<maxn;pos+=pos&-pos){
        ft[pos]+=val;
    }
}

int sum(int pos){
    int ans=0;
    for(++pos;pos>0;pos&=pos-1){
        ans+=ft[pos];
    }
    return ans;
}

int query(int l,int r){
    return sum(r)-sum(l-1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int q;
	cin>>q;
	while(q--){
        int m;
        cin>>m;
        memset(ft,0,m+1);
        ll ans=0;
        map<ll,vector<int>> val;
        for(int i=0;i<m;i++){
            int id;
            cin>>id;
            val[big-a[id-1]].pb(i);
        }
        for(auto x:val){
            for(int i:x.second){
                update(i,1);
            }
            for(int i:x.second){
                ll cnt=1;
                int l=0,r=i;
                while(l<r){
                    int m=(l+r)/2;
                    if(query(m,i)==1) r=m;
                    else l=m+1;
                }
                cnt*=i-l+1;
                l=i,r=m-1;
                while(l<r){
                    int m=(l+r+1)/2;
                    if(query(i,m)==1) l=m;
                    else r=m-1;
                }
                cnt*=l-i+1;
                cout<<i<<" "<<(big-x.first)<<" "<<cnt<<"\n";
                ans+=(big-x.first)*cnt;
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
