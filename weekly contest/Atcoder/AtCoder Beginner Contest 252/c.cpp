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
	int n;
	cin>>n;
	vector<vector<int>> pos(n,vector<int>(10));
	for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++) pos[i][s[j]-'0']=j;
	}
	int ans=INT_MAX;
	for(int x=0;x<10;x++){
        vector<int> a(10,0);
        for(int i=0;i<n;i++) a[pos[i][x]]++;
        int res=0;
        for(int i=0;i<10;i++){
            if(a[i]) res=max(res,(a[i]-1)*10+i);
        }
        ans=min(res,ans);
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
