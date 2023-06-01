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
	int n,m,h,k;
	cin>>n>>m>>h>>k;
	string s;
	cin>>s;
	multiset<pair<int,int>> good;
	for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        good.insert({x,y});
	}
	int x=0,y=0;
	for(int i=0;i<n;i++){
        h--;

        if(h<0){
            cout<<"No\n";
            return 0;
        }
        if(s[i]=='R'){
            x++;
        }else if(s[i]=='L'){
            x--;
        }else if(s[i]=='U'){
            y++;
        }else{
            y--;
        }

        if(good.count({x,y})){
            if(h<k){
                h=k;
                good.erase(good.find({x,y}));
            }
        }
	}
	cout<<"Yes\n";
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
