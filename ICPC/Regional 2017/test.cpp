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
const int maxn=1e5;
int ndiv(int num){
    int ans=1;
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            int e=0;
            while(num%i==0){
                num/=i;
                e++;
            }
            ans++;
        }
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans=0;
	for(int i=2;i<=maxn;i++){
        ans=max(ans,ndiv(i));
	}
	cout<<ans<<"\n";
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
