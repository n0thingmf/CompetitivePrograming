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

void solve(string &s){
    string rs=s;
    reverse(all(rs));
    string ss=rs+"#"+s;
    int n=s.size();
    vector<int> z(2*n+1,0);
    int l=0,r=0;
    for(int i=1;i<=2*n;i++){
        if(r>=i) z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<=2*n && ss[z[i]]==ss[i+z[i]]) z[i]++;
        if(i+z[i]-1>r){
            r=i+z[i]-1;
            l=i;
        }
    }
    int j;
    for(j=0;j<n;j++){
        if(j+z[j+n+1]==n) break;
    }
    for(int i=j-1;i>=0;i--) s.pb(s[i]);
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	string s;
	while(cin>>s){
        solve(s);
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
