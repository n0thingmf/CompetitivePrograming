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
const double PI = acos(-1);
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
bool intersectSS2(const L &s, const L &t) { // Don't consider the one that touches as a cross
  REP(i, 2) {
    if (ccw(s[0], s[1], t[i]) == 0) {
      int c = ccw(s[0],s[1],t[!i]);
      if (s[0] == t[i]) {
        if (c!=-2&&c) return 0;
      } else if (s[1] == t[i]) {
        if (c!=2&&c) return 0;
      } else if (abs(c)==1) return 0;
    }
  }
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
P reflection(const L &l, const P &p) {
  return p + P(2,0) * (projection(l, p) - p);
}
double distanceLP(const L &l, const P &p) {
  return abs(p - projection(l, p));
}
double distanceLL(const L &l, const L &m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}
double istanceLS(const L &l, const L &s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS(const L &s, const L &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}
double area(const G& g) {
  double A = 0;
  for (int i = 0; i < g.size(); ++i) {
    A += cross(g[i], next(g, i));
  }
  return abs(A/2);
}

G convex_cut(const G& g, const L& l) {
  G Q;
  REP(i, g.size()) {
    P A = curr(g, i), B = next(g, i);
    if (ccw(l[0], l[1], A) != -1) Q.push_back(A);
    if (ccw(l[0], l[1], A)*ccw(l[0], l[1], B) < 0)
      Q.push_back(crosspoint(L(A, B), l));
  }
  return Q;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

// centroid of a uniform polygon
P centroid(const vector<P> &v) {
  double S = 0;
  P res;
  REP(i,v.size()) {
    int j = i+1;
    if (j == v.size()) j = 0;
    double tmp = cross(v[i], v[j]);
    S += tmp;
    res += (v[i] + v[j]) * tmp;
  }
  S /= 2;
  res /= 6*S;
  return res;
}

double manDistanceSP(const L &l, const P &p) {
  double res = INF;
  L xl = L(p, p + P(1,0));
  if (intersectLS(xl, l)){
    P cp = crosspoint(xl, l);
    double d = abs(p-cp);
    res = min(res, d);
  }
  L yl = L(p, p + P(0,1));
  if (intersectLS(yl, l)) {
    P cp = crosspoint(yl, l);
    double d = abs(p-cp);
    res = min(res, d);
  }
  res = min(res, abs(l[0].real()-p.real()) + abs(l[0].imag()-p.imag()));
  res = min(res, abs(l[1].real()-p.real()) + abs(l[1].imag()-p.imag()));
  return res;
}

// point-convex polygon containment relation
bool convex_contain(const G &g, const P &p) { // Assuming counterclockwise rotation
  REP(i,g.size())
    if (ccw(g[i], next(g, i), p) == -1) return 0;
  return 1;
}
// Determination of overlap between convex polygons
bool intersectGG(const G &g1, const G &g2) {
  if (convex_contain(g1, g2[0])) return 1;
  if (convex_contain(g2, g1[0])) return 1;
  REP(i,g1.size()) REP(j,g2.size()) {
    if (intersectSS(L(g1[i], next(g1, i)), L(g2[j], next(g2, j)))) return 1;
  }
  return 0;
}
// Distance between convex polygon and point
double distanceGP(const G &g, const P &p) {
  if (convex_contain(g, p)) return 0;
  double res = INF;
  REP(i, g.size()) {
    res = min(res, distanceSP(L(g[i], next(g, i)), p));
  }
  return res;
}
// vertical bisector
L bisector(const P &a, const P &b) {
  P A = (a+b)*P(0.5,0);
  return L(A, A+(b-a)*P(0, PI/2));
}
// Voronoi region
G voronoi_cell(G g, const vector<P> &v, int s) {
  REP(i, v.size())
    if (i!=s)
      g = convex_cut(g, bisector(v[s], v[i]));
  return g;
}
// angle related
double angle(const P &a, const P &b) {        // Calculate the angle of vector b with respect to vector a[0,2pi)
  double ret = arg(b)-arg(a);
  return (ret>=0) ? ret : ret + 2*PI;
}
double angle2(const P &a, const P &b) { // angle between vector a and vector b
  return min(angle(a,b), angle(b,a));
}
double rtod(double rad) {       // radians → degrees
  return rad*180/PI;
}
double dtor(double deg) {       // degrees to radians
  return deg*PI/180;
}
// vector rotation
P rotate(P p, double ang) {
  return p * P(cos(ang), sin(ang));
}
// rotation of a line around the origin
L rotate(L l, double ang) {
  return L(rotate(l[0], ang),rotate(l[1], ang));
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
            vector<int> newtop;
            for(int xd=0;xd<top.size();xd++){
                int j=top[xd];
                if(!intersectSS(seg[i],seg[j])) newtop.pb(j);
            }
            newtop.pb(i);
            top=newtop;
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