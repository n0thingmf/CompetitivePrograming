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

typedef pair<int,int> ii;
typedef vector<int> vi;
const int N = 405;
const int R = 4e5;
int dp[N][N];
vector<pair<int,int>> mov[R];
int n,m;

bool valid(int x,int y){
    return  x>=1 && y>=1 && x<=n && y<=n;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>m;

    if(m>=R){
        memset(dp,-1,sizeof(dp));
        dp[1][1] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dp[i][j]<<" ";

            }
            cout<<endl;
        }
        return 0;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int val = i*i+j*j;

            if(val<R){
                mov[val].pb({i,j});
                mov[val].pb({-i,-j});
                mov[val].pb({i,-j});
                mov[val].pb({-i,j});

                mov[val].pb({j,i});
                mov[val].pb({-j,-i});
                mov[val].pb({j,-i});
                mov[val].pb({-j,i});
            }
        }
    }

        queue<ii>q;
        q.push({1,1});
        memset(dp,-1,sizeof(dp));
        dp[1][1] = 0;
        while(!q.empty()){
            auto e = q.front();
            q.pop();
            for(auto mv:mov[m]){
                int nx,ny;
                nx = e.first + mv.first , ny = e.second + mv.second;
                if(valid(nx,ny)){
                    if(dp[nx][ny]==-1){
                        dp[nx][ny] =  dp[e.first][e.second] +1 ;
                        q.push({nx,ny});
                    }
                    else if(dp[e.first][e.second] +1 <dp[nx][ny]){
                            dp[nx][ny] =  dp[e.first][e.second] +1 ;
                            q.push({nx,ny});
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dp[i][j]<<" ";

            }
            cout<<endl;
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
