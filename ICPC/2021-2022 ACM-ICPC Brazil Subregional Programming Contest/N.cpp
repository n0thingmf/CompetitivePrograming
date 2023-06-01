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
vector<int> t[4*maxn];
void combine(vector<int> &a,vector<int> &b,vector<int> &c){
    int i,j;
    for(i=0,j=0;i<a.size() && j<b.size();){
        if(a[i]<b[j]){
            c.pb(a[i]);
            i++;
        }
        else{
            c.pb(b[j]);
            j++;
        }
    }
    while(i<a.size()){
        c.pb(a[i]);
        i++;
    }
    while(j<b.size()){
        c.pb(b[j]);
        j++;
    }
}

void build(vector<int> &a,int v,int l,int r){
    if(l==r){
        t[v]=vector<int>(1,a[l]);
        return;
    }
    int m=(l+r)/2;
    build(a,2*v,l,m);
    build(a,2*v+1,m+1,r);
    combine(t[2*v],t[2*v+1],t[v]);

}
int solve(vector<int> &a,int val){
    int x=lower_bound(all(a),val)-a.begin();
    return a.size()-x;
}
int query(int v,int ql,int qr,int l,int r,int val){
    if(ql>qr) return 0;
    if(ql==l && qr==r) return solve(t[v],val);
    int m=(l+r)/2;
    return query(2*v,ql,min(m,qr),l,m,val)+query(2*v+1,max(ql,m+1),qr,m+1,r,val);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int y,n;
	cin>>y>>n;
	vector<int> x(y);
	for(int i=0;i<y;i++) cin>>x[i];
	build(x,1,0,y-1);
	for(int i=0;i<n;i++){
        int a,p,f;
        cin>>a>>p>>f;
        if(p>x[a-1]) cout<<query(1,a,a+f-1,0,y-1,p)<<"\n";
        else cout<<"0\n";
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
