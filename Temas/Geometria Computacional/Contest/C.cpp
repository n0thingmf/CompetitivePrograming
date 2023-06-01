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
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;

typedef complex<double> P;
typedef vector<P> L;
const double eps = 1e-8;

double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;
	int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	vector<L> line(n);
    	vector<P> pnts;
    	for(int i=0;i<n;i++){
    	    double x0,y0,x1,y1;
    	    cin>>x0>>y0>>x1>>y1;
    	    line[i].pb(P(x0,y0));
    	    line[i].pb(P(x1,y1));
    	    pnts.pb(P(x0,y0));
    	    pnts.pb(P(x1,y1));
    	}
    	bool ok=false;
    	for(int i=0;i<pnts.size() && !ok;i++){
    	    for(int j=i+1;j<pnts.size() && !ok;j++){
    	        if(abs(pnts[i]-pnts[j])<eps) continue;
    	        P rect=pnts[j]-pnts[i];
    	        bool kek=true;
    	        for(int k=0;k<n;k++){
                    if(cross(rect,line[k][0]-pnts[i])*cross(rect,line[k][1]-pnts[i])>0){
                        kek=false;
                        break;
                    }
    	        }
    	        if(kek) ok=true;
    	    }
    	}
    	if(ok) cout<<"Yes!\n";
    	else cout<<"No!\n";

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
