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
        ll n,m;
        cin>>n>>m;
        if(n==1 && m>1){
            if(m==2) cout<<"1\n";
            if(m>2) cout<<"-1\n";
            continue;
        }
        if(m==1 && n>1){
            if(n==2) cout<<"1\n";
            if(n>2) cout<<"-1\n";
            continue;
        }
        if(n>m) swap(n,m);
        if((m-n)&1){
            cout<<2*(n-1)+((m-n)/2)*4+1<<"\n";
        }else{
            cout<<2*(n-1)+((m-n)/2)*4<<"\n";
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
