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
const int maxn=80;
int dp[maxn][maxn];
int phi[maxn][maxn];
string s;
void init(){
    int n=s.size();
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=-1;
    for(int i=0;i<n;i++){
        phi[i][0]=0;
        for(int j=1;i+j<n;j++){
            int k=phi[i][j-1];
            while(k>0 && s[i+k]!=s[i+j]) k=phi[i][k-1];
            k+=s[i+k]==s[i+j];
            phi[i][j]=k;
        }
    }
}
int solve(int i,int j){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==j){
        dp[i][j]=1;
        return 1;
    }
    dp[i][j]=j-i+1;
    for(int k=i+1;k<=j;k++) dp[i][j]=min(dp[i][j],solve(i,k-1)+solve(k,j));
    if(phi[i][j-i]>0 && (j-i+1)%(j-i+1-phi[i][j-i])==0) dp[i][j]=min(dp[i][j],solve(i,i+phi[i][j-i]-1));
    return dp[i][j];
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	while(cin>>s){
        if(s.size()==1 && s[0]=='*') break;
        init();
        cout<<solve(0,s.size()-1)<<"\n";
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
