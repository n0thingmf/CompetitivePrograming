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
        int n;
        cin>>n;
        vector<pair<int,int>> fact;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                int e=0;
                while(n%i==0){
                    n/=i;
                    e++;
                }
                fact.pb({e,i});
            }
        }
        if(n>1) fact.pb({1,n});
        sort(all(fact));
        int prod=1;
        for(auto p:fact) prod*=p.second;
        int last=0;
        ll ans=0;
        for(auto p:fact){
            if(p.first>last) ans+=prod*(p.first-last),last=p.first;
            prod/=p.second;
        }
        cout<<ans<<"\n";
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
