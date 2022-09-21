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

const int maxn=2e5;
int t[4*maxn];
int combine(int a,int b){
    return a+b;
}
void build(vector<int> &a,int v,int l,int r){
    if(l==r){
        t[v]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(a,2*v,l,m);
    build(a,2*v+1,m+1,r);
    t[v]=combine(t[2*v],t[2*v+1]);
}
int query(int v,int ql,int qr,int l,int r){
    if(ql>qr) return 0;
    if(ql==l && qr==r) return t[v];
    int m=(l+r)/2;
    return combine(query(2*v,ql,min(m,qr),l,m),query(2*v+1,max(ql,m+1),qr,m+1,r));
}
void update(int v,int pos,int delta,int l,int r){
    if(l==r){
        t[v]+=delta;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m){
        update(2*v,pos,delta,l,m);
    }else{
        update(2*v+1,pos,delta,m+1,r);
    }
    t[v]=combine(t[2*v],t[2*v+1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(2*n);
	vector<pair<pair<int,int>,int>> e(n,{{-1,-1},0});
	for(int i=0;i<2*n;i++){
        cin>>a[i];
        if(e[a[i]-1].first.first==-1) e[a[i]-1].first.first=i;
        else{
            e[a[i]-1].first.second=i;
            e[a[i]-1].second=a[i];
            update(1,i,1,0,2*n);
        }
	}
	sort(all(e));
	vector<int> ans(n);
	for(auto iv:e){
        update(1,iv.first.second,-1,0,2*n);
        ans[iv.second-1]=query(1,0,iv.first.second,0,2*n);
	}
	for(int i=0;i<n;i++) cout<<ans[i]<<" ";
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
