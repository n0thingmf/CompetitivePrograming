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
	vector<pair<int,int>> fact;
	for(int i=2;i*i<=n;i++){
        if(n%i==0){// i es primo?
            //cada i que pasa por aqui es primo
            int e=0;
            while(n%i==0){
                e++;
                n/=i;
            }
            fact.pb({i,e});
        }
	}
	if(n>1){
        fact.pb({n,1});
	}
	int e=1,loge=0,ans=1;
	for(auto f:fact){
        ans*=f.first;
        while(e<f.second) e*=2,loge++;
	}
	bool ok=true;
	for(auto f:fact){
        if(e!=f.second) ok=false;
	}
	if(ok) cout<<ans<<" "<<loge<<"\n";
    else cout<<ans<<" "<<loge+1<<"\n";
    x^y
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
