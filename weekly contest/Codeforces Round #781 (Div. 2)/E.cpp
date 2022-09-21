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
int n;
int a[maxn];
int t[4*maxn];
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
int solve(int l,int r,int mask){
    int m1,m2,v1,v2;

    m1=query(1,l,r,0,n-1);
    v1=a[m1];
    update(1,m1,1<<30,0,n-1);// to cal m2
    m2=query(1,l,r,0,n-1);
    v2=a[m2];
    update(1,m1,v1,0,n-1);//to normal
       /* for(int i=l;i<=r;i++){
            cout<<bitset<30>(a[i])<<"\n";
        }
cout<<"\n";*/
    if((v1^mask)==0) return v1|v2;
    int bi1=max_bit(v1^mask),bi2=max_bit(v2^mask);
        mask|=1<<bi2;
        update(1,m1,v1|(1<<bi2),0,n-1);
        int ans=solve(l,r,mask);
        update(1,m1,v1,0,n-1);
        return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
/* for(int i=0;i<n;i++){
    cout<<bitset<30>(a[i])<<"\n";
}*/
        build(1,0,n-1);
        int q;
        cin>>q;
        while(q--){
            int l,r;
            cin>>l>>r;
            cout<<solve(l-1,r-1,0)<<"\n";
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
