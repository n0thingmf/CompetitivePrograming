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
	/*ios::sync_with_stdio(false);
	cin.tie(0);*/
	int n,k;
	cin>>n>>k;
	map<vector<int>,int> m;
	for(int i=0;i<n;i++){
        vector<int> c(k);
        for(int j=0;j<k;j++) cin>>c[j];
        m[c]=i;
	}
	vector<int> dp(n,0);
	for(auto it=m.begin();it!=m.end();it++){
        for(auto it2=m.begin();it2!=it;it2++){
            vector<int> u=it->first;
            vector<int> v=it2->first;
            vector<int> w(k);
            for(int i=0;i<k;i++){
                if(u[i]==v[i]) w[i]=u[i];
                else w[i]=3-u[i]-v[i];
            }
            if(m.count(w)){
                dp[m[w]]++;
            }
        }
	}
	int ans=0;
	for(int i=0;i<n;i++) ans+=(dp[i]*(dp[i]-1))/2;
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
