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

vector<vector<int>> child;
vector<ll> c;
vector<int> r;

ll dfs(int now,int k){
    int cs=child[now].size();
    ll ans=c[now];
    if(cs>0){
        r[now]=k%cs;
        ans*=(k/cs)*cs;
    }else{
        r[now]=0;
        ans*=k;
    }
    for(int next:child[now]){
        ans+=dfs(next,k/cs);
    }
    return ans;
}

ll dfs2(int now,ll &best){
    ll ans=c[now]*r[now];
    vector<ll> costs;
    for(int next:child[now]){
        ll mex;
        ans+=dfs2(next,mex);
        //cout<<next+1<<" "<<mex<<"\n";
        costs.pb(mex);
    }
    if(costs.size()>0){
        sort(all(costs));
        int i,j;
        for(i=costs.size()-1,j=0;j<r[now];i--,j++){
            ans+=costs[i];
        }
        if(i>=0) best=c[now]+costs[i];
        else best=c[now];
    }else best=c[now];
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,k;
        cin>>n>>k;
        child.clear();
        child.resize(n);
        c.resize(n);
        r.resize(n);
        for(int i=1;i<n;i++){
            int p;
            cin>>p;
            child[p-1].pb(i);
        }
        for(int i=0;i<n;i++) cin>>c[i];
        ll ans=0,xd;
        ans+=dfs(0,k);
        ans+=dfs2(0,xd);
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
