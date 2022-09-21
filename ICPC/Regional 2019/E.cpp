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

ll f(ll x){return (x*(x+1))/2;}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,s;
	string cake;
	cin>>cake;
	n=cake.size();
	cin>>s;
    ll total=n*s;
    ll cnt=0;
    vector<ll> parts;
    if(cake[0]=='E') parts.pb(0);
    bool ok=false;
    for(int i=0;i<n;i++){
        if(cake[i]=='E'){
            if(cnt!=0) parts.pb(cnt);
            cnt=0;
            ok=true;
        }else{
            cnt++;
        }
    }
    if(!ok){
        cout<<"0\n";
        return 0;
    }
    if(cnt!=0){
        if(parts.empty()) parts.pb(cnt);
        else parts[0]+=cnt;
    }
    for(ll p:parts){
        total-=f(p)-f(max(0ll,p-s));
    }
    cout<<total<<"\n";
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
