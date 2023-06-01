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
        int a,b,c;
        cin>>a>>b>>c;
        bool ok=false;
        for(int x=-100;x<=100 && !ok;x++){
            for(int y=-100;y<=100 && !ok;y++){
                int z=a-x-y;
                if(x!=y && x!=z && y!=z && x*y*z==b && x*x+y*y+z*z==c){
                    cout<<x<<" "<<y<<" "<<z<<"\n";
                    ok=true;
                }
            }
        }
        if(!ok) cout<<"No solution.\n";
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
