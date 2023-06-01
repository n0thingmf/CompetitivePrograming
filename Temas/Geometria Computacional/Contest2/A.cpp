#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<b?(a=b,1):0)
#define chmin(a,b) (a>b?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
using namespace std;

const int INF = 1<<29;
const double PI = acos(-1.0);
const double EPS = 1e-8;

typedef complex<double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    // if (abs(a-b)<EPS) return 0;
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
  L() {}
};
typedef vector<P> G;
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};

double ccw(P a, P b, P c) {
  b -= a; c -= a;
  return cross(b,c);
}

bool intersectLL(const L &l, const L &m) {
  return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
         abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
}
bool intersectLS(const L &l, const L &s) {
  return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
         cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
}
bool intersectLP(const L &l, const P &p) {
  return abs(cross(l[1]-p, l[0]-p)) < EPS;
}
bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) < 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) < 0;
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cout << setprecision(12) << fixed;
    int n;
    while(cin>>n && n){
        vector<L> seg(n);
        for(int i=0;i<n;i++){
            double x0,y0,x1,y1;
            scanf("%lf%lf%lf%lf",&x0,&y0,&x1,&y1);
            seg[i].pb(P(x0,y0));
            seg[i].pb(P(x1,y1));
        }
        vector<int> top;
        for(int i=0;i<n;i++){
            bool ok=true;
            for(int j=i+1;j<n;j++){
                if(intersectSS(seg[i],seg[j])){
                    ok=false;
                    break;
                }
            }
            if(ok){
                top.pb(i);
            }
        }
        printf("Top sticks: ");
        for(int i=0;i<top.size();i++){
            if(i==top.size()-1){
                printf("%d.\n",top[i]+1);
            }else{
                printf("%d, ",top[i]+1);
            }
        }
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
