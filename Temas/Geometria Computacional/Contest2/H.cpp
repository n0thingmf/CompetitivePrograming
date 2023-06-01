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
const double eps=1e-8;
const double pi=acos(-1.0);
const double inf=1e20;
const int maxp=1111;
int dblcmp(double d)
{
    if (fabs(d)<eps)return 0;
    return d>eps?1:-1;
}
inline double sqr(double x){return x*x;}
struct point
{
    double x,y;
    point(){}
    point(double _x,double _y):
    x(_x),y(_y){};
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    void output()
    {
        printf("%.2f %.2f\n",x,y);
    }
    bool operator==(point a)const
    {
        return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
    }
    bool operator<(point a)const
    {
        return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
    }
    double len()
    {
        return hypot(x,y);
    }
    double len2()
    {
        return x*x+y*y;
    }
    double distance(point p)
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
    point mul(double b)
    {
        return point(x*b,y*b);
    }
    point div(double b)
    {
        return point(x/b,y/b);
    }
    double dot(point p)
    {
        return x*p.x+y*p.y;
    }
    double det(point p)
    {
        return x*p.y-y*p.x;
    }
    double rad(point a,point b)
    {
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    point trunc(double r)
    {
        double l=len();
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
    point rotate(point p,double angle)//Rotar un �ngulo angle en sentido contrario a las agujas del reloj alrededor del punto p
    {
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
};
struct line
{
    point a,b;
    line(){}
    line(point _a,point _b)
    {
        a=_a;
        b=_b;
    }
    bool operator==(line v)
    {
        return (a==v.a)&&(b==v.b);
    }
    //�ngulo de inclinaci�n angle
    line(point p,double angle)
    {
        a=p;
        if (dblcmp(angle-pi/2)==0)
        {
            b=a.add(point(0,1));
        }
        else
        {
            b=a.add(point(1,tan(angle)));
        }
    }
    //ax+by+c=0
    line(double _a,double _b,double _c)
    {
        if (dblcmp(_a)==0)
        {
            a=point(0,-_c/_b);
            b=point(1,-_c/_b);
        }
        else if (dblcmp(_b)==0)
        {
            a=point(-_c/_a,0);
            b=point(-_c/_a,1);
        }
        else
        {
            a=point(0,-_c/_b);
            b=point(1,(-_c-_a)/_b);
        }
    }
    void input()
    {
        a.input();
        b.input();
    }
    void adjust()
    {
        if (b<a)swap(a,b);
    }
    double length()
    {
        return a.distance(b);
    }
    double angle()//inclinaci�n en l�nea recta 0<=angle<180
    {
        double k=atan2(b.y-a.y,b.x-a.x);
        if (dblcmp(k)<0)k+=pi;
        if (dblcmp(k-pi)==0)k-=pi;
        return k;
    }
    // relaci�n punto y l�nea
    //1 en sentido antihorario
    //2 en el sentido de las agujas del reloj
    //3 paralelo
    int relation(point p)
    {
        int c=dblcmp(p.sub(a).det(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    bool pointonseg(point p)
    {
        return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
    }
    bool parallel(line v)
    {
        return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
    }
    //2 intersecci�n can�nica
    //1 intersecci�n no can�nica
    //0 disjunto
    int segcrossseg(line v)
    {
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if ((d1^d2)==-2&&(d3^d4)==-2)return 2;
        return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
                d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
                d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
                d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);
    }
    int linecrossseg(line v)//*this seg v line
    {
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    //0 paralelo
    //1 superposici�n
    //2 se cruzan
    int linecrossline(line v)
    {
        if ((*this).parallel(v))
        {
            return v.relation(a)==3;
        }
        return 2;
    }
    point crosspoint(line v)
    {
        double a1=v.b.sub(v.a).det(a.sub(v.a));
        double a2=v.b.sub(v.a).det(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
    double dispointtoline(point p)
    {
        return fabs(p.sub(a).det(b.sub(a)))/length();
    }
    double dispointtoseg(point p)
    {
        if (dblcmp(p.sub(b).dot(a.sub(b)))<0||dblcmp(p.sub(a).dot(b.sub(a)))<0)
        {
            return min(p.distance(a),p.distance(b));
        }
        return dispointtoline(p);
    }
    point lineprog(point p)
    {
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
    }
    point symmetrypoint(point p)
    {
        point q=lineprog(p);
        return point(2*q.x-p.x,2*q.y-p.y);
    }
};

void read(vector<point> pol[],int id){
    string name;
    cin>>name;
    //cout<<"name is "<<name<<"\n";

    if(name=="square"){
        int x0,y0,x1,y1;
        scanf(" (%d,%d)",&x0,&y0);
        scanf(" (%d,%d)",&x1,&y1);
        point a(x0,y0),b,c(x1,y1),d;
        b=c.add(c.sub(a).rotright()).add(a).div(2);
        d=c.add(c.sub(a).rotleft()).add(a).div(2);
        pol[id].pb(a);
        pol[id].pb(b);
        pol[id].pb(c);
        pol[id].pb(d);

    }else if(name=="rectangle"){
        int x0,y0,x1,y1,x2,y2;
        scanf(" (%d,%d)",&x0,&y0);
        scanf(" (%d,%d)",&x1,&y1);
        scanf(" (%d,%d)",&x2,&y2);
        point a(x0,y0),b(x1,y1),c(x2,y2),d;
        d=a.add(c).sub(b);
        pol[id].pb(a);
        pol[id].pb(b);
        pol[id].pb(c);
        pol[id].pb(d);
    }else if(name=="line"){
        int x0,y0,x1,y1;
        scanf(" (%d,%d)",&x0,&y0);
        scanf(" (%d,%d)",&x1,&y1);
        pol[id].pb(point(x0,y0));
        pol[id].pb(point(x1,y1));

    }else if(name=="triangle"){
        int x0,y0,x1,y1,x2,y2;
        scanf(" (%d,%d)",&x0,&y0);
        scanf(" (%d,%d)",&x1,&y1);
        scanf(" (%d,%d)",&x2,&y2);
        point a(x0,y0),b(x1,y1),c(x2,y2);
        pol[id].pb(a);
        pol[id].pb(b);
        pol[id].pb(c);

    }else if(name=="polygon"){
        int n;
        scanf(" %d",&n);
        for(int i=0;i<n;i++){
            int x,y;
            scanf(" (%d,%d)",&x,&y);
            pol[id].pb(point(x,y));
        }
    }
}
bool polIntersect(vector<point> &a,vector<point> &b){
    int n=a.size(),m=b.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(line(a[i],a[(i+1)%n]).segcrossseg(line(b[j],b[(j+1)%m]))) return true;
        }
    }
    return false;
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << setprecision(12) << fixed;

	char c;
	while(true){
        c=getchar();
        if(c=='.') break;
        vector<point> pol[26];
        //printf("%s leido",s);
        getchar();
        read(pol,c-'A');
        getchar();
        while(true){
            c=getchar();
            if(c=='-') break;
            getchar();
            read(pol,c-'A');
            getchar();
        }
        vector<int> adj[26];
        for(int i=0;i<26;i++){
            if(pol[i].size()==0) continue;
            for(int j=i+1;j<26;j++){
                if(pol[j].size()==0) continue;

                if(polIntersect(pol[i],pol[j])){
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
        }
        for(int i=0;i<26;i++){
            if(pol[i].size()==0) continue;
            if(adj[i].size()==0) printf("%c has no intersections\n",'A'+i);
            else if(adj[i].size()==1) printf("%c intersects with %c\n",'A'+i,'A'+adj[i][0]);
            else if(adj[i].size()==2) printf("%c intersects with %c and %c\n",'A'+i,'A'+adj[i][0],'A'+adj[i][1]);
            else{
                printf("%c intersects with ",'A'+i);
                for(int j=0;j<adj[i].size()-1;j++){
                    printf("%c, ",'A'+adj[i][j]);
                }
                printf("and %c\n",'A'+adj[i].back());
            }
        }
        printf("\n");
        getchar();

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