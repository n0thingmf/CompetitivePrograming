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

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	vector<int> div;
	for(int i=1;i<n;i++){
        if(n%i==0) div.pb(i);
	}
	map<int,bool> ans;
	for(int p:div) ans[p]=false;
	for(int p:div){
        for(int i=0;i<p;i++){
            bool ok=true;
            int j=i;
            while(j<n){
                if(s[j]=='P'){
                    ok=false;
                    break;
                }
                j+=p;
            }
            if(ok) ans[p]=true;
        }
	}
	int res=0;
	for(int k=1;k<n;k++){
        if(ans[gcd(k,n)]) res++;
	}
	cout<<res<<"\n";
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
