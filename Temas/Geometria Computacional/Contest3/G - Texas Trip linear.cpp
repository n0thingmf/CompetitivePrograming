#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<complex>
#define mp make_pair
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
const long double eps=1e-9L;
const long double pi=acos(-1.0);
const long double inf=1e20;
const int maxp=1111;
int dblcmp(long double d)
{
    if (fabs(d)<eps)return 0;
    return d>eps?1:-1;
}
inline long double sqr(long double x){return x*x;}
struct point
{
    long double x,y;
    point(){}
    point(long double _x,long double _y):
    x(_x),y(_y){};
    bool operator==(point a)const
    {
        return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
    }
    bool operator<(point a)const
    {
        return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
    }
    long double len()
    {
        return hypot(x,y);
    }
    long double len2()
    {
        return x*x+y*y;
    }
    long double distance(point p)
    {
        return hypot(x-p.x,y-p.y);
    }
    point add(point p)
    {
        return point(x+p.x,y+p.y);
    }
    point sub(point p)
    {
        return point(x-p.x,y-p.y);
    }
    point mul(long double b)
    {
        return point(x*b,y*b);
    }
    point div(long double b)
    {
        return point(x/b,y/b);
    }
    long double dot(point p)
    {
        return x*p.x+y*p.y;
    }
    long double det(point p)
    {
        return x*p.y-y*p.x;
    }
    long double rad(point a,point b)
    {
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    point trunc(long double r)
    {
        long double l=len();
        if (!dblcmp(l))return *this;
        r/=l;
        return point(x*r,y*r);
    }
    point rotleft()
    {
        return point(-y,x);
    }
    point rotright()
    {
        return point(y,-x);
    }
    point rotate(point p,long double angle)//Rotar un ángulo angle en sentido contrario a las agujas del reloj alrededor del punto p
    {
        point v=this->sub(p);
        long double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
    long double angle(point p){
    	complex<long double> v1(x,y),v2(p.x,p.y);
    	long double delta=arg(v2)-arg(v1);
    	if(dblcmp(delta)>=0) return delta;
    	else return delta+2*pi;
    }
};

bool ccw(point a,point b){
	if(a.det(b)==0){
		return a.len()<b.len();
	}else{
		return a.det(b)>0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(2) << fixed;
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<point> pol(n);
        for(int i=0;i<n;i++){
            long double x,y;
            cin>>x>>y;
            pol[i]=point(x,y);
        }
        long double delta=pi/1000000;
        point origin(0,0);
        long double ans=inf;
        for(long double ang=0;ang<pi;ang+=delta){
            long double xl=inf,xr=-inf,yl=inf,yr=-inf;
            for(int i=0;i<n;i++){
                point pt=pol[i].rotate(origin,ang);
                xl=min(xl,pt.x);
                xr=max(xr,pt.x);
                yl=min(yl,pt.y);
                yr=max(yr,pt.y);
            }
            ans=min(ans,max(xr-xl,yr-yl));
        }
        cout<<ans*ans<<"\n";
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
