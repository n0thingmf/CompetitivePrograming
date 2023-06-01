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
	int n,m;
	cin>>n>>m;
	vector<set<int>> a(m);
	for(int i=0;i<m;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int v;
            cin>>v;
            a[i].insert(v);
        }
	}
	bool ok=true;
	for(int i=1;i<=n && ok;i++){
        for(int j=i+1;j<=n && ok;j++){
            bool g=false;
            for(int k=0;k<m;k++){
                if(a[k].count(i)>0 && a[k].count(j)>0) g=true;
            }
            if(!g) ok=false;
        }
	}
	if(ok) cout<<"Yes\n";
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
