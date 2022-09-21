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

string pointInSegment(pt a,pt b,pt c){
    pt u={b.x-a.x,b.y-a.y},v={c.x-a.x,c.y-a.y};
    int cross=u.x*v.y-v.x*u.y;
    if(cross>0) return "LEFT";
    else if(cross==0){
        if((c.x-a.x)*(c.x-b.x)+(c.y-a.y)*(c.y-b.y)<=0) return "ON_SEGMENT";
        else return "ON_LINE";
    }else return "RIGHT";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	pt a,b;
	cin>>a.x>>a.y>>b.x>>b.y;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
        pt p;
        cin>>p.x>>p.y;
        cout<<pointInSegment(a,b,p)<<"\n";
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
