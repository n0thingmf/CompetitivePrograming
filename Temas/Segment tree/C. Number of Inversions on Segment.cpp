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

class data{
public:
    ll inv;
    int f[41];
    data(){
        inv=0;
        for(int i=1;i<=40;i++) f[i]=0;
    }
    data operator =(const data &other){
        inv=other.inv;
        for(int i=1;i<=40;i++) f[i]=other.f[i];
        return *this;
    }
};

const int maxn=1e5;
data t[4*maxn];
int a[maxn];

data combine(data a,data b){
    data ans;
    ans.inv=a.inv+b.inv;
    ll acum=0;
    for(int i=1;i<=40;i++){
        ans.inv+=acum*a.f[i];
        acum+=b.f[i];
    }
    for(int i=1;i<=40;i++) ans.f[i]=a.f[i]+b.f[i];
    return ans;
}
void build(int v,int l,int r){
    if(l==r){
        t[v].f[a[l]]++;
        return;
    }
    int m=(l+r)/2;
    build(2*v,l,m);
    build(2*v+1,m+1,r);
    t[v]=combine(t[2*v],t[2*v+1]);
}
data query(int v,int ql,int qr,int l,int r){
    if(ql>qr) return data();
    if(ql==l && qr==r) return t[v];
    int m=(l+r)/2;
    return combine(query(2*v,ql,min(m,qr),l,m),query(2*v+1,max(ql,m+1),qr,m+1,r));
}
void update(int v,int pos,int newval,int l,int r){
    if(l==r){
        t[v].f[a[pos]]--;
        a[pos]=newval;
        t[v].f[a[pos]]++;
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
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    build(1,0,n-1);
    while(q--){
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1){
            cout<<query(1,l-1,r-1,0,n-1).inv<<"\n";
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
