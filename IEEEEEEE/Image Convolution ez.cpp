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
string grid[500];
string patt[200];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int r,c,a,b;
        cin>>r>>c;
        for(int i=0;i<r;i++) cin>>grid[i];
        cin>>a>>b;
        for(int i=0;i<a;i++) cin>>patt[i];
        int ans=0;
        for(int i=0;i+a-1<r;i++){
            for(int j=0;j+b-1<c;j++){
                bool ok=true;
                for(int row=0;row<a && ok;row++){
                    for(int col=0;col<b && ok;col++){
                        if(patt[row][col]!='?' && patt[row][col]!=grid[i+row][j+col]){
                            ok=false;
                            break;
                        }
                    }
                }
                if(ok) ans++;
            }
        }
        cout<<ans<<"\n";
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
