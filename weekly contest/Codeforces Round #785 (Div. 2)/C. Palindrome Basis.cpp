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

const ll mod=1e9+7;
const ll maxn=4e4;
vector<int> palin;
ll dp[maxn+1][500];
void init(){
    for(int i=1;i<=9;i++){
        palin.pb(i);
        palin.pb(i*11);
    }
    for(int i=1;i<10;i++){
        for(int j=0;j<10;j++){
            palin.pb(101*i+10*j);
            palin.pb(1001*i+110*j);
        }
    }

    for(int i=1;i<4;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++) palin.pb(10001*i+1010*j+100*k);
        }
    }
    sort(all(palin));
    for(int i=0;i<palin.size();i++) dp[0][i]=1;
    //dp[0][0]=1;
    for(int i=1;i<=maxn;i++){
        for(int j=0;j<palin.size();j++){
            if(i>=palin[j]){
                if(j>=1) dp[i][j]=(dp[i-palin[j]][j]+dp[i][j-1])%mod;
                else dp[i][j]=dp[i-palin[j]][j];
            }
            else dp[i][j]=dp[i][j-1];
           /* for(int k=j;k<palin.size();k++){
                if(i+palin[k]<=maxn) dp[i+palin[k]][k]=(dp[i+palin[k]][k]+dp[i][j])%mod;
                else break;
            }*/
        }

    }

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t;
	//cout<<palin.size()<<"\n";
	//for(int x:palin) cout<<x<<"\n";
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        ll ans=0;
        //for(int j=0;j<palin.size();j++) ans=(ans+dp[n][j])%mod;
        cout<<dp[n][palin.size()-1]<<"\n";
        //cout<<ans<<"\n";
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
