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
#define p pair<ll,ll>
#define x first
#define y second

using namespace std;

p operator -(const p a,const p b){
    return {a.x-b.x,a.y-b.y};
}
ll cross(p a,p b){
    return a.x*b.y-b.x*a.y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,q;
	cin>>n;
	vector<p> pol(n);
	for(int i=0;i<n;i++){
        cin>>pol[i].x>>pol[i].y;
	}
	cin>>m;
	vector<p> v(m);
	for(int i=0;i<m;i++){
        cin>>v[i].x>>v[i].y;
	}
	vector<ll> maxcross(n,LLONG_MIN);
	for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxcross[i]=max(maxcross[i],cross(pol[(i+1)%n]-pol[i],v[j]));
        }
	}
	cin>>q;
	while(q--){
        p qry;
        cin>>qry.x>>qry.y;
        bool ok=true;
        for(int i=0;i<n;i++){
            if(cross(pol[(i+1)%n]-pol[i],qry-pol[i])<maxcross[i]){
                ok=false;
                break;
            }
        }
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
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
