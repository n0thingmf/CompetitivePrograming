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
int n; //numero de nodos
map<pair<int,int>,int> cap;
vector<vector<int>> adj;

int bfs(int s,int t,vector<int> &path){
    for(int i=0;i<n;i++) path[i]=-1;
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
    vector<int> path(n);
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
	int m,s,t;
	int ncase=0;
	while(cin>>n && n){
    ncase++;
	cin>>s>>t>>m;
	s--,t--;
	adj.resize(n);
	for(int i=0;i<n;i++) adj[i].clear();
	cap.clear();
	for(int i=0;i<m;i++){
        int a,b,e_cap;
        cin>>a>>b>>e_cap;
        //cout<<a<<b<<e_cap<<"\n";
        a--;
        b--;
        if(cap.count({a,b})==0){
            adj[a].pb(b);
            adj[b].pb(a);
            cap[{a,b}]=e_cap;
            cap[{b,a}]=e_cap;
        }
        else{
            cap[{a,b}]+=e_cap;
            cap[{b,a}]+=e_cap;
        }
	}
	/*cout<<"capacity\n";
	for(auto x:cap){
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<"\n";
	}*/
	//vector<int> path(n);
	//cout<<bfs(s,t,path)<<"\n";
	cout<<"Network "<<ncase<<"\n";
	cout<<"The bandwidth is "<<MaxFlow(s,t)<<".\n";
	cout<<"\n";
	}
	return 0;
}

//Ford-Fulkerson Algorithm
/*
int maxflow(int s,int t,Graph G){
    Gf=G;
    for(edges e:G){
        e.flow=0;
    }
    int max_flow=0;
    while(there is a path from s to t in Gf){
            path=find_path(Gf);
            int mflow=INF;
            for(edges e:path){
                mflow=min(mflow,e.cap-e.flow);
            }
            max_flow+=mflow;
            for(edges e:path){
                e.flow+=mflow;
                reverse(e).flow-=mflow;
            }
    }
    return max_flow;
}
*/
