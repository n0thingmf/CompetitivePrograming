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
    point rotate(long double angle)//Rotar un ángulo angle en sentido contrario a las agujas del reloj alrededor del punto p
    {
        long double c=cosl(angle),s=sinl(angle);
        return point(x*c-y*s,x*s+y*c);
    }
    long double angle(point p){
    	complex<long double> v1(x,y),v2(p.x,p.y);
    	long double delta=arg(v2)-arg(v1);
    	if(dblcmp(delta)>=0) return delta;
    	else return delta+2*pi;
    }
};

long double closestDist(vector<point> &p,vector<point> &q,int l,int r){
    if(r-l==1){
        if(dblcmp(p[r].y-p[l].y)>=0) q.pb(p[l]),q.pb(p[r]);
        else q.pb(p[r]),q.pb(p[l]);
        return p[l].distance(p[r]);
    }
    if(l==r){
        q.pb(p[l]);
        return inf;
    }
    int m=(l+r)/2;
    vector<point> q1,q2;
    long double d=min(closestDist(p,q1,l,m),closestDist(p,q2,m+1,r));
    int i=0,j=0;
    while(i<q1.size() && j<q2.size()){
        if(q1[i].y<q2[j].y) q.pb(q1[i++]);
        else q.pb(q2[j++]);
    }
    while(i<q1.size()) q.pb(q1[i++]);
    while(j<q2.size()) q.pb(q2[j++]);
    vector<point> L,R;
    for(point p1:q1) if(p[m].x-d<=p1.x) L.pb(p1);
    for(point p2:q2) if(p2.x<=p[m].x+d) R.pb(p2);
    i=0,j=0;
    for(int k=0;k<L.size();k++){
        while(i<R.size() && R[i].y<L[k].y-d) i++;
        while(j<R.size() && R[j].y<=L[k].y+d) j++;
        for(int z=i;z<j;z++) d=min(d,L[k].distance(R[z]));
    }
    return d;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(6) << fixed;
	int n;
	cin>>n;
	vector<point> p(n);
	for(int i=0;i<n;i++){
        double x,y;
        cin>>x>>y;
        p[i]=point(x,y);
	}
	sort(all(p));
	vector<point> q;
	cout<<closestDist(p,q,0,n-1)<<"\n";
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
