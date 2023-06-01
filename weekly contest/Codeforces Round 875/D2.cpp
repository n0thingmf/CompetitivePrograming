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
	cout << setprecision(12) << fixed;
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> p(n);
        for(int i=0;i<n;i++) cin>>p[i].first;
        for(int i=0;i<n;i++) cin>>p[i].second;
        sort(all(p));
        vector<ll> a(n);
        vector<ll> b(n);
        for(int i=0;i<n;i++) a[i]=p[i].first,b[i]=p[i].second;
        int sq=(int)sqrt(2*n);
        vector<unordered_map<ll,ll>> bs(n+1);
        bs[a[0]][b[0]]++;
        ll ans=0;
        for(int i=1;i<n;i++){
            if(a[i]<=sq){
                for(int j=1;j<=a[i];j++){
                    ll val=a[i]*j-b[i];//recuerda que esto puede ser long long
                    if(1<=val && val<=n && bs[j].count(val)>0) ans+=bs[j][val]; //recuerda no acceder a val si no esta
                }
            }else{
                int l=(2+a[i]-1)/a[i],r=2*n/a[i];
                for(int j=l;j<=r;j++){
                    ll val=a[i]*j-b[i];//recuerda que esto puede ser long long
                    if(1<=val && val<=n && bs[j].count(val)>0) ans+=bs[j][val];
                }
            }
            bs[a[i]][b[i]]++; // O(n) memory
        }//nunca te olvides de los limites de tiempo y memoria, no te apresures
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
