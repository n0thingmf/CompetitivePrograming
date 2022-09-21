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

vector<map<string,int>> trie;
int node=0;
void insert(string s){
    int pos=0;
    string next;
    for(int i=0;i<s.size();i++){
        if(s[i]=='\\'){
            if(trie[pos].count(next)==0){
                trie[pos][next]=++node;
                trie.pb(map<string,int>());
            }
            pos=trie[pos][next];
            next.clear();
        }else{
            next.pb(s[i]);
        }
    }
    if(next.size()>0){
        if(trie[pos].count(next)==0){
            trie[pos][next]=++node;
            trie.pb(map<string,int>());
        }
        pos=trie[pos][next];
        next.clear();
    }
}
void prnt(int pos,string sang){
    for(auto x:trie[pos]){
        cout<<sang<<x.first<<"\n";
        sang.pb(' ');
        prnt(x.second,sang);
        sang.popb();
    }
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n,nt=0;
	while(cin>>n){
        trie.assign(1,map<string,int>());
        node=0;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            insert(s);
        }
        prnt(0,"");
        cout<<"\n";
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
