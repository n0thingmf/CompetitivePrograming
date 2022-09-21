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
class datos{
public:
    ll ans,sum,pref,suf;
    datos(){
        ans=sum=pref=suf=0;
    }
    datos(int val){
        sum=val;
        ans=pref=suf=max(val,0);
    }
};
datos t[4*maxn];
datos combine(datos a,datos b){
    datos res;
    res.sum=a.sum+b.sum;
    res.pref=max(a.pref,a.sum+b.pref);
    res.suf=max(a.suf+b.sum,b.suf);
    res.ans=max(max(a.ans,b.ans),a.suf+b.pref);
    return res;
}
void build(vector<ll> &a,int v,int l,int r){
    if(l==r){
        t[v]=datos(a[l]);
        return;
    }
    int m=(l+r)/2;
    build(a,2*v,l,m);
    build(a,2*v+1,m+1,r);
    t[v]=combine(t[2*v],t[2*v+1]);
}
datos query(int v,int ql,int qr,int l,int r){
    if(ql>qr) return datos(0);
    if(ql==l && qr==r) return t[v];
    int m=(l+r)/2;
    return combine(query(2*v,ql,min(m,qr),l,m),query(2*v+1,max(ql,m+1),qr,m+1,r));
}
void update(int v,int pos,int newval,int l,int r){
    if(l==r){
        t[v]=datos(newval);
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	build(a,1,0,n-1);
        cout<<query(1,0,n-1,0,n-1).ans<<"\n";
	for(int i=0;i<m;i++){
        int u;
        ll v;
        cin>>u>>v;
        update(1,u,v,0,n-1);
        cout<<query(1,0,n-1,0,n-1).ans<<"\n";
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
