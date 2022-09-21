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

int solve(string s){
    int n=s.size();
    vector<int> z(n,0);
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(r>=i) z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[i+z[i]]==s[z[i]]) z[i]++;
        if(i+z[i]-1>r){
            r=i+z[i]-1;
            l=i;
        }
    }
    int j;
    for(j=1;j<n;j++){
        if(n%j==0 && z[j]==n-j){
            break;
        }
    }
    return j;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        string s;
        cin>>s;
        cout<<solve(s)<<"\n";
        if(t) cout<<"\n";
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
