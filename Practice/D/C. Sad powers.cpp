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
const ll maxv=1e18;
set<ll> mgood;
vector<ll> good;
bool issqr(ll x){
    ll y=(long long)sqrtl(x);
    if(y*y==x) return true;
    return false;
}
ll sqr(ll x){
    ll y=(long long)sqrtl(x);
    return y;
}
void init(){
    for(ll a=2;a<=1e6;a++){
        ll e=a*a*a;
        for(ll b=3;;b++){
            mgood.insert(e);
            if(e>maxv/a){
                break;
            }else{
                e*=a;
            }
        }
    }
    for(ll x:mgood){
        if(!issqr(x)) good.pb(x);
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    init();
    //cout<<good.size()<<" "<<*good.begin()<<"\n";
    int q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        /*auto it1=good.lower_bound(l);
        auto it2=good.upper_bound(r);*/
        ll ans=upper_bound(all(good),r)-lower_bound(all(good),l);
        //ans=distance(it1,it2);
        //cout<<"data :"<<sqr(r)<<" "<<sqr(l-1)<<"\n";
        ans+=sqr(r)-sqr(l-1);
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
