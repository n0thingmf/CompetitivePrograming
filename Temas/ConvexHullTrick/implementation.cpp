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
#define point complex<ll>
#define x real
#define y imag

using namespace std;

ll dot(point a, point b) {
    return (conj(a) * b).x();
}

ll cross(point a, point b) {
    return (conj(a) * b).y();
}

vector<point> hull,vecs;

void add_line(ll k,ll b){
    point nw = {k,b};
    while(!vecs.empty() && dot(vecs.back(), nw - hull.back()) < 0) {
        hull.popb();
        vecs.popb();
    }
    if(!hull.empty()) {
        vecs.pb(complex<ll>(0,1) * (nw - hull.back()));
    }
    hull.pb(nw);
}

int get(ll x) {
    point query = {x, 1};
    auto it = lower_bound(all(vecs), query, [](point a, point b) {
        return cross(a, b) > 0;
    });
    return dot(query, hull[it - vecs.begin()]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int s,c,r;
        cin>>s>>c;
        vector<int> r(s+1);
        vector<int> x(s+1);
        cin>>r[0];
        x[0]=0;
        vector<pair<int,int>> os(s+1);
        for(int i=1;i<=s;i++) cin>>x[i]>>r[i],os[i]={};

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
