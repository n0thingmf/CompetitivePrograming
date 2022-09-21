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
const int maxn=3e5+1;
string s[maxn],t;
int pinow[maxn],ans=0;
vector<int> child[maxn];
vector<vector<int>> go;
void build(){
    t+="#";
    int n=t.size();
    vector<int> pi(n);
    pi[0]=0;
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && t[j]!=t[i]) j=pi[j-1];
        if(t[j]==t[i]) j++;
        pi[i]=j;
    }
    go.assign(n,vector<int>(26,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            if(i==0 || t[i]=='a'+j) go[i][j]=i+(t[i]=='a'+j);
            else go[i][j]=go[pi[i-1]][j];
        }
    }
}
void dfs(int v,int pos){
    for(int u:child[v]){
        for(int i=0;i<s[u].size();i++){
            pinow[pos+i]=go[pinow[pos+i-1]][s[u][i]-'a'];
            if(pinow[pos+i]==t.size()-1){
                ans++;
                //cout<<u+1<<" "<<pos+i<<"\n";
            }
        }
        dfs(u,pos+s[u].size());
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
        int par;
        cin>>par;
        child[par-1].pb(i);
        cin>>s[i];
	}
	cin>>t;
	build();
	pinow[0]=0;
	dfs(0,1);
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
