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
int n,m;
const int maxn=1e2;
int tab[maxn][maxn];
bool vis[maxn][maxn];
int maxx,minx,maxy,miny;
int bfs(int x,int y){
    if(x>maxx) maxx=x;
    if(x<minx) minx=x;
    if(y>maxy) maxy=y;
    if(y<miny) miny=y;
    vis[x][y]=true;
    int cnt=1;
    if(x>=1 && tab[x-1][y]==1 &&!vis[x-1][y]){
        cnt+=bfs(x-1,y);
    }
    if(y>=1 && tab[x][y-1]==1 && !vis[x][y-1]){
        cnt+=bfs(x,y-1);
    }
    if(x<n-1 && tab[x+1][y]==1 && !vis[x+1][y]){
        cnt+=bfs(x+1,y);
    }
    if(y<m-1 && tab[x][y+1]==1 && !vis[x][y+1]){
        cnt+=bfs(x,y+1);
    }
    return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='0') tab[i][j]=0;
                else tab[i][j]=1;
                vis[i][j]=false;
            }
        }
        bool ok=true;
        for(int i=0;i<n && ok;i++){
            for(int j=0;j<m && ok;j++){
                if(tab[i][j] && !vis[i][j]){
                    minx=miny=INT_MAX;
                    maxx=maxy=INT_MIN;
                    int ans=bfs(i,j);
                    //cout<<ans<<" "<<minx<<" "<<maxx<<" "<<miny<<" "<<maxy<<"\n";
                    if(ans!=(maxx-minx+1)*(maxy-miny+1)) ok=false;
                }
            }
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
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
