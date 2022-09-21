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
int r;
int t[4*maxn][2][2];
int a[maxn][2][2];
void combine(int x[2][2],int y[2][2],int z[2][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            z[i][j]=0;
            for(int k=0;k<2;k++) z[i][j]=(z[i][j]+x[i][k]*y[k][j])%r;
        }
    }
}
void build(int v,int l,int r){
    if(l==r){
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++) t[v][i][j]=a[l][i][j];
        return;
    }
    int m=(l+r)/2;
    build(2*v,l,m);
    build(2*v+1,m+1,r);
    combine(t[2*v],t[2*v+1],t[v]);
}
void query(int v,int ql,int qr,int l,int r,int ans[2][2]){
    if(ql>qr){
        ans[0][0]=ans[1][1]=1;
        ans[0][1]=ans[1][0]=0;
        return;
    }
    if(ql==l && qr==r){
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++) ans[i][j]=t[v][i][j];
        return;
    }
    int m=(l+r)/2;
    int x[2][2],y[2][2];
    query(2*v,ql,min(m,qr),l,m,x);
    query(2*v+1,max(ql,m+1),qr,m+1,r,y);
    combine(x,y,ans);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>r>>n>>m;
	for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                cin>>a[i][j][k];
                a[i][j][k]%=r;
            }
        }
	}
	build(1,0,n-1);
	for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        int ans[2][2];
        query(1,l-1,r-1,0,n-1,ans);
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                cout<<ans[j][k]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
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
