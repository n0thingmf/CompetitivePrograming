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

int tab[40][40];
int dp[40][40][40][40];
int cnt[40][40][40][40];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='0') tab[i][j]=0;
            else tab[i][j]=1;
        }
	}
	for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) dp[i][j][0][0]=tab[i][j]==0;
	//sum
	for(int i=0;i<n;i++)
        for(int j=1;j<m;j++) tab[i][j]+=tab[i][j-1];
	for(int j=0;j<m;j++)
        for(int i=1;i<n;i++) tab[i][j]+=tab[i-1][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int l=0;i+l<n;l++){
                for(int r=0;j+r<m;r++){
                    if(l==0 && r==0) continue;
                    if(i==0 && j==0) dp[i][j][l][r]=tab[i+l][j+r]==0;
                    else if(i==0) dp[i][j][l][r]=tab[i+l][j+r]-tab[i+l][j-1]==0;
                    else if(j==0) dp[i][j][l][r]=tab[i+l][j+r]-tab[i-1][j+r]==0;
                    else dp[i][j][l][r]=tab[i+l][j+r]-tab[i-1][j+r]-tab[i+l][j-1]+tab[i-1][j-1]==0;
                    if(l==0) dp[i][j][l][r]+=dp[i][j][l][r-1];
                    else if(r==0) dp[i][j][l][r]+=dp[i][j][l-1][r];
                    else dp[i][j][l][r]+=dp[i][j][l-1][r]+dp[i][j][l][r-1]-dp[i][j][l-1][r-1];
                }
            }
        }
    }
    for(int l=0;l<n;l++){
        for(int r=0;r<m;r++){
            for(int i=0;i+l<n;i++){
                for(int j=0;j+r<m;j++){
                    if(l==0 && r==0) cnt[i][j][l][r]=dp[i][j][0][0];
                    else if(l==0) cnt[i][j][l][r]=cnt[i][j+1][l][r-1]+dp[i][j][l][r];
                    else if(r==0) cnt[i][j][l][r]=cnt[i+1][j][l-1][r]+dp[i][j][l][r];
                    else cnt[i][j][l][r]=cnt[i+1][j][l-1][r]+cnt[i][j+1][l][r-1]-cnt[i+1][j+1][l-1][r-1]+dp[i][j][l][r];
                }
            }
        }
    }
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<cnt[a-1][b-1][c-a][d-b]<<"\n";
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
