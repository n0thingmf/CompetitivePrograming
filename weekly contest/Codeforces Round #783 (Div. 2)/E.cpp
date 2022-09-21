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
	int n;
	cin>>n;
	int x=n-1,y=1;
	vector<pair<int,int>> ans;
	for(int i=0;x>0 && y<=n;i++){
        ans.pb({x,y});
        if(i&1) x-=2,y+=1;
        else x-=1,y+=2;
	}
	if(n%3==1){
        ans.pb({1,n});
	}
	cout<<ans.size()<<"\n";
	for(auto pr:ans) cout<<pr.first<<" "<<pr.second<<"\n";
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
