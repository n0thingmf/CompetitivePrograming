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
	vector<string> s(n);
	for(int i=0;i<n;i++) cin>>s[i];
	int ans=0;
	for(char u='a';u<='z';u++){
        for(char v=u+1;v<='z';v++){
            int res=0;
            for(int i=0;i<n;i++){
                bool ok=true;
                for(char c:s[i]){
                    if(c!=u && c!=v){
                        ok=false;
                        break;
                    }
                }
                if(ok) res+=s[i].size();
            }
            ans=max(ans,res);
        }
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
