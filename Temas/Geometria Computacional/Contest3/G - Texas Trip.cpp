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
        vector<point> p(n);
        int io=0;
        for(int i=0;i<n;i++){
            long double x,y;
            cin>>x>>y;
            p[i]=point(x,y);
            if(p[i]<p[io]) io=i;
        }
        vector<point> a;
        for(int i=0;i<n;i++){
            if(i==io) continue;
            a.pb(p[i].sub(p[io]));
        }
        sort(all(a),ccw);
        vector<point> ch;
        ch.pb(point(0,0));
        ch.pb(a[0]);
        //radial convex hull
        for(int i=1;i<n-1;i++){
            while(ch.size()>1 && !ccw(ch.back().sub(ch[ch.size()-2]),a[i].sub(ch.back()))){
                ch.pop_back();
            }
            ch.pb(a[i]);
        }
        p=ch;
        n=ch.size();
		//cout<<n<<" ch size\n";
        int v[4]={0}; //puntos de soporte
        point e[4]; //vectores de soporte
        e[0]=p[0].sub(p[n-1]);
        e[1]=e[0].rotate(pi/2);
        e[2]=e[0].rotate(pi);
        e[3]=e[0].rotate(3*pi/2);
        long double ang[4];
        for(int i=1;i<4;i++){
            while(dblcmp(e[0].angle(p[(v[i]+1)%n].sub(p[v[i]]))-pi*i/2)==-1 || dblcmp(e[0].angle(p[(v[i]+1)%n].sub(p[v[i]])))==0) v[i]++;// v[i]<n
        }
        for(int i=0;i<4;i++) ang[i]=e[i].angle(p[(v[i]+1)%n].sub(p[v[i]]));
        long double ans=inf;
        bool run=true;
        while(run){
            /*cout<<"points of support\n";
            for(int i=0;i<4;i++) cout<<v[i]<<" ";
            cout<<"\n";
            for(int i=0;i<4;i++) cout<<ang[i]<<" ";
            cout<<"\n";*/
            long double minangle=inf;
            for(int i=0;i<4;i++) minangle=min(minangle,ang[i]);
            point diag1=p[v[2]].sub(p[v[0]]);
            point diag2=p[v[1]].sub(p[v[3]]);
            long double l1=diag1.len(),l2=diag2.len();

            long double theta1=e[0].angle(diag1),theta2=e[3].angle(diag2);
            long double L=0,R=minangle;
            //cout<<l1<<" "<<theta1<<"\n";
            //cout<<l2<<" "<<theta2<<"\n";
            // binary or ternary search on max(diag1*sin(theta1-M),diag2*sin(theta2-M))
            int niterations=50;
            while(niterations--){
                long double M1=(L*2+R)/3,M2=(L+R*2)/3;
                if(max(l1*sinl(theta1-M1),l2*sinl(theta2-M1))<max(l1*sinl(theta1-M2),l2*sinl(theta2-M2))){
                    R=M2;
                }else{
                    L=M1;
                }
            }
            ans=min(ans,max(l1*sinl(theta1-L),l2*sinl(theta2-L)));
            //cout<<ans<<" temp answer\n";
            //update rotating calipers
            for(int i=0;i<4;i++){
                if(dblcmp(minangle-ang[i])==0){
                    if(i==0 && v[i]==n-1) run=false;
                    v[i]=(v[i]+1)%n;
                }
            }
            for(int i=0;i<4;i++){
                e[i]=e[i].rotate(minangle);
            }
            for(int i=0;i<4;i++) ang[i]=e[i].angle(p[(v[i]+1)%n].sub(p[v[i]]));
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
