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
ll t[4*maxn];
int n,m;

ll combine(ll a,ll b){
    return a+b;
}
ll query(int v,int ql,int qr,int l,int r){
    if(ql>qr) return 0;
    if(ql==l && qr==r) return t[v];
    int m=(l+r)/2;
    return combine(query(2*v,ql,min(m,qr),l,m),query(2*v+1,max(ql,m+1),qr,m+1,r));
}
void update(int v,int pos,ll newval,int l,int r){
    if(l==r){
        t[v]+=newval;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m){
        update(2*v,pos,newval,l,m);
    }else{
        update(2*v+1,pos,newval,m+1,r);
    }
    t[v]=combine(t[2*v],t[2*v+1]);
}
void range_update(int l,int r,ll delta){
    update(1,l,delta,0,n-1);
    if(r+1<n) update(1,r+1,-delta,0,n-1);
}
ll point_query(int pos){
    return query(1,0,pos,0,n-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
        int type;
        cin>>type;
        if(type==1){
            int l,r,v;
            cin>>l>>r>>v;
            range_update(l,r-1,v);
        }else{
            int pos;
            cin>>pos;
            cout<<point_query(pos)<<"\n";
        }
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
