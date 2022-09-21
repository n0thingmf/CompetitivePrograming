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

const int maxn=5e5+2;
vector<int> adj[maxn];
int t1[4*maxn],t2[4*maxn],timer=0;
int low[maxn],up[maxn],vertex[maxn];
bool marked[4*maxn];

void push(int v){
    if(marked[v]){
        t1[2*v]=t1[2*v+1]=t1[v];
        marked[v]=false;
        marked[2*v]=marked[2*v+1]=true;
    }
}
void update1(int v,int ql,int qr,int l,int r,int val){
    if(ql>qr) return;
    if(ql==l && qr==r){
        t1[v]=val;
        marked[v]=true;
    }else{
        int m=(l+r)/2;
        push(v);
        update1(2*v,ql,min(m,qr),l,m,val);
        update1(2*v+1,max(m+1,ql),qr,m+1,r,val);
    }
}
int query1(int v,int pos,int l,int r){
    if(l==r){
        return t1[v];
    }else{
        int m=(l+r)/2;
        push(v);
        if(pos<=m) return query1(2*v,pos,l,m);
        else return query1(2*v+1,pos,m+1,r);
    }
}
void update2(int v,int pos,int val,int l,int r){
    if(l==r){
        t2[v]=val;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m) update2(2*v,pos,val,l,m);
    else update2(2*v+1,pos,val,m+1,r);
    t2[v]=max(t2[2*v],t2[2*v+1]);
}
int query2(int v,int ql,int qr,int l,int r){
    if(ql>qr) return -1;
    if(ql==l && qr==r){
        return t2[v];
    }else{
        int m=(l+r)/2;
        return max(query2(2*v,ql,min(m,qr),l,m),query2(2*v+1,max(m+1,ql),qr,m+1,r));
    }
}

void dfs(int v,int p){
    low[v]=timer;
    vertex[timer]=v;
    timer++;
    for(int u:adj[v]){
        if(u!=p){
            dfs(u,v);
        }
    }
    up[v]=timer-1;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n;
	for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].pb(b);
        adj[b].pb(a);
	}
	dfs(0,-1);
	for(int i=0;i<n;i++){
        update2(1,i,1,0,n-1);
	}
	cin>>q;
	for(int i=2;i<=q+1;i++){
        int c,v;
        cin>>c>>v;
        v--;
        if(c==1){
            update1(1,low[v],up[v],0,n-1,i);
        }else if(c==2){
            update2(1,low[v],i,0,n-1);
        }else{
            int ans1=query1(1,low[v],0,n-1);
            int ans2=query2(1,low[v],up[v],0,n-1);
            if(ans1>ans2) cout<<"1\n";
            else cout<<"0\n";
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
