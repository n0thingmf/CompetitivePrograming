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
        int n,r,b;
        cin>>n>>r>>b;
        int nr=(r)/(b+1),delta=r-(r/(b+1))*(b+1);
        string s;
        for(int i=0;i<b;i++){
            for(int j=0;j<nr;j++){
                s.pb('R');
            }
            if(i<delta) s.pb('R');
            s.pb('B');
        }
        for(int i=0;i<nr;i++) s.pb('R');
        cout<<s<<"\n";
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
