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

vector<int> kap;
void prec(){
    for(int i=4;i<=4e4;i++){
        string s=to_string(i*i);
        for(int j=1;j<s.size();j++){
            int x=stoi(s.substr(0,j));
            int y=stoi(s.substr(j,s.size()-j));
            if(i==x+y && x>0 && y>0){
                kap.pb(i);
                break;
            }
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	prec();
	//for(auto x:kap) cout<<x<<"\n";
	int t;
	cin>>t;
	for(int ncase=1;ncase<=t;ncase++){
        cout<<"case #"<<ncase<<"\n";
        int inf,sup;
        cin>>inf>>sup;
        bool ok=true;
        for(auto k:kap){
            if(inf<=k && k<=sup){
                cout<<k<<"\n";
                ok=false;
            }
        }
        if(ok) cout<<"no kaprekar numbers\n";
        if(ncase<t) cout<<"\n";
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
