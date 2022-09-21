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

const ll inf=LLONG_MAX;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<ll,ll>> p(n);
	vector<ll> power(n);
	for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second>>power[i];
/*	vector<int> d(n);
	auto bfs = [&](int start){
        for(int i=0;i<n;i++) d[i]=inf;
        d[start]=0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int now=q.front();
            q.pop();
            for(int next=0;next<n;next++){
                int dist=abs(p[next].first-p[now].first)+abs(p[next].second-p[now].second);
                int newd=max((dist+power[now]-1)/power[now],d[now]);
                if(d[next]>newd){
                    q.push(next);
                    d[next]=newd;
                }
            }
        }
	};
	*/
	vector<vector<ll>> d(n,vector<ll>(n,inf));
	for(int i=0;i<n;i++) d[i][i]=0;
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) if(i!=j) d[i][j]=(abs(p[j].first-p[i].first)+abs(p[j].second-p[i].second)+power[i]-1)/power[i];
	for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
            }
        }
	}


	ll res=inf;
	for(int i=0;i<n;i++){
        ll ans=0;
        for(int j=0;j<n;j++) ans=max(ans,d[i][j]);
        res=min(res,ans);
	}
	cout<<res<<"\n";
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
