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
int t[4*maxn];
vector<int> a;
int combine(int i,int j){
    if(i==-1 && j==-1) return -1;
    if(i==-1) return j;
    if(j==-1) return i;
    if(a[i]<a[j]) return i;
    else return j;
}
void build(int v,int l,int r){
    if(l==r){
        t[v]=l;
        return;
    }
    int m=(l+r)/2;
    build(2*v,l,m);
    build(2*v+1,m+1,r);
    t[v]=combine(t[2*v],t[2*v+1]);
}
int query(int v,int ql,int qr,int l,int r){
    if(ql>qr) return -1;
    if(ql==l && qr==r) return t[v];
    int m=(l+r)/2;
    return combine(query(2*v,ql,min(m,qr),l,m),query(2*v+1,max(ql,m+1),qr,m+1,r));
}
void update(int v,int pos,int newval,int l,int r){
    if(l==r){
        a[pos]=newval;
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
	a.resize(n,INT_MAX);
	build(1,0,n-1);
	while(m--){
        int type;
        cin>>type;
        if(type==1){
            int i,h;
            cin>>i>>h;
            update(1,i,h,0,n-1);
        }else{
            int l,r,p;
            cin>>l>>r>>p;
            int k=query(1,l,r-1,0,n-1),ans=0;
            while(a[k]<=p){
                    ans++;
                update(1,k,INT_MAX,0,n-1);
                k=query(1,l,r-1,0,n-1);
            }
            cout<<ans<<"\n";
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
