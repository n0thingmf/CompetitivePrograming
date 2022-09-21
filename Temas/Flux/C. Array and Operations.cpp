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

const int inf=1e5;
int sz;
map<pair<int,int>,int> cap;
vector<vector<int>> adj;

int bfs(int s,int t,vector<int> &path){
    for(int i=0;i<sz;i++) path[i]=-1;
    path[s]=-2;
    queue<pair<int,int>> Q;
    Q.push({s,INT_MAX});
    while(!Q.empty()){
        int now=Q.front().first;
        int flow=Q.front().second;
        Q.pop();
        for(int next:adj[now]){
            int e_cap=cap[{now,next}];
            if(path[next]==-1 && e_cap>0){
                flow=min(flow,e_cap);
                path[next]=now;
                if(next==t){
                    return flow;
                }
                Q.push({next,flow});
            }
        }
    }
    return 0;
}
//Edmonds-Karp Algorithm(Ford fulkerson implementation)
int MaxFlow(int s,int t){
    int max_flow=0,new_flow;
    vector<int> path(sz);
    while(new_flow=bfs(s,t,path)){
        int e1,e2=t;
        while(e2!=s){
            e1=path[e2];
            cap[{e1,e2}]-=new_flow;
            cap[{e2,e1}]+=new_flow;
            e2=e1;
        }
        max_flow+=new_flow;
    }
    return max_flow;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	set<int> primes;
	adj.resize(n+2);
	sz=n+2;
	for(int i=0;i<n;i++){
        cin>>a[i];
        int x=a[i];
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                primes.insert(j);
                while(x%j==0){
                    x/=j;
                }
            }
        }
        if(x>1) primes.insert(x);
	}
	for(int i=1;i<=n;i++){
        if(i%2){
            adj[i].pb(n+1);
        }
        else{
            adj[0].pb(i);
        }
	}
	vector<pair<int,int>> e(m);
	for(int i=0;i<m;i++){
        cin>>e[i].first>>e[i].second;
        adj[e[i].first].pb(e[i].second);
        adj[e[i].second].pb(e[i].first);
        if(e[i].first%2) swap(e[i].first,e[i].second);
	}
	int ans=0;
	for(int p:primes){
        //cout<<"primo: "<<p<<"\n";
        for(int i=2;i<=n;i+=2){
            int exp=0,num=a[i-1];
            while(num%p==0) num/=p,exp++;
            cap[{0,i}]=exp;
        }
        for(int i=1;i<=n;i+=2){
            int exp=0,num=a[i-1];
            while(num%p==0) num/=p,exp++;
            cap[{i,n+1}]=exp;
        }
        for(int i=0;i<m;i++){
            cap[{e[i].first,e[i].second}]=inf;
            cap[{e[i].second,e[i].first}]=0;
        }
        ans+=MaxFlow(0,n+1);
	}
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
