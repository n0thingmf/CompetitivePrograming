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

vector<map<int,int>> adj(26);
int minimax(int v,bool turn){
    bool fend=true;
    int ans;
    if(turn) ans=-2;
    else ans=2;
    for(auto x:adj[v]){
        if(x.second>0){
            fend=false;
            adj[v][x.first]--;
            if(turn){
                ans=max(ans,minimax(x.first,!turn));
            }else{
                ans=min(ans,minimax(x.first,!turn));
            }
            adj[v][x.first]++;
        }
    }
    if(fend) return !turn;
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	set<int> inits;
	for(int i=0;i<n;i++){
        string s;
        cin>>s;
        adj[s[0]-'a'][s.back()-'a']++;
        inits.insert(s[0]-'a');
	}
	bool ans=false;
	for(int i:inits){
        if(minimax(i,true)) ans=true;
	}
	if(ans) cout<<"First\n";
	else cout<<"Second\n";
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
