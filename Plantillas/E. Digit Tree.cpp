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

const int maxn=1e5+2;

vector<pair<int,int>> adj[maxn];

ll mod,ans=0,sz[maxn],up[maxn],down[maxn];

map<ll,ll> fup,fdown;

bool big[maxn];

ll bezout(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll xx,yy;
    ll g=bezout(b,a%b,xx,yy);
    x=yy;
    y=xx-(a/b)*yy;
    return g;
}
ll inv(ll x){
    ll xx,yy;
    bezout(x,mod,xx,yy);
    return (xx%mod+mod)%mod;
}

void dfssz(int v,int p,ll e){
    sz[v]=1;
    if(p==-1){
        up[v]=down[v]=0;
    }
    for(auto edge:adj[v]){
        int u=edge.first;
        ll w=edge.second;
        if(u!=p){
            up[u]=(w*e+up[v])%mod;
            down[u]=(down[v]*10+w)%mod;
            dfssz(u,v,(e*10)%mod);
            sz[v]+=sz[u];
        }
    }
}
void add(int v,int p,ll e){
    fup[up[v]]++;
    fdown[(down[v]*inv(e))%mod]++;
    for(auto edge:adj[v]){
        int u=edge.first,w=edge.second;
        if(u!=p && !big[u]){
            add(u,v,e);
        }
    }
}
void sub(int v,int p,ll e){
    fup[up[v]]--;
    fdown[(down[v]*inv(e))%mod]--;
    for(auto edge:adj[v]){
        int u=edge.first,w=edge.second;
        if(u!=p && !big[u]){
            sub(u,v,e);
        }
    }
}
void answer(int v,int p,int r,ll er,ll e){
    ll a,b;
    a=(mod+up[v]-up[r])%mod;
    a=(a*inv(er))%mod;
    b=(down[r]*e)%mod;
    b=(b*inv(er))%mod;
    b=(mod+down[v]-b)%mod;
    a=(mod+down[r]-a)%mod;
    a=(a*inv(er))%mod;
    b=(mod-b)%mod;
    b=(b*inv(e))%mod;
    b=(b*er)%mod;
    b=(b*er)%mod;
    b=(b+up[r])%mod;
    ans+=fup[b];
    ans+=fdown[a];
    for(auto edge:adj[v]){
        int u=edge.first,w=edge.second;
        if(u!=p && !big[u]){
            answer(u,v,r,er,(e*10)%mod);
        }
    }
}
void dfs(int v,int p,ll e,bool keep){
    int maxsz=-1,maxv=-1;
    for(auto edge:adj[v]){
        int u=edge.first,w=edge.second;
        if(u!=p && sz[u]>maxsz){
            maxsz=sz[u],maxv=u;
        }
    }
    for(auto edge:adj[v]){
        int u=edge.first,w=edge.second;
        if(u!=p && u!=maxv) dfs(u,v,(e*10)%mod,false);
    }
    if(maxv!=-1){
        dfs(maxv,v,(e*10)%mod,true);
        big[maxv]=true;
    }
    //answer

    for(auto edge:adj[v]){
        int u=edge.first,w=edge.second;
        if(u!=p && u!=maxv){
            answer(u,v,v,e,(e*10)%mod);
            add(u,v,(e*10)%mod);
        }
    }
    ans+=fdown[(down[v]*inv(e))%mod];
    ans+=fup[up[v]];
    fup[up[v]]++;
    fdown[(down[v]*inv(e))%mod]++;

    if(maxv!=-1) big[maxv]=false;
    if(!keep){
        sub(v,p,e);
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n>>mod;
	for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
	}
	//for(int i=1;i<mod;i++) cout<<i<<" "<<inv(i)<<"\n";
	dfssz(0,-1,1);
	dfs(0,-1,1,false);
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
