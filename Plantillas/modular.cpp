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
const ll mod = 1e9 + 7; // change to something else
class modint {
public:
	ll x;
	modint(){
        x=0;
    }
	modint(ll xx){
        x=xx%mod;
	}
	modint operator=(modint b) {
        x=b.x;
        return *this;
	}
	modint operator+(modint b) const{ return modint((x + b.x) % mod); }
	modint operator-(modint b) const{ return modint((x - b.x + mod) % mod); }
	modint operator*(modint b) const{ return modint((x * b.x) % mod); }
	modint operator/(modint b) { return (*this) * inv(b); }
	static modint inv(modint a) {
	    if(a.x<=1) return a;
	    return inv(modint(mod%a.x))*modint(mod-mod/a.x);
	}
	modint operator^(ll e) {
		if (!e) return modint(1);
		modint r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	modint p(7);
	modint q(6);
	p=p/q;
	cout<<p.x<<"\n";;
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
