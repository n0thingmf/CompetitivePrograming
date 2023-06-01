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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	map<int,set<int>> follow;
	for(int i=0;i<q;i++){
        int t,a,b;
        cin>>t>>a>>b;
        a--,b--;
        if(t==1){
            follow[a].insert(b);
        }else if(t==2){
            follow[a].erase(b);
        }else{
            if(follow[a].count(b)>0 && follow[b].count(a)>0){
                cout<<"Yes\n";
            }else cout<<"No\n";
        }
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
