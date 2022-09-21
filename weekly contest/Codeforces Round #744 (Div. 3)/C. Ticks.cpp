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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<bool>> tab(n,vector<bool>(m));
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='*') tab[i][j]=true;
                else tab[i][j]=false;
            }
        }
        vector<vector<int>> maxd(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(tab[i][j]){
                   // cout<<i<<" "<<j<<"aea\n";
                    int d=0;
                    while(tab[i-d][j-d] && tab[i-d][j+d]){
                        d++;
                        if(i-d<0 || j-d<0 || j+d>=m) break;
                    }
                    maxd[i][j]=d-1;
                }
            }
        }
        vector<vector<bool>> tab2(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(tab[i][j] && maxd[i][j]>=k){
                   // cout<<i<<" "<<j<<" "<<maxd[i][j]<<"\n";
                    tab2[i][j]=true;
                    for(int d=1;d<=maxd[i][j];d++){
                        tab2[i-d][j-d]=tab2[i-d][j+d]=true;
                    }
                }
            }
        }
        bool ok=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(tab[i][j]!=tab2[i][j]) ok=false;
            }
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
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
