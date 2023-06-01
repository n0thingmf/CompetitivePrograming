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
        ll a,b,d;
        cin>>a>>b>>d;
        //cout<<bitset<30>(a)<<" "<<bitset<30>(b)<<" "<<bitset<30>(d)<<"\n";
        if((a&-a)>=(d&-d) && (b&-b)>=(d&-d)){
            ll x=(1<<30)-(d&-d);
            ll now=0;
            for(int i=0;i<30;i++){
                if(x&(1<<i)){
                    if((now&(1<<i))==0){
                        now+=d;
                    }
                    d<<=1;
                }
            }
            //cout<<bitset<60>(x|now)<<"\n";
            cout<<(x|now)<<"\n";
        }else{
            cout<<"-1\n";
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
