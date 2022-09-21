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

const int maxn=1e3;
int n,m;
int tab[maxn][maxn];
bool isok(int x,int y){
   if(x<0 || x>=n) return false;
   if(y<0 || y>=m) return false;
   if(tab[x][y]) return false;
   return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) tab[i][j]=0;
    ll ans=0;
    for(int k=1,i=1,j=1;i<=n && j<=m;k&1?j++:i++){
        ans+=(n-i+1)*(m-j+1);
        k++;
    }
    for(int k=1,i=1,j=1;i<=n && j<=m;k&1?i++:j++){
        ans+=(n-i+1)*(m-j+1);
        k++;
    }
    ans-=n*m;
    while(q--){
        ll delta=0;
        int x,y;
        cin>>x>>y;
        x--,y--;
        int i=1,j=1;
        while(isok(x+(i+1)/2,y+i/2)) i++;
        while(isok(x-j/2,y-(j+1)/2)) j++;
        delta+=1ll*i*j;
        i=1,j=1;
        while(isok(x+i/2,y+(i+1)/2)) i++;
        while(isok(x-(j+1)/2,y-j/2)) j++;
        delta+=1ll*i*j;
        delta--;
        if(tab[x][y]) ans+=delta;
        else ans-=delta;
        tab[x][y]^=1;
        cout<<ans<<"\n";
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
