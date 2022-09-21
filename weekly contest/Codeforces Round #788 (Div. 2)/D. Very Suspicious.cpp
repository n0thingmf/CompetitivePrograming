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

const ll maxn=1e9;
vector<ll> lines;
void init(){
    ll now=0,add=2;
    lines.pb(0);
    for(int i=0;now<=maxn;i++){
        lines.pb(now);
        now+=add;
        if(i%3!=1) add+=2;
    }
    //cout<<lines.size()<<"\n";
   // for(int i=0;i<101;i++) cout<<i<<" "<<lines[i]<<"\n";

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        int i=lower_bound(all(lines),n)-lines.begin();
        cout<<i<<"\n";
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
