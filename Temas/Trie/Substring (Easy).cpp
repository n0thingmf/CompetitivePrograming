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

int trie[10000][26];
int node=0;
void insert(string s){
    int pos=0;
    for(int i=0;i<s.size();i++){
        int nxt=s[i]-'a';
        if(trie[pos][nxt]==0) trie[pos][nxt]=++node;
        pos=trie[pos][nxt];
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
        insert(s.substr(i,s.size()-i));
	}
	cout<<node<<"\n";
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
