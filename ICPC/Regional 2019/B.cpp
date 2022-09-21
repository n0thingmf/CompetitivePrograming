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

const double phi=acos(-1);
const int iter=1e3;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;
	int n;
	cin>>n;
	vector<pair<int,int>> p(n);
	for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
	double delta=phi/(2*iter);
	double ans=0;
	for(int i=0;i<n;i++){
        double ang=atan(abs(double(p[i].second)/p[i].first));
        double r=1e10;
        for(int i=0;i<n;i++){
            double x,y;
            x=cos(ang)*p[i].first-sin(ang)*p[i].second;
            y=sin(ang)*p[i].first+cos(ang)*p[i].second;
            r=min(r,max(abs(x),abs(y)));
        }
        ans=max(ans,8*r);
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
