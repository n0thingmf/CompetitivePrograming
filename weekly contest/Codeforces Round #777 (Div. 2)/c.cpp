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
int n,m;
int tab[100][100];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        cin>>n>>m;
        int ans=0;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='1') tab[i][j]=1,ans++;
                else tab[i][j]=0;
            }
        }
        if(tab[0][0]) cout<<"-1\n";
        else{
            cout<<ans<<"\n";
            for(int j=m-1;j>0;j--){
                for(int i=n-1;i>=0;i--){
                    if(tab[i][j]) cout<<i+1<<" "<<j<<" "<<i+1<<" "<<j+1<<"\n";
                }
            }
            for(int i=n-1;i>0;i--){
                if(tab[i][0]) cout<<i<<" "<<1<<" "<<i+1<<" "<<1<<"\n";
            }
        }

	}
	//cout << setprecision(12) << fixed;
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
