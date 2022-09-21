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
#define pt pair<int,int>
#define x first
#define y second
using namespace std;

int dot(pt a,pt b,pt c){
    pt u={b.x-a.x,b.y-a.y};
    pt v={c.x-a.x,c.y-a.y};
    return u.x*v.x+u.y*v.y;
}
int cross(pt a,pt b,pt c){
    pt u={b.x-a.x,b.y-a.y};
    pt v={c.x-a.x,c.y-a.y};
    return u.x*v.y-v.x*u.y;
}
string pointInPolygon(vector<pt> &v,pt p){
    int n=v.size(),ni=0;
    for(int i=0;i<n;i++){
        pt a=v[i],b=v[(i+1)%n];
        if(a.y==b.y){
            if(a.x>b.x) swap(a,b);
            if(p.y==a.y && a.x<=p.x && p.x<=b.x) return "BORDER";
            continue;
        }
        if(a.y>b.y) swap(a,b);
        if(a.y<=p.y && p.y<=b.y && cross(a,b,p)<=0){
            if(cross(a,b,p)==0 && dot(p,a,b)<=0) return "BORDER";
            if(p.y!=b.y) ni++;
        }
    }
    if(ni&1) return "INSIDE";
    else return "OUTSIDE";
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
        cout<<pointInPolygon(v,p)<<"\n";
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
