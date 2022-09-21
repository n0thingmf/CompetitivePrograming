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
        int n,x;
        cin>>n>>x;
        if(n&1){
            for(int i=-(n/2);i<=n/2;i++){
                cout<<i+x<<" ";
            }
            cout<<"\n";
        }else{
            for(int i=0;i<n/2;i++){
                cout<<x+i-n/2<<" ";
            }
            for(int i=0;i<n/2;i++){
                cout<<x+i+1<<" ";
            }
            cout<<"\n";
        }
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
