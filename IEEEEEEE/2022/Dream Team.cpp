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
	ll B;
	cin>>B;
	vector<ll> w[5];
	vector<string> name[5];
	for(int i=0;i<5;i++){
	    int n;
	    cin>>n;
	    w[i].resize(n);
	    for(int j=0;j<n;j++) cin>>name[i][j]>>w[i][j];
	}
	vector<pair<ll,string>> x;
	for(int i=0;i<w[0].size();i++){
	    for(int j=0;j<w[1].size();j++){
	        x.pb({w[0][i]+w[1][j],name[0][i]+" "+name[1][j]});
	    }
	}
	sort(all(x));
	ll best=0;
	string team;
	for(int i=0;i<w[2].size();i++){
	    for(int j=0;j<w[3].size();j++){
	        for(int k=0;k<w[4].size();k++){
	            ll ww=w[2][i]+w[3][j]+w[4][k];
	            if(ww<=B){
	                string kekw=name[2][i]+" "+name[3][j]+" "+name[4][k];
	                int id=upper_bound(all(x),make_pair(B-ww,string()))-x.begin();
	                id--;
	                if(id>=0){
	                    if(best<x[id].first+ww){
	                        team=x[id].second+kekw;
	                    }else if(best==x[id].first+ww){
	                        if(team>x[id].second+kekw){
	                            team=x[id].second+kekw;
	                        }
	                    }
	                }
	            }
	        }
	    }
	}
	cout<<team<<"\n";

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
