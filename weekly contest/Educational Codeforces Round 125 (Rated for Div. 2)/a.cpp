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
	bool issq[5001];
	memset(issq,false,sizeof(issq));
	for(int i=0;i*i<=5000;i++) issq[i*i]=true;
	int t;
	cin>>t;
	while(t--){
        int x,y;
        cin>>x>>y;
        if(x==0 && y==0) cout<<"0\n";
        else if(issq[x*x+y*y]) cout<<"1\n";
        else cout<<"2\n";
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
