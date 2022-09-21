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
const double pi=acos(-1);
class p{
public:
    int x,y,id;
    p(){
        x=0,y=0,id=-1;
    }
};
int dot(p a,p b,p c){
    return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}
int corss(p a,p b,p c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
bool toRight(p a,p b,p c){
    return cross(a,b,c)<0;
}
double ang(p a,p b){
    return pi-atan2(a.x*b.y−a.y*b.x,a.x*b.x+a.y*b.y);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<p> pt(n);
	for(int i=0;i<n;i++){
        cin>>pt[i].x>>pt[i].y;
        pt[i].id=i;
	}
	vector<vector<p>> cw(n);
	for(int i=0;i<n;i++){
        vector<p> up,down;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(pt[j].y<pt[i].y) down.pb(p[j]);
            else if(pt[j].y>pt[i].y) up.pb(p[j]);
            else if(pt[j].x>pt[i].x) down.pb(p[j]);
            else up.pb(p[j]);
        }
        sort(all(down),[&pt,i](p a,p b)->bool{return toRight(p[i],a,b);});
        sort(all(up),[&pt,i](p a,p b)->bool{return toRight(p[i],a,b);});
        down.insert( down.end(), up.begin(), up.end() );
        cw[i]=down;
	}
	vector<int> points(n,0);
	int now=0,angle=(ang(p[0],p[1])+ang(p[0],p[2]))/2;
	while(angle<(ang(p[0],p[1])+ang(p[0],p[2]))/2+2*pi){

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
