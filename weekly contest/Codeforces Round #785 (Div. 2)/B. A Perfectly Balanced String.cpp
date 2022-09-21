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
        string s;
        cin>>s;
        vector<int> f(26,0);
        for(int i=0;i<s.size();i++) f[s[i]-'a']++;
        int cnt=0;
        for(int i=0;i<26;i++) if(f[i]) cnt++;
        f.assign(26,0);
        for(int i=0;i<cnt;i++) f[s[i]-'a']++;
        int dcnt=0;
        for(int i=0;i<26;i++) if(f[i]) dcnt++;
        bool ok=true;
        if(dcnt!=cnt) ok=false;
        for(int i=cnt;i<s.size();i++){
            if(s[i]!=s[i-cnt]) ok=false;
        }
        if(ok) cout<<"yes\n";
        else cout<<"no\n";
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
