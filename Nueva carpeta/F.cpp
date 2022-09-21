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
	ll n;
	cin>>n;
	vector<ll> b(n),p(n);
	ll sumb=0,sump=0;
	for(int i=0;i<n;i++){
        cin>>b[i]>>p[i];
        sumb+=b[i];
        sump+=p[i];
	}
	if(n%2==0 && sumb%(n/2)==0 && sump%(n/2)==0){
        ll ga=sumb/(n/2),gb=sump/(n/2);
        map<pair<ll,ll>,int> f;
        bool ok=true;
        for(int i=0;i<n;i++){
            if(f[{ga-b[i],gb-p[i]}]>0) f[{ga-b[i],gb-p[i]}]--;
            else f[{b[i],p[i]}]++;
        }
        for(auto x:f){
            if(x.second!=0){
                ok=false;
                break;
            }
        }
        if(ok) cout<<"possible\n";
        else cout<<"impossible\n";
	}else cout<<"impossible\n";
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
