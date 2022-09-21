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
        int l,r;
        cin>>l>>r;
        vector<int> n0(17,0),n1(17,0);
        for(int i=0;i<=r;i++){
            for(int j=0;j<17;j++){
                if(i&(1<<j)) n1[j]++;
                else n0[j]++;
            }
        }
        vector<int> m0(17,0),m1(17,0);
        for(int i=0;i<=r;i++){
            int s;
            cin>>s;
            for(int j=0;j<17;j++){
                if(s&(1<<j)) m1[j]++;
                else m0[j]++;
            }
        }
        int ans=0;
        for(int i=0;i<17;i++){
            if(n0[i]>n1[i]){
                if(m1[i]>m0[i]) ans|=(1<<i);
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
