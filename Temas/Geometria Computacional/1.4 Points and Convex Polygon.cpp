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


ll dot(pt a,pt b,pt c){
    pt u={b.x-a.x,b.y-a.y};
    pt v={c.x-a.x,c.y-a.y};
    return u.x*v.x+u.y*v.y;
}
ll cross(pt a,pt b,pt c){
    pt u={b.x-a.x,b.y-a.y};
    pt v={c.x-a.x,c.y-a.y};
    return u.x*v.y-v.x*u.y;
}
string pointInConvexPolygon(vector<pt> &v,pt p){
    int n=v.size(),start=0;
    for(int i=1;i<n;i++){
        if(v[i].x<v[start].x || (v[i].x==v[start].x && v[i].y<v[start].y)) start=i;
    }
    rotate(v.begin(),v.begin()+start,v.end());
    if(cross(v[0],v[1],p)<0) return "OUTSIDE";
    if(cross(v[0],v[n-1],p)>0) return "OUTSIDE";
    if(cross(v[0],v[1],p)==0){
        if(dot(p,v[0],v[1])<=0) return "BORDER";
        else "OUTSIDE";
    }
    if(cross(v[0],v[n-1],p)==0){
        if(dot(p,v[0],v[n-1])<=0) return "BORDER";
        else return "OUTSIDE";
    }

    int l=1,r=n-1;
    while(l<r){
        int m=(l+r+1)/2;
        if(cross(v[0],v[m],p)>=0) l=m;
        else r=m-1;
    }
    ll st=abs(cross(v[0],v[l],v[l+1]));
    ll s1=abs(cross(p,v[0],v[l]));
    ll s2=abs(cross(p,v[l],v[l+1]));
    ll s3=abs(cross(p,v[l+1],v[0]));
    if(st==s1+s2+s3){
        if(s2==0) return "BORDER";
        else return "INSIDE";
    }else return "OUTSIDE";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    int m,n;
    cin>>m;
    vector<pt> v(m);
    for(int i=0;i<m;i++) cin>>v[i].x>>v[i].y;
    cin>>n;
    for(int i=0;i<n;i++){
        pt p;
        cin>>p.x>>p.y;
        cout<<pointInConvexPolygon(v,p)<<"\n";
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
