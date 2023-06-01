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
	int q;
	cin>>q;
	while(q--){
        int a;
        cin>>a;
        int mb=max_bit(a);
        int c=(1<<(mb+1))-1;
        if(a==c){
            int max_div=1;
            for(int i=2;i*i<=a;i++){
                if(a%i==0){
                    max_div=max(max_div,i);
                    if(i!=a/i) max_div=max(max_div,a/i);
                }
            }
            cout<<max_div<<"\n";
        }else{
            cout<<c<<"\n";
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
