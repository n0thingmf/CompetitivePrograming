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

const int maxn=15e6+1;

bool esPrimo[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(esPrimo,true,sizeof(esPrimo));
	esPrimo[0]=esPrimo[1]=false;
	for(int i=2;i*i<maxn;i++){
        if(esPrimo[i]){
            for(int j=i*i;j<maxn;j+=i){
                esPrimo[j]=false;
            }
        }
	}
	for(int i=0;i<=100;i++){
        if(esPrimo[i]){
            cout<<i<<"\n";
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
