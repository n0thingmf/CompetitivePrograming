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

const int maxn=1e6;
int trie[maxn][26];
bool termino[maxn];
int node=0;
void insert(string s){
    int pos=0;
    for(int i=0;i<s.size();i++){
        int next=s[i]-'a';
        if(trie[pos][next]==0) trie[pos][next]=++node;
        pos=trie[pos][next];
    }
    termino[pos]=true;
}
void dfs(string s,int pos){
    if(termino[pos]) cout<<s<<"\n";
    for(int i=0;i<26;i++){
        if(trie[pos][i]==0) continue;
        s.pb('a'+i);
        dfs(s,trie[pos][i]);
        s.popb();
    }
}
void solve(string s){
    int pos=0;
    for(int i=0;i<s.size();i++){
        int next=s[i]-'a';
        if(trie[pos][next]==0){
            cout<<"No match.\n";
            return;
        }
        pos=trie[pos][next];
    }
    for(int i=0;i<26;i++){
        if(trie[pos][i]==0) continue;
        s.pb('a'+i);
        dfs(s,trie[pos][i]);
        s.popb();
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(s);
	}
	cin>>k;
	for(int i=1;i<=k;i++){
        string s;
        cin>>s;
        cout<<"Case #"<<i<<":\n";
        solve(s);
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
