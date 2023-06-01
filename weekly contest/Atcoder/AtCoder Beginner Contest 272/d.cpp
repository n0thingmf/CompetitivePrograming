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

const int maxn=400,maxm=1e6+1,inf=1e8;
int n;
int tab[maxn][maxn];
int dx[4]={1,-1,1,-1};
int dy[4]={1,1,-1,-1};
vector<pair<int,int>> p;

void init(int m){
    vector<int> dp(maxm,-1);
    for(int i=0;i*i<=m;i++){
        dp[i*i]=i;
    }
    for(int i=0;i*i<=m;i++){
        if(dp[m-i*i]!=-1) p.pb({i,dp[m-i*i]});
    }
}
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        auto now=q.front();
        q.pop();
        for(auto s:p){
            for(int i=0;i<4;i++){
                pair<int,int> next={now.first+dx[i]*s.first,now.second+dy[i]*s.second};
                if(next.first>=0 && next.first<n && next.second>=0 && next.second<n){
                    if(tab[next.first][next.second]>tab[now.first][now.second]+1){
                        tab[next.first][next.second]=tab[now.first][now.second]+1;
                        q.push(next);
                    }
                }
            }
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin>>n>>m;
	init(m);
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) tab[i][j]=inf;
	tab[0][0]=0;
	bfs(0,0);
	/*cout<<"pairs\n";
	for(auto s:p) cout<<s.first<<" "<<s.second<<"\n";*/
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tab[i][j]!=inf) cout<<tab[i][j]<<" ";
            else cout<<"-1 ";
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
