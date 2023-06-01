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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        //cout<<"new testcaseee\n";
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i],a[i]=i+a[i];
        vector<int> vis(n,0);
        vector<int> comp(n,-1);
        int ncomp=0;
        vector<int> type;
        auto dfs = [&](int now,auto &&dfs) -> int{
            vis[now]=1;
            if(0<=a[now] && a[now]<n){
                if(vis[a[now]]==1){
                    comp[now]=ncomp;
                    type.pb(1);
                    vis[now]=0;
                    return ncomp++;
                }else{
                    int next;
                    if(comp[a[now]]==-1){
                        next=dfs(a[now],dfs);
                        comp[now]=next;
                        vis[now]=0;
                        return next;
                    }else{
                        next=comp[a[now]];
                        comp[now]=next;
                        vis[now]=0;
                        return next;
                    }

                }
            }else{
                comp[now]=ncomp;
                type.pb(0);
                vis[now]=0;
                return ncomp++;
            }
        };
        for(int i=0;i<n;i++){
            if(comp[i]==-1){
                dfs(i,dfs);
            }
        }
        int good=0;
        for(int i=0;i<n;i++){
            if(type[comp[i]]==0) good++;
        }
        if(type[comp[0]]){ //no existe respuesta, el vertice uno llega a un ciclo
            ll ans=0;
            vector<int> check(n,0);
            auto solve = [&](int v,auto &&solve) ->void{
                check[v]=1;
                ans+=good+n+1;
                if(check[a[v]]==0){
                    solve(a[v],solve);
                }
            };
            solve(0,solve);
            cout<<ans<<"\n";
        }else{
            ll ans=0;
            vector<vector<int>> rev(n+1);
            for(int i=0;i<n;i++){
                if(comp[i]==comp[0]){
                    if(0<=a[i] && a[i]<n) rev[a[i]].pb(i);
                    else rev[n].pb(i);
                }else ans+=2*n+1;
            }
            vector<int> check(n+1,0);
            vector<bool> judge(n+1,false);
            auto solve = [&](int u,auto &&solve) -> void{
                check[u]=1;
                if(u==0) judge[u]=true;
                for(int v:rev[u]){
                    solve(v,solve);
                    check[u]+=check[v];
                    if(judge[v]) judge[u]=true;
                }
            };
            solve(n,solve);
            //cout<<"caso1\n";
            for(int i=0;i<n;i++){
                if(comp[i]==comp[0]){
                    //cout<<i<<" "<<check[i]<<"\n";
                    if(judge[i]) ans+=good-check[i]+n+1;
                    else ans+=2*n+1;
                }
            }
            cout<<ans<<"\n";
        }
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
