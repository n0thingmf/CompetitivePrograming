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

string pointInTriangle(pt a,pt b,pt c,pt p){
    int total=(c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
    int t1=(a.x-p.x)*(b.y-p.y)-(b.x-p.x)*(a.y-p.y);
    int t2=(b.x-p.x)*(c.y-p.y)-(c.x-p.x)*(b.y-p.y);
    int t3=(c.x-p.x)*(a.y-p.y)-(a.x-p.x)*(c.y-p.y);
    if(abs(total)==abs(t1)+abs(t2)+abs(t3)){
        if(abs(t1)==0 || abs(t2)==0 || abs(t3)==0) return "BORDER";
        else return "INSIDE";
    }else return "OUTSIDE";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	pt a,b,c;
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
        pt p;
        cin>>p.x>>p.y;
        cout<<pointInTriangle(a,b,c,p)<<"\n";
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
