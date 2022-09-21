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
#define x first
#define y second
#define pt pair<ll,ll>
using namespace std;
const double phi=acos(-1);
const double err=1e-8;
double angle(pt a,pt b,pt c){
   pt u={a.x-b.x,a.y-b.y};
   pt v={c.x-b.x,c.y-b.y};
   return acos((double)(u.x*v.x+u.y*v.y)/(hypot(u.x,u.y)*hypot(v.x,v.y)));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << setprecision(12) << fixed;
	ll n;
	cin>>n;
	vector<pt> p(n);
	for(ll i=0;i<n;i++) cin>>p[i].x>>p[i].y;
	/*vector<double> ang(n);
	ang[0]=0;
	for(ll i=1;i<n;i++){
        ang[i]=ang[i-1]+phi-angle(p[i-1],p[i],p[(i+1)%n]);
	}*/

	ll all=(n*(n-1)*(n-2))/6,wrong=0;
	/*for(ll i=0;i<n;i++){
        double limit=ang[i]+phi+err;
        if(limit>=2*phi){
            limit-=2*phi;
            ll j=upper_bound(all(ang),limit)-ang.begin();
            j--;
            if(n+j-i>=2) wrong+=((n+j-i)*(n+j-i-1))/2;
        }else{
            ll j=upper_bound(all(ang),limit)-ang.begin();
            j--;
            if(j-i>=2) wrong+=((j-i)*(j-i-1))/2;
        }
	}*/
	for(ll i=0,j=1;i<n;i++){
        pt u={p[i].x-p[(i+1)%n].x,p[i].y-p[(i+1)%n].y};

        pt v={p[(j+1)%n].x-p[(j)%n].x,p[(j+1)%n].y-p[(j)%n].y};
        while(v.x*u.y-u.x*v.y>=0){
            j++;
            v={p[(j+1)%n].x-p[(j)%n].x,p[(j+1)%n].y-p[(j)%n].y};
        }
        wrong+=((j-i-1)*(j-i-2))/2;
	}


	cout<<all-wrong<<"\n";
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
