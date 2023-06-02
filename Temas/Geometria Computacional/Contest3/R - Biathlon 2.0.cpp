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

ll cross(ll a,ll b,ll x,ll y){
    return a*y-b*x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;
	int n,m;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    cin>>m;
    vector<int> x(m),y(m);
    for(int i=0;i<m;i++) cin>>x[i]>>y[i];
    for(int i=0;i<n;i++){
        int L=0,R=m-1;
        while(L<R){
            int M=(L+R)/2;
            if(cross(a[i],b[i],x[M],y[M])>=0)
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
