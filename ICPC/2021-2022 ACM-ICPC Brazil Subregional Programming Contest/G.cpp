#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back
#define f first
#define s second
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
//#define dbg(x) do {} while (false)
#define raya do {cerr << "===========================" << endl; } while (false)
//#define raya do {} while (false)
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> ii;
const ll maxn = 100;
const ll inf = 1e15;
ll fib[maxn];
int cnt[maxn];
vector<pair<ll,int>>fb;

unordered_map<ll, bool> mposs;
unordered_map<ll, bool> vis;
unordered_map<ll, pair<ll,int>> nxt;

bool poss(ll n) {
    if(n == 1) return true;
    if(vis[n]) return mposs[n];

    vis[n] = true;
    mposs[n] = false;
    for(pair<ll,int> e : fb) {
        ll x = e.first;
        if(n % x == 0) {
            if(poss(n/x)) {
                mposs[n] = true;
                nxt[n] = e;
                break;
            }
        }
    }

    return mposs[n];
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	memset(cnt,0,sizeof(cnt));
	fib[0] = 2 , fib[1] = 3;
	fb.pb({2,1});fb.pb({3,2});
	for(int i=2;i<maxn;i++){
		fib[i] = fib[i-1] + fib[i-2] ;
		if(fib[i]>inf)break;
		fb.pb({fib[i],i+1});
	}
	ll n;
	cin>>n;
	reverse(all(fb));

    if(!poss(n)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    while(n != 1) {
        for(int i=0;i<nxt[n].second;i++) cout<<"A";
        cout<<"B";
        n/=nxt[n].first;
    }

    return 0;
}
