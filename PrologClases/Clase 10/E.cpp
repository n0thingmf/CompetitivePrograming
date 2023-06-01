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

vector<string> build(int n){
    if(n==1) return vector<string>(1,"H-H");
    vector<string> small=build(n-1);
    vector<string> up=small;
    vector<string> down=small;
    for(int i=small.size()/2+1;i<small.size();i++) up[i][small[0].size()/2]='|';
    for(int i=0;i<small.size()/2;i++) down[i][small[0].size()/2]='|';

    vector<string> big;

    for(int i=0;i<small.size();i++){
        string line;
        line+=up[i];
        line+=" ";
        line+=up[i];
        big.pb(line);
    }

    string midline;
    int w=small[0].size();
    midline+=string(w/2,' ');
    midline+="|";
    midline+=string(w,'-');
    midline+="|";
    midline+=string(w/2,' ');
    big.pb(midline);

    for(int i=0;i<small.size();i++){
        string line;
        line+=down[i];
        line+=" ";
        line+=down[i];
        big.pb(line);
    }
    return big;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<string> fractal=build(n);
	for(int i=0;i<fractal.size();i++){
        while(fractal[i].back()==' ') fractal[i].pop_back();
	}
	for(string s:fractal) cout<<s<<"\n";
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
