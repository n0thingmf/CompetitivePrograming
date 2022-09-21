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
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	scanf("%d",&t);
	while(t--){
	    int e=2,r,ans;
	    printf("? %d %d\n",2,4);
	    fflush(stdout);
	    scanf("%d",&r);
	    r%=2;
        while (e<(1<<30)) {
            printf("? %d %d\n",e-r,e+(e<<1)-r);
            fflush(stdout);
            scanf("%d",&ans);
            if(ans==(e<<1)){
                r=e+r;
            }
            e<<=1;
        }
        printf("! %d\n", r);
        fflush(stdout);
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
