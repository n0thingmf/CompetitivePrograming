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

const int maxn=3e5;
ll ft1[maxn+1],ft2[maxn+1];

void add(ll ft[],int pos,ll val){
    for(++pos;pos<=maxn;pos+=pos&-pos){
        ft[pos]+=val;
    }
}
ll sum(ll ft[],int pos){
    ll ans=0;
    for(++pos;pos>0;pos&=pos-1){
        ans+=ft[pos];
    }
    return ans;
}
void range_update(int l,int r,ll delta){
    add(ft1,l,delta);
    add(ft1,r+1,-delta);
    add(ft2,l,-delta*l);
    add(ft2,r+1,delta*(r+1));
}
ll pref_sum(int pos){
    return sum(ft1,pos)*(pos+1)+sum(ft2,pos);
}
ll range_query(int l,int r){
    if(l==0) return pref_sum(r);
    return pref_sum(r)-pref_sum(l-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<ll> a(n,0),b(n);
	for(int i=0;i<n;i++) cin>>b[i];
	memset(ft1,0,sizeof(ft1));
	memset(ft2,0,sizeof(ft2));
	ll ans=0;
	for(int i=n-1;i>=k-1;i--){
        ll now=pref_sum(i);
        //cout<<i<<" "<<now<<"\n";
        ll d=(b[i]-now+k-1)/k;
        if(d>=0){
            range_update(i-k+1,i,d);
            ans+=d;
        }
	}
	for(int i=k-2;i>=0;i--){
        ll now=pref_sum(i);
        //cout<<i<<" "<<now<<"\n";
        ll d=(b[i]-now+i)/(i+1);
        if(d>=0){
            range_update(0,k-1,d);
            ans+=d;
        }
	}
	/*for(int i=0;i<n;i++){
        cout<<pref_sum(i)<<" ";
	}
	cout<<"\n";*/
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
