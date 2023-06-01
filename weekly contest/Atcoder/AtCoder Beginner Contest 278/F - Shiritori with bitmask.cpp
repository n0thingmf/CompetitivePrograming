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

int dp[1<<16];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            int first=s[i][0]-'a',last=s[i].back()-'a';
            if((mask>>i)&1){
                dp[mask]|=(((~dp[mask^(1<<i)])>>first)&1)<<last;
            }
        }
    }
    //cout<<bitset<26>(dp[(1<<n)-1])<<"\n";
    bool ok=false;
    for(int i=0;i<26;i++) if((dp[(1<<n)-1]>>i)&1) ok=true;
    if(ok) cout<<"First\n";
    else cout<<"Second\n";
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
