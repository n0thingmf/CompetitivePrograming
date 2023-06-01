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
    int h,w;
    cin>>h>>w;
    vector<string> s(w,string(h,' ')),t(w,string(h,' '));
    for(int i=0;i<h;i++){
        string x;
        cin>>x;
        for(int j=0;j<w;j++){
            s[j][i]=x[j];
        }
    }
    for(int i=0;i<h;i++){
        string x;
        cin>>x;
        for(int j=0;j<w;j++){
            t[j][i]=x[j];
        }
    }
    sort(all(s));
    sort(all(t));
    if(s==t) cout<<"Yes\n";
    else cout<<"No\n";
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
