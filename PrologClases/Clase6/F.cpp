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

ll fpow(ll a,ll b,ll mod){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll inv(ll a,ll mod){
    return fpow(a,mod-2,mod);
}
ll bezout(ll a,ll b,ll &x,ll &y){//a*x+b*y=g, retorna g, misma complejidad que el gcd
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll x2,y2;
    ll g=bezout(b,a%b,x2,y2);
    x=y2;
    y=x2-(a/b)*y2;
    return g;
}

ll CRT(ll a1,ll b1,ll a2,ll b2){
    ll x,y;
    ll g=bezout(b1,b2,x,y);
    if((a2-a1)%g!=0) cout<<"No hay solucion\n";
    else{
        ll r=a1+x*(b1/g)*(a2-a1);
        r%=(b1*b2/g);//b1*b2/g = minimo comun multiplo
        if(r<0) r+=b1*b2/g;
        return r;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a,b,p,x;
	cin>>a>>b>>p>>x;
	ll ans=0;
	for(ll i=0;i<p-1;i++){
        ll c=(inv(fpow(a,i,p),p)*b)%p;
        ll d=CRT(i,p-1,c,p);
        if(x>=d) ans+=(x-d)/(p*(p-1))+1;
	}
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
