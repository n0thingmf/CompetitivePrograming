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
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int check=0;
        for(int i=0;i<n;i++) if(s[i]=='1') check++;
        if(check==0 || check%2==1){
            cout<<"NO\n";
            continue;
        }
        if(check==n){
            cout<<"YES\n";
            for(int i=1;i<n;i++) cout<<1<<" "<<i+1<<"\n";
            continue;
        }
        vector<pair<int,int>> e;
        vector<int> imp;
        vector<int> deg(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                imp.pb(i);
            }
        }
        for(int i=0;i<imp.size()-2;i++){
            e.pb({imp[0],imp[i]+1});
            for(int j=imp[i]+1;j<imp[i+1];j++){
                e.pb({j,j+1});
            }
        }
        if(imp[imp.size()-2]+1!=imp.back()) {
            e.pb({imp[0],imp[imp.size()-2]+1});
            for(int i=imp[imp.size()-2]+1;i<imp[imp.size()-1]-1;i++) e.pb({i,i+1});
            e.pb({imp[imp.size()-1]-1,(imp[0]-1+n)%n});
        } else e.pb({imp[0],(imp[0]-1+n)%n});
        for(int i=(imp[0]-1+n)%n;i!=imp[imp.size()-1];i=(i-1+n)%n){
            int j=(i-1+n)%n;
            e.pb({i,j});
        }
        cout<<"YES\n";
        for(auto x:e) cout<<x.first+1<<" "<<x.second+1<<"\n";
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
