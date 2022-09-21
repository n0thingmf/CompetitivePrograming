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
    int n,m;
    cin>>n>>m;
    vector<int> a(31);
    vector<vector<int>> b(31);
    for(int i=0;i<n;i++){
            int val;
        cin>>val;
        int pow=0;
        while(val>0) a[pow]+=val&1,val/=2,pow++;
    }
    for(int i=0;i<m;i++){
        int val;
        cin>>val;
        b[val].pb(1);
    }
    int ans=0;
    for(int i=0;i<30;i++){
        if(a[i]>=b[i].size()) for(int x:b[i]) ans+=x;
        else{
            for(int j=b[i].size()-1;j>=b[i].size()-a[i];j--) ans+=b[i][j];
            int len=b[i].size()-a[i];
            if(len&1) b[i+1].pb(b[i][0]);
            for(int j=len&1;j<len;j+=2){
                b[i+1].pb(b[i][j]+b[i][j+1]);
            }
        }
    }
    cout<<ans<<"\n";
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
