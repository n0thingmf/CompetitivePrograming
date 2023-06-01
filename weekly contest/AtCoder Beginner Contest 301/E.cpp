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
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;
	int h,w,t;
	cin>>h>>w>>t;
	vector<string> tab(h);
	int ini,fin;
	vector<int> candy;
	for(int i=0;i<h;i++){
        cin>>tab[i];
        for(int j=0;j<w;j++){
            if(tab[i][j]=='S') ini=i*w+j;
            else if(tab[i][j]=='G') fin=i*w+j;
            else if(tab[i][j]=='o') candy.pb(i*w+j);
        }
	}
	int nc=candy.size();
	vector<vector<int>> d(h,vector<int>(w));
	auto bfs=[&](int sx,int sy)->void{
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++) d[i][j]=INT_MAX;
        d[sx][sy]=0;
        queue<pair<int,int>> q;
        q.push({sx,sy});
        while(!q.empty()){
            pair<int,int> now=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                pair<int,int> next={now.first+dx[i],now.second+dy[i]};
                if(0<=next.first && next.first<h && 0<=next.second && next.second<w && tab[next.first][next.second]!='#' && d[next.first][next.second]==INT_MAX){
                    d[next.first][next.second]=d[now.first][now.second]+1;
                    q.push(next);
                }
            }
        }
	};
	vector<vector<int>> dd(nc+2,vector<int>(nc+2,0));
	bfs(ini/w,ini%w);
	for(int i=0;i<nc;i++) dd[0][i+1]=d[candy[i]/w][candy[i]%w];
	dd[0][nc+1]=d[fin/w][fin%w];
	if(dd[0][nc+1]==INT_MAX || dd[0][nc+1]>t){
        cout<<"-1\n";
        return 0;
	}
	for(int i=0;i<nc;i++){
        bfs(candy[i]/w,candy[i]%w);
        dd[i+1][0]=d[ini/w][ini%w];
        dd[i+1][nc+1]=d[fin/w][fin%w];
        for(int j=0;j<nc;j++) dd[i+1][j+1]=d[candy[j]/w][candy[j]%w];
	}

    vector<vector<ll>> dp(1<<nc,vector<ll>(nc,INT_MAX));
    for(int i=0;i<nc;i++){
        dp[1<<i][i]=dd[0][i+1];
    }
    int ans=0;
    for(int mask=1;mask<(1<<nc);mask++){
        for(int i=0;i<nc;i++){
            if((mask>>i)&1){
                int cnt=0;
                for(int j=0;j<nc;j++){
                    if((mask>>j)&1){
                       cnt++;
                    }else{
                        dp[mask|(1<<j)][j]=min(dp[mask|(1<<j)][j],dp[mask][i]+dd[i+1][j+1]);
                    }
                }
                if(dp[mask][i]+dd[i+1][nc+1]<=t) ans=max(ans,cnt);
            }
        }
    }
    cout<<ans<<"\n";
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
