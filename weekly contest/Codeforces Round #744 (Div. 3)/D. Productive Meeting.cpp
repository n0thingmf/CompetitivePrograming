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
        priority_queue<pair<int,int>> p;
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            p.push({val,i});
        }
        pair<int,int> a,b;
        int ans=0;
        vector<pair<int,int>> pairs;
        while(true){
            a=p.top();
            p.pop();
            b=p.top();
            p.pop();
            if(a.first==0 || b.first==0) break;
            pairs.pb({a.second+1,b.second+1});
            p.push({a.first-1,a.second});
            p.push({b.first-1,b.second});
        }
        cout<<pairs.size()<<"\n";
        for(int i=0;i<pairs.size();i++) cout<<pairs[i].first<<" "<<pairs[i].second<<"\n";
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
