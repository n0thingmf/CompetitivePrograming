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

class point{
public:
    int x,y;
    point(){
        x=y=0;
    }
    point(int xx,int yy){
        x=xx,y=yy;
    }

};
class line{
public:

    int a,b,c;
    line(){
        a=b=1;
        c=0;
    }
    line(point u,point v){
        a=v.y-u.y;
        b=u.x-v.x;
        c=u.y*(v.x-u.x)-u.x*(v.y-u.y);
    }
    bool in(point p){
        return a*p.x+b*p.y+c==0;
    }
    line operator =(line other){
        a=other.a;
        b=other.b;
        c=other.c;
        return *this;
    }
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<point> p(n);
	for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
	if(n<=4){
        cout<<"YES\n";
        return 0;
	}
	line l1,l2;
	bool ok=false;
	for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
                line l(p[i],p[j]);
                if(l.in(p[k])){
                    ok=true;
                    l1=l;
                    break;
                }
            }
        }
	}
	if(ok){
        vector<point> bad;
        for(int i=0;i<n;i++) if(!l1.in(p[i])) bad.pb(p[i]);
        if(bad.size()>=2){
            l2=line(bad[0],bad[1]);
            ok=true;
            for(int i=2;i<bad.size();i++){
                if(!l2.in(bad[i])){
                    ok=false;
                    break;
                }
            }
            if(ok) cout<<"YES\n";
            else cout<<"NO\n";
        }else cout<<"YES\n";
	}
    else{
        cout<<"NO\n";
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
