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

bool c[26];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(c,false,sizeof(c));
	int n,k,lst=-1;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<k;i++){
        char x;
        cin>>x;
        c[x-'a']=true;
	}
    vector<ll> dp(n,0);
    if(c[s[0]-'a']) dp[0]=1;
    else dp[0]=0,lst=0;
    for(int i=1;i<n;i++){
        if(c[s[i]-'a']) dp[i]=dp[i-1]+i-lst;
        else dp[i]=dp[i-1],lst=i;
    }
    cout<<dp[n-1]<<"\n";
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
