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
struct two_sat {
    int n;
    vector<vector<int>> g, gr; // gr is the reversed graph
    vector<int> comp, topological_order, answer; // comp[v]: ID of the SCC containing node v
    vector<bool> vis;

    two_sat() {}

    two_sat(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        g.assign(2 * n, vector<int>());
        gr.assign(2 * n, vector<int>());
        comp.resize(2 * n);
        vis.resize(2 * n);
        answer.resize(2 * n);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    // For the following three functions
    // int x, bool val: if 'val' is true, we take the variable to be x. Otherwise we take it to be x's complement.

    // At least one of them is true
    void add_clause_or(int i, bool f, int j, bool g) {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }

    // Only one of them is true
    void add_clause_xor(int i, bool f, int j, bool g) {
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }

    // Both of them have the same value
    void add_clause_and(int i, bool f, int j, bool g) {
        add_clause_xor(i, !f, j, g);
    }

    // Topological sort
    void dfs(int u) {
        vis[u] = true;

        for (const auto &v : g[u])
            if (!vis[v]) dfs(v);

        topological_order.push_back(u);
    }

    // Extracting strongly connected components
    void scc(int u, int id) {
        vis[u] = true;
        comp[u] = id;

        for (const auto &v : gr[u])
            if (!vis[v]) scc(v, id);
    }

    // Returns true if the given proposition is satisfiable and constructs a valid assignment
    bool satisfiable() {
        fill(vis.begin(), vis.end(), false);

        for (int i = 0; i < 2 * n; i++)
            if (!vis[i]) dfs(i);

        fill(vis.begin(), vis.end(), false);
        reverse(topological_order.begin(), topological_order.end());

        int id = 0;
        for (const auto &v : topological_order)
            if (!vis[v]) scc(v, id++);

        // Constructing the answer
        for (int i = 0; i < n; i++) {
            if (comp[i] == comp[i + n]) return false;
            answer[i] = (comp[i] > comp[i + n] ? 1 : 0);
        }

        return true;
    }
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	two_sat solver(n);
	for(int i=0;i<m;i++){
        int x,y,c;
        string s;
        cin>>x>>y>>s>>c;
        if(s=="="){
            if(c==0){
                solver.add_clause_or(x,false,x,false);
                solver.add_clause_or(y,false,y,false);
            }else if(c==1){
                solver.add_clause_or(x,true,y,true);
                solver.add_clause_or(x,false,y,false);
            }else if(c==2){
                solver.add_clause_or(x,true,x,true);
                solver.add_clause_or(y,true,y,true);
            }
        }else if(s=="!="){
            if(c==0){
                solver.add_clause_or(x,true,y,true);
            }else if(c==1){
                solver.add_clause_or(x,false,y,true);
                solver.add_clause_or(x,true,y,false);
            }else if(c==2){
                solver.add_clause_or(x,false,y,false);
            }
        }else if(s=="<"){
            if(c==0){
                cout<<"No\n";
                return 0;
            }else if(c==1){
                solver.add_clause_or(x,false,x,false);
                solver.add_clause_or(y,false,y,false);
            }else if(c==2){
                solver.add_clause_or(x,false,y,false);
            }
        }else if(s==">"){
            if(c==0){
                solver.add_clause_or(x,true,y,true);
            }else if(c==1){
                solver.add_clause_or(x,true,x,true);
                solver.add_clause_or(y,true,y,true);
            }else if(c==2){
                cout<<"No\n";
                return 0;
            }
        }else if(s=="<="){
            if(c==0){
                solver.add_clause_or(x,false,x,false);
                solver.add_clause_or(y,false,y,false);
            }else if(c==1){
                solver.add_clause_or(x,false,y,false);
            }
        }else if(s==">="){
            if(c==1){
                solver.add_clause_or(x,true,y,true);
            }else if(c==2){
                solver.add_clause_or(x,true,x,true);
                solver.add_clause_or(y,true,y,true);
            }
        }
	}
	if(solver.satisfiable()) cout<<"Yes\n";
	else cout<<"No\n";

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
