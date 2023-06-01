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



vector<string> fractal(int n){
    if(n==1){
        return vector<string>(1,"X");
    }
    vector<string> g=fractal(n-1);
    vector<string> gg;
    for(int i=0;i<g.size();i++){
        string line;
        line+=g[i];
        line+=string(g.size(),' ');
        line+=g[i];
        gg.pb(line);
    }
    for(int i=0;i<g.size();i++){
        string line;
        line+=string(g.size(),' ');
        line+=g[i];
        line+=string(g.size(),' ');
        gg.pb(line);
    }
    for(int i=0;i<g.size();i++){
        string line;
        line+=g[i];
        line+=string(g.size(),' ');
        line+=g[i];
        gg.pb(line);
    }
    return gg;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<string> ans=fractal(n);
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<"\n";
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
