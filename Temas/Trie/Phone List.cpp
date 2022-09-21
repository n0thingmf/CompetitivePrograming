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
const int maxn=1e7+1;
vector<vector<int>> trie;
vector<int> cnt;
vector<bool> terminal;

int pos=0;
void insert(string s){
    int now=0;
    for(int i=0;i<s.size();i++){
        int next=s[i]-'0';
        cnt[now]++;
        if(trie[now][next]==0){
            trie[now][next]=++pos;
            trie.pb(vector<int>(10,0));
            cnt.pb(0);
            terminal.pb(false);
        }
        now=trie[now][next];
    }
    cnt[now]++;
    terminal[now]=true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        trie.assign(1,vector<int>(10,0));
        cnt.assign(1,0);
        terminal.assign(1,false);
        pos=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            insert(s);
        }
        bool ok=true;
        for(int i=1;i<=pos;i++){
            if(terminal[i] && cnt[i]!=1){
                ok=false;
                break;
            }
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
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
