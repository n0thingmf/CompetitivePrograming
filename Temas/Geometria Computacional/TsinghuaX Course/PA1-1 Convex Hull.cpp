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
#define pt pair<ll,ll>
#define x first
#define y second
using namespace std;

class point{
public:
    int id;
    ll x,y;
    point(){
        id=0,x=0,y=0;
    }
    point(int ii,ll xx,ll yy){
        id=ii,x=xx,y=yy;
    }
};
ll dot(point a,point b,point c){
    return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}
ll cross(point a,point b,point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
bool between(point a,point b,point c){
    return (b.x-a.x)*(c.x-b.x)+(b.y-a.y)*(c.y-b.y)>0;
}
bool toLeft(point a,point b,point c){
    if(cross(a,b,c)>0) return true;
    if(cross(a,b,c)<0) return false;
    return between(a,b,c);
}
ll convexHull(vector<point> &p){
    int n=p.size();
    int start=0;
    for(int i=1;i<n;i++){
        if(p[i].y<p[start].y || (p[i].y==p[start].y && p[i].x<p[start].x)){
            start=i;
        }
    }
    vector<point> v;
    for(int i=0;i<n;i++){
        if(i==start) continue;
        v.pb(p[i]);
    }
    sort(all(v),[&p,start](point a,point b)->bool{return toLeft(p[start],a,b);});
    vector<point> ch;
    ch.pb(p[start]);
    ch.pb(v[0]);
    for(int i=1,j;i<n-1;i++){
        j=ch.size()-1;
        while(cross(ch[j-1],ch[j],v[i])<0){
            ch.popb();
            j--;
        }
        ch.pb(v[i]);
    }
    for(int j=n-3;j>=0;j--){
        if(cross(ch[0],ch.back(),v[j])==0 && cross(ch[0],ch[1],v[j])!=0) ch.pb(v[j]);
    }
    ll ans=ch.size(),mod=n+1;
    for(point pp:ch){
        //cout<<pp.id<<"\n";
        ans=(ans*pp.id)%mod;
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<point> p(n);
	for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
        p[i].id=i+1;
	}
    cout<<convexHull(p)<<"\n";

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
