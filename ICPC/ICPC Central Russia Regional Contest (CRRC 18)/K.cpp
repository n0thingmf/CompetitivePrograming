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
const double eps=1e-9;
const double pi=acos(-1.0);

int dblcmp(double d)
{
    if (fabs(d)<eps)return 0;
    return d>eps?1:-1;
}
double sqr(double x){return x*x;}
class point{
public:
    double x,y;
    point(){}
    point(double _x,double _y){
        x=_x,y=_y;
    }
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    void output(){
        printf("%.4f %.4f\n",x,y);
    }
    point operator=(point a){
        x=a.x,y=a.y;
        return *this;
    }
    bool operator==(point a)const{
        return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
    }
    bool operator<(point a)const{
        return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
    }
    double len(){
        return hypot(x,y);
    }
    double len2(){
        return x*x+y*y;
    }
    double distance(point p){
        return hypot(x-p.x,y-p.y);
    }
    point add(point p){
        return point(x+p.x,y+p.y);
    }
    point sub(point p){
        return point(x-p.x,y-p.y);
    }
    point mul(double b){
        return point(x*b,y*b);
    }
    point div(double b){
        return point(x/b,y/b);
    }
    double dot(point p){
        return x*p.x+y*p.y;
    }
    double det(point p){
        return x*p.y-y*p.x;
    }
    double rad(point a,point b){
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    point trunc(double r){
        double l=len();
        if (!dblcmp(l))return *this;
        r/=l;
        return point(x*r,y*r);
    }
    point rotleft(){
        return point(-y,x);
    }
    point rotright(){
        return point(y,-x);
    }
    point rotate(point p,double angle){//Rotate angle counterclockwise around point p
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
};

class line{
public:
    point a,b;
    line(){}
    line(point _a,point _b){
        a=_a,b=_b;
    }
    line operator=(line v){
        a=v.a,b=v.b;
        return *this;
    }
    bool operator==(line v){
        return (a==v.a)&&(b==v.b);
    }
    //Tilt angle
    line(point p,double angle){
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
    line(double _a,double _b,double _c){
        if (dblcmp(_a)==0){
            a=point(0,-_c/_b);
            b=point(1,-_c/_b);
        }
        else if (dblcmp(_b)==0){
            a=point(-_c/_a,0);
            b=point(-_c/_a,1);
        }
        else{
            a=point(0,-_c/_b);
            b=point(1,(-_c-_a)/_b);
        }
    }
    void input(){
        a.input();
        b.input();
    }
    void adjust(){
        if (b<a) swap(a,b);
    }
    double length(){
        return a.distance(b);
    }
    double angle(){//Straight line tilt angle 0<=angle<180
        double k=atan2(b.y-a.y,b.x-a.x);
        if (dblcmp(k)<0)k+=pi;
        if (dblcmp(k-pi)==0)k-=pi;
        return k;
    }
    //Point and line relationship
    //1 is counterclockwise
    //2 in clockwise
    //3 parallel
    int relation(point p){
        int c=dblcmp(p.sub(a).det(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    bool pointonseg(point p){
        return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
    }
    bool parallel(line v){
        return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
    }
    //2 specification intersection
    //1 non-canonical intersection
    //0 disjoint
    int segcrossseg(line v){
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
    int linecrossseg(line v){//*this seg v line
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    //0 parallel
    //1 coincide
    //2 intersect
    int linecrossline(line v){
        if ((*this).parallel(v))
        {
            return v.relation(a)==3;
        }
        return 2;
    }
    point crosspoint(line v){
        double a1=v.b.sub(v.a).det(a.sub(v.a));
        double a2=v.b.sub(v.a).det(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
    double dispointtoline(point p){
        return fabs(p.sub(a).det(b.sub(a)))/length();
    }
    double dispointtoseg(point p){
        if (dblcmp(p.sub(b).dot(a.sub(b)))<0||dblcmp(p.sub(a).dot(b.sub(a)))<0)
        {
            return min(p.distance(a),p.distance(b));
        }
        return dispointtoline(p);
    }
    point lineproy(point p){
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
    }
    point symmetrypoint(point p){
        point q=lineproy(p);
        return point(2*q.x-p.x,2*q.y-p.y);
    }
};
double construct(point a,point b,point c,point d){
    point m1=a.add(b).div(2),m2=c.add(d).div(2);
    point c1=m1.add(m1.trunc(a.distance(b)/(sqrt(3)*2))),c2=m2.add(m2.trunc(c.distance(d)/(sqrt(3)*2)));
    point u1=c1.add(m1.trunc(a.distance(b)/sqrt(3))),u2=c2.add(m2.trunc(c.distance(d)/sqrt(3)));
    line l1(u1,u2),l2(u2,u1);
    point x1=u1.add(l1.lineproy(c1).sub(u1).mul(2)),x2=u2.add(l2.lineproy(c2).sub(u2).mul(2));
    double res=x1.distance(a)+x1.distance(b)+x1.distance(x2)+x2.distance(c)+x2.distance(d);
    //cout<<res<<"\n";
    return res;
}
double solve(point p[4]){
    double ans=p[2].sub(p[0]).len()+p[3].sub(p[1]).len();
    for(int i=0;i<2;i++){
        ans=min(ans,construct(p[i],p[i+1],p[i+2],p[(i+3)%4]));
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;
    int r;
    int g[4];
    cin>>r>>g[0]>>g[1]>>g[2]>>g[3];
    point p[4];
    for(int i=0, deg=0;i<4;i++){
        double ang=(pi/180)*deg;
        p[i]=point(cos(ang)*r,sin(ang)*r);
        deg+=g[i];
    }
    cout<<solve(p);
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
