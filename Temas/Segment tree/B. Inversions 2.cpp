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
int query(int v,int k,int l,int r){
    if(l==r) return l+1;
    int m=(l+r)/2;
    if(k>=t[2*v+1]){
        return query(2*v,k-t[2*v+1],l,m);
    }else{
        return query(2*v+1,k,m+1,r);
    }
}
void update(int v,int pos,int newval,int l,int r){
    if(l==r){
        t[v]=newval;
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
	int n;
	cin>>n;
	vector<int> a(n,1);
    build(a,1,0,n-1);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[i]=query(1,a[i],0,n-1);
        update(1,ans[i]-1,0,0,n-1);
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
