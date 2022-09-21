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
vector<int> t[4*maxn];
vector<int> a;
vector<int> combine(vector<int> u,vector<int> v){
    vector<int> w(41,0);
    for(int i=1;i<=40;i++) w[i]=u[i]+v[i];
    return w;
}
void build(int v,int l,int r){
    if(l==r){
        t[v]=vector<int>(41,0);
        t[v][a[l]]++;
        return;
    }
    int m=(l+r)/2;
    build(2*v,l,m);
    build(2*v+1,m+1,r);
    t[v]=combine(t[2*v],t[2*v+1]);
}
vector<int> query(int v,int ql,int qr,int l,int r){
    if(ql>qr) return vector<int>(41,0);
    if(ql==l && qr==r) return t[v];
    int m=(l+r)/2;
    return combine(query(2*v,ql,min(m,qr),l,m),query(2*v+1,max(m+1,ql),qr,m+1,r));
}
void update(int v,int pos,int newval,int l,int r){
    if(l==r){
        t[v][a[pos]]--;
        t[v][newval]++;
        a[pos]=newval;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m) update(2*v,pos,newval,l,m);
    else update(2*v+1,pos,newval,m+1,r);
    t[v]=combine(t[2*v],t[2*v+1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	a.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	build(1,0,n-1);
	while(q--){
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1){
            vector<int> f=query(1,l-1,r-1,0,n-1);
            int ans=0;
            for(int i=1;i<=40;i++) if(f[i]) ans++;
            cout<<ans<<"\n";
        }else{
            update(1,l-1,r,0,n-1);
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
