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
	string s;
	cin>>s;
	ll n,m=s.size();
	cin>>n;
	ll base=0;
	for(int i=0;i<m;i++){
        if(s[i]=='1') base+=1ll<<(m-1-i);
	}
	n-=base;
	if(n<0){
        cout<<"-1";
	}else{
	    ll now=0;
        for(int i=0;i<m;i++){
            if(s[i]=='?'){
                if((now|(1ll<<(m-1-i)))<=n) now|=(1ll<<(m-1-i));
            }
        }
        cout<<now+base<<"\n";
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
