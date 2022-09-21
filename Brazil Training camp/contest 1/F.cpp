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
const int maxn=2e6;
int par[maxn];
ll area[maxn];
ll sumarea[maxn];
int dsufind(int v){
    if(v==par[v]) return v;
    par[v]=dsufind(par[v]);
    return par[v];
}
void dsuunion(int u,int v){
    u=dsufind(u);
    v=dsufind(v);
    if(u!=v) par[v]=u;
}

class rectan{
public:
    int compx,compy,x0,y0,x1,y1,x2,y2,x3,y3,id;
    rectan(int _compx,int _compy,int _x0,int _y0,int _x1,int _y1,int _x2,int _y2,int _x3,int _y3,int _id){
        compx=_compx,compy=_compy,x0=_x0,y0=_y0,x1=_x1,y1=_y1,x2=_x2,y2=_y2,x3=_x3,y3=_y3,id=_id;
    }
};

bool comp1(rectan u,rectan v){
    if(u.compx==v.compx) return u.compy<v.compy;
    return u.compx<v.compx;
}
bool comp2(rectan u,rectan v){
    if(u.compy==v.compy) return u.compx<v.compx;
    return u.compy<v.compy;
}
bool comp3(rectan u,rectan v){
    if(u.compy==v.compy) return u.compx>v.compx;
    return u.compy<v.compy;
}
bool comp4(rectan u,rectan v){
    if(u.compx==v.compx) return u.compy>v.compy;
    return u.compx<v.compx;
}
bool adj(rectan u,rectan v){
    if(u.compx==v.compx && u.compy==v.compy) return true;
    if(u.x0==v.x0){
        if(u.y0<=v.y0 && u.y2>=v.y0) return true;
        if(u.y0<=v.y2 && u.y2>=v.y2) return true;
    }
    if(u.x1==v.x1){
        if(u.y0<=v.y0 && u.y2>=v.y0) return true;
        if(u.y0<=v.y2 && u.y2>=v.y2) return true;
    }
    if(u.x0==v.x1){
        if(u.y0<=v.y0 && u.y2>=v.y0) return true;
        if(u.y0<=v.y2 && u.y2>=v.y2) return true;
    }
    if(u.x1==v.x0){
        if(u.y0<=v.y0 && u.y2>=v.y0) return true;
        if(u.y0<=v.y2 && u.y2>=v.y2) return true;
    }
    if(u.y0==v.y0){
        if(u.x0<=v.x0 && u.x1>=v.x0) return true;
        if(u.x0<=v.x1 && u.x1>=v.x1) return true;
    }
    if(u.y2==v.y2){
        if(u.x0<=v.x0 && u.x1>=v.x0) return true;
        if(u.x0<=v.x1 && u.x1>=v.x1) return true;
    }
    if(u.y0==v.y2){
        if(u.x0<=v.x0 && u.x1>=v.x0) return true;
        if(u.x0<=v.x1 && u.x1>=v.x1) return true;
    }
    if(u.y2==v.y0){
        if(u.x0<=v.x0 && u.x1>=v.x0) return true;
        if(u.x0<=v.x1 && u.x1>=v.x1) return true;
    }
    return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>n){
        for(int i=0;i<maxn;i++) par[i]=i,area[i]=0,sumarea[i]=0;
        vector<rectan> r;
        for(int i=0;i<n;i++){
            int x,y,w,h;
            cin>>x>>y>>w>>h;
            r.pb(rectan(x,y,x,y,x+w,y,x+w,y+h,x,y+h,i));
            r.pb(rectan(x+w,y,x,y,x+w,y,x+w,y+h,x,y+h,i));
            r.pb(rectan(x,y+h,x,y,x+w,y,x+w,y+h,x,y+h,i));
            r.pb(rectan(x+w,y+h,x,y,x+w,y,x+w,y+h,x,y+h,i));
            area[i]=w*h;
        }
        sort(all(r),comp1);
        for(int i=0;i<r.size()-1;i++){
            if(adj(r[i],r[i+1])){
                dsuunion(r[i].id,r[i+1].id);
            }
        }
        sort(all(r),comp2);
        for(int i=0;i<r.size()-1;i++){
            if(adj(r[i],r[i+1])){
                dsuunion(r[i].id,r[i+1].id);
            }
        }
        sort(all(r),comp3);
        for(int i=0;i<r.size()-1;i++){
            if(adj(r[i],r[i+1])){
                dsuunion(r[i].id,r[i+1].id);
            }
        }
        sort(all(r),comp4);
        for(int i=0;i<r.size()-1;i++){
            if(adj(r[i],r[i+1])){
                dsuunion(r[i].id,r[i+1].id);
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            int group=dsufind(i);
            sumarea[group]+=area[i];
            ans=max(ans,sumarea[group]);
        }
        cout<<ans<<"\n";
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
