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

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
class pt{
public:
    ll x,y,z;
    pt(){
        x=y=z=0;
    }
    pt(int _x,int _y,int _z){
        x=_x,y=_y,z=_z;
    }
    pt operator=(pt other){
        x=other.x;
        y=other.y;
        z=other.z;
        return *this;
    }
    pt operator+(pt other){
        pt ans;
        ans.x=x+other.x,ans.y=y+other.y,ans.z=z+other.z;
        return ans;
    }
    pt operator-(pt other){
        pt ans;
        ans.x=x-other.x,ans.y=y-other.y,ans.z=z-other.z;
        return ans;
    }
    void normalize(){
        ll g=gcd(gcd(abs(x),abs(y)),abs(z));
        x/=g;
        y/=g;
        z/=g;
    }
    double norm(){
        return sqrt(x*x+y*y+z*z);
    }
};
pt cross(pt a,pt b){
        pt ans;
        ans.x=a.y*b.z-b.y*a.z;
        ans.y=b.x*a.z-a.x*b.z;
        ans.z=a.x*b.y-b.x*a.y;
        return ans;
}
ll det(pt a,pt b,pt c){
    return a.x*(b.y*c.z-b.z*c.y)-a.y*(b.x*c.z*b.z*c.x)+a.z*(b.x*c.y-b.y*c.x);
}
double area2(vector<pt> &p){
    pt ans;
    for(int i=1;i<p.size()-1;i++){
        pt cc=cross(p[i]-p[0],p[i+1]-p[0]);
        ans=ans+cc;
    }
    return ans.norm();
}
double solve(vector<pt> &p,ll inside){
    int n=p.size();
    for(int i=1;i<n;i++) p[i]=p[i]-p[0];
    p[0].x=p[0].y=p[0].z=0;
    pt w=cross(p[1],p[2]-p[1]);
    pt u=p[1];
    u.normalize();
    w.normalize();
    pt v=cross(u,w);
    v.normalize();
    double k=cross(u,v).norm()/w.norm();
    //cout<<w.x<<" "<<w.y<<" "<<w.z<<"\n";
    double s=area2(p);
    cout<<k<<" "<<s<<"\n";
    ll border=n;
    for(int i=0;i<n;i++){
        ll dx=abs(p[(i+1)%n].x-p[i].x);
        ll dy=abs(p[(i+1)%n].y-p[i].y);
        ll dz=abs(p[(i+1)%n].z-p[i].z);
        border+=gcd(gcd(dx,dy),dz)-1;

    };
    //return border;
    return s/(2*inside+border-2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pt> p(n);
        for(int i=0;i<n;i++){
            cin>>p[i].x>>p[i].y>>p[i].z;
        }
        ll bound;
        cin>>bound;
        cout<<solve(p,bound)<<"\n";
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
