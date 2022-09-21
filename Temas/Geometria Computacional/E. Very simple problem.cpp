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
    return u.x*v.y-u.y*v.x;
}
bool inside(vector<pt> &v,pt p){
    int n=v.size(),start=0;
    for(int i=1;i<n;i++){
        if(v[i].x<v[start].x || (v[i].x==v[start].x && v[i].y<v[start].y)) start=i;
    }
    rotate(v.begin(),v.begin()+start,v.end());
    if(cross(v[0],v[1],p)<0) return false;
    if(cross(v[0],v[n-1],p)>0) return false;
    int l=1,r=n-2;
    while(l<r){
        int m=(l+r+1)/2;
        if(cross(v[0],v[m],p)>=0) l=m;
        else r=m-1;
    }
    ll st=abs(cross(v[0],v[l],v[l+1]));
    ll s1=abs(cross(p,v[0],v[l]));
    ll s2=abs(cross(p,v[l],v[l+1]));
    ll s3=abs(cross(p,v[l+1],v[0]));
    if(st==s1+s2+s3) return true;
    return false;
}
ll f3(ll x){
    return (x*(x-1)*(x-2))/6;
}
ll f2(ll x){
    return (x*(x-1))/2;
}
ll solve(vector<pt> &v,pt p){
    if(!inside(v,p)) {
        //cout<<"fuera\n";
        return 0;
    }
    int n=v.size();
    ll all=f3(n),cnt=0;
    for(int pos=0;pos<n;pos++){
        int l=1,r=n-2;
        while(l<r){
            int m=(r+l+1)/2;
            if(cross(v[pos],v[(pos+m)%n],p)>=0) l=m;
            else r=m-1;
        }
        cnt+=f2(l)+f2(n-l-1);
    }
    return all-(cnt/2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << setprecision(12) << fixed;'
	int n,t;
	cin>>n;
	vector<pt> v(n);
	for(int i=0;i<n;i++) cin>>v[i].x>>v[i].y;
	reverse(all(v));
	cin>>t;
	for(int i=0;i<t;i++){
        pt p;
        cin>>p.x>>p.y;
        cout<<solve(v,p)<<"\n";
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
