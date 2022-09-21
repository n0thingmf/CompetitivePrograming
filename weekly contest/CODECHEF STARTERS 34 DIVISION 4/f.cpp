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
        int n,k,ones=0,two=0;
        cin>>n>>k;
        string s;
        cin>>s;
        bool ok=true;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ones++,ok=!ok;
            else if(ok) two++;
        }

        if(ones&1){
            if(k%2==1 && k<=ones) cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            if(k%2==0 && k<=ones) cout<<"YES\n";
            else{
                if(k<=ones/2+two) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
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
