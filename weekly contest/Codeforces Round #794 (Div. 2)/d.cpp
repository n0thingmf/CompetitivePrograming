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
        int a,b,c,d;
        string s;
        cin>>a>>b>>c>>d;
        int ta=a+c+d,tb=b+c+d;
        cin>>s;
        int n=s.size();
        int u=0,v=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A') u++;
            else v++;
        }
        if(u!=ta || v!=tb){
            cout<<"NO\n";
            continue;
        }
        int k=0;
        int len=0;
        vector<int> ab,ba;
        for(int i=0;i+1<n;i++){
            if(s[i]==s[i+1]){
                k+=len/2;
                if(len>0 && len&1){
                    if(s[i]=='A') ba.pb(len/2+1);
                    else ab.pb(len/2+1);
                }
                len=0;
            }else len++;
        }
        k+=len/2;
        if(len>0 && len&1){
            if(s[n-1]=='A') ba.pb(len/2+1);
            else ab.pb(len/2+1);
        }
        sort(all(ab));
        sort(all(ba));
        for(int i=0;i<ab.size();i++){
            if(c<ab[i]) break;
            c-=ab[i];
            k-=ab[i]-1;
        }
        for(int i=0;i<ba.size();i++){
            if(d<ba[i]) break;
            d-=ba[i];
            k-=ba[i]-1;
        }
        if(c+d<=k) cout<<"YES\n";
        else cout<<"NO\n";
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
