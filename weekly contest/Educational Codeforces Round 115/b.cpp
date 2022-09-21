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
        int n,ans=(1<<5)-1;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(5));
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>a[i][j];
            }
        }
        bool ok=false;
        for(int i=0;i<5;i++){
            for(int j=i+1;j<5;j++){
                int x=0,y=0,z=0;
                for(int k=0;k<n;k++){
                    if(a[k][i]==1 && a[k][j]==1) y++;
                    else if(a[k][i]==1) x++;
                    else if(a[k][j]==1) z++;
                }
                if(x+y+z==n && x<=n/2 && z<=n/2) ok=true;
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
