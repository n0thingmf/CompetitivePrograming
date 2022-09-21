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

bool dp[maxn+1][maxn];
pair<int,int> p[maxn+1][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n,m;
	cin>>s>>m;
	n=s.size();
	for(int i=0;i<=n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=false;
            p[i][j]={-1,10};
        }
	}
	dp[0][0]=true;
	//int dp[n][m];
	int e=1;
	for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dp[i][j]){
                   // cout<<i<<" "<<j<<" "<<p[i][j].first<<" "<<p[i][j].second<<"\n";
                if(s[n-1-i]=='?'){
                    for(int k=9;k>=((i==n-1)?1:0);k--){
                        dp[i+1][(j+e*k)%m]=true;
                        if(p[i+1][(j+e*k)%m].second>k){
                            p[i+1][(j+e*k)%m]={j,k};
                        }
                    }
                }else{
                    int k=s[n-1-i]-'0';
                    dp[i+1][(j+e*k)%m]=true;
                    if(p[i+1][(j+e*k)%m].second>k){
                            p[i+1][(j+e*k)%m]={j,k};
                    }
                }
            }
        }
        e=(e*10)%m;
	}
	if(dp[n][0]){
        int i=n,j=0;
        while(i!=0){
            auto pr=p[i][j];
            i--;
            j=pr.first;
            s[n-i-1]='0'+pr.second;
        }
        cout<<s<<"\n";
	}else cout<<"*\n";
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
