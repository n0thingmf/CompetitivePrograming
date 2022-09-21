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
pair<int,int> t[4*maxn];

pair<int,int> combine(pair<int,int> a,pair<int,int> b){
    if(a.first<b.first) return a;
    if(a.first>b.first) return b;
    return {a.first,a.second+b.second};
}
void build(vector<int> &a,int v,int l,int r){
    if(l==r){
        t[v]={a[l],1};
        return;
    }
    int m=(l+r)/2;
    build(a,2*v,l,m);
    build(a,2*v+1,m+1,r);
    t[v]=combine(t[2*v],t[2*v+1]);
}
pair<int,int> query(int v,int ql,int qr,int l,int r){
    if(ql>qr) return {INT_MAX,0}; //elemento neutro
    if(ql==l && qr==r) return t[v];
    int m=(l+r)/2;
    return combine(query(2*v,ql,min(m,qr),l,m),query(2*v+1,max(ql,m+1),qr,m+1,r));
}
void update(int v,int pos,ll newval,int l,int r){
    if(l==r){
        t[v]={newval,1};
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	build(a,1,0,n-1);
	for(int i=0;i<m;i++){
        int type,u,v;
        cin>>type>>u>>v;
        if(type==1){
            update(1,u,v,0,n-1);
        }else{
            auto ans=query(1,u,v-1,0,n-1);
            cout<<ans.first<<" "<<ans.second<<"\n";
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
