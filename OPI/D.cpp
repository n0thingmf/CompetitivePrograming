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

const int maxn = 2e5+2;

int n;
vector<int> a;
int ST[maxn][25];
void STBuild(){
    for(int i = 1; i <= n; i++){
        ST[i][0] = a[i];
    }
    for(int k = 1; 1<<k <= n; k++){
        int dis = 1<<(k - 1);
        for(int i = 1; i + 2 * dis - 1 <= n; i++){
            ST[i][k] = max(ST[i][k - 1], ST[i + dis][k - 1]);
        }
    }
}

int STQuery(int L, int R){
    int d = R - L + 1;
    int k = 31 - __builtin_clz(d);
    int dis = 1<<k;
    return max(ST[L][k], ST[R-dis+1][k]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin>>n>>k;
	int tot=n-k;
	a.resize(n+1);
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	STBuild();
	vector<int> res;
	int mex=STQuery(1,k+1);
    //cout<<mex<<" mex\n";
	for(int i=1;i<=n;i++){
        if(a[i]==mex){
            res.pb(a[i]);
            mex=STQuery(i+1,i+k+1);
        }else k--;
	}
	for(int i=0;i<tot;i++) cout<<res[i];
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
