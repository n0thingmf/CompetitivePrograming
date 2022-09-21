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
const ll dd=1e9;
const double inf=1e12;
ll cross(pt a,pt b,pt c){
    pt u={b.x-a.x,b.y-a.y};
    pt v={c.x-a.x,c.y-a.y};
    return u.x*v.y-v.x*u.y;
}
bool to_left(pt a,pt b,pt c){
    return cross(a,b,c)>0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    cout << setprecision(3) << fixed;
	int n;
	cin>>n;
	vector<vector<pt>> pol(n);
	vector<vector<pt>> l(n),r(n);
	vector<ll> minx(n,LLONG_MAX),maxx(n,LLONG_MIN);
	for(int i=0;i<n;i++){
        int k;
        cin>>k;
        pol[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>pol[i][j].x>>pol[i][j].y;
            maxx[i]=max(maxx[i],pol[i][j].x);
            minx[i]=min(minx[i],pol[i][j].x);
        }
        r[i].pb(pol[i][1]);
        int j;
        for(j=2;pol[i][j].y!=pol[i][j-1].y;j++){
            r[i].pb(pol[i][j]);
        }
        for(;j<k;j++) l[i].pb(pol[i][j]);
        l[i].pb(pol[i][0]);
	}
	vector<vector<double>> d(n,vector<double>(n,inf));
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            for(int u=r[i].size()-1,v=0;u>=0;u--){
                while(r[i][u].y>l[j][v].y || r[i][u].y<l[j][v+1].y) v++;

                ll dist1=r[i][u].y-l[j][v+1].y,dist2=l[j][v].y-r[i][u].y;
                double dist=((double)(l[j][v].x*dist1+l[j][v+1].x*dist2))/(dist1+dist2);
                dist=dist-r[i][u].x;
                d[i][j]=min(d[i][j],dist);
            }
            for(int u=0,v=r[i].size()-1;u<l[j].size();u++){
                while(l[j][u].y>r[i][v].y || l[j][u].y<r[i][v-1].y) v--;

                ll dist1=l[j][u].y-r[i][v-1].y,dist2=r[i][v].y-l[j][u].y;
                double dist=((double)(r[i][v].x*dist1+r[i][v-1].x*dist2))/(dist1+dist2);
                dist=l[j][u].x-dist;
                d[i][j]=min(d[i][j],dist);
            }
            d[i][j]=(double)maxx[j]-maxx[i]-d[i][j];
        }
	}
	vector<vector<double>> dp((1<<n),vector<double>(n,inf));
	for(int i=0;i<n;i++){
        dp[1<<i][i]=maxx[i]-minx[i];
	}
	for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(dp[mask][i]!=inf){
                for(int j=0;j<n;j++){
                    if((mask&(1<<j))==0){
                        dp[mask|(1<<j)][j]=min(dp[mask|(1<<j)][j],dp[mask][i]+d[i][j]);
                    }
                }
            }
        }
	}
	double ans=inf;
	for(int i=0;i<n;i++) ans=min(ans,dp[(1<<n)-1][i]);
	cout<<ans<<"\n";
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
