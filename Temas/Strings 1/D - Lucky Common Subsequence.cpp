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
int n1,n2,nv;
string s1,s2,virus;
int go[100][26];
int dp[101][101][100];
tuple<int,int,int> bk[101][101][100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2>>virus;
	n1=s1.size(),n2=s2.size(),nv=virus.size();
	tuple<int,int,int> fin=make_tuple(-1,-1,-1);
    vector<int> phi(nv,0);
    for(int i=1;i<nv;i++){
        int j=phi[i-1];
        while(j>0 && virus[i]!=virus[j]) j=phi[j-1];
        if(virus[i]==virus[j]) j++;
        phi[i]=j;
    }
    for(int i=0;i<nv;i++){
        for(char c='A';c<='Z';c++){
            int j=i;
            while(j>0 && virus[j]!=c) j=phi[j-1];
            if(virus[j]==c) j++;
            go[i][c-'A']=j;
        }
    }
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<nv;k++){
                dp[i][j][k]=0;
                bk[i][j][k]=fin;
            }
        }
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            for(int k=0;k<nv;k++){
                int next=go[k][s1[i]-'A'];
                if(s1[i]==s2[j] && next<nv){
                    if(dp[i+1][j+1][next]<dp[i][j][k]+1){
                        dp[i+1][j+1][next]=dp[i][j][k]+1;
                        bk[i+1][j+1][next]=make_tuple(i,j,k);
                    }
                }
                if(dp[i+1][j][k]<dp[i][j][k]){
                    dp[i+1][j][k]=dp[i][j][k];
                    bk[i+1][j][k]=bk[i][j][k];
                }
                if(dp[i][j+1][k]<dp[i][j][k]){
                    dp[i][j+1][k]=dp[i][j][k];
                    bk[i][j+1][k]=bk[i][j][k];
                }
            }
        }
    }
    int ans=0;
    tuple<int,int,int> bans;
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<nv;k++){
                if(dp[i][j][k]>ans){
                    ans=dp[i][j][k];
                    bans=bk[i][j][k];
                }
            }
        }
    }
    string ss="";
    while(bans!=fin){
        ss.pb(s1[get<0>(bans)]);
        bans=bk[get<0>(bans)][get<1>(bans)][get<2>(bans)];
    }
    reverse(all(ss));
    if(ans) cout<<ss<<"\n";
    else cout<<"0\n";
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
