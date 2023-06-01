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
	int n,k;
	cin>>n>>k;
	vector<int> a(k);
	for(int i=0;i<k;i++) cin>>a[i];
	vector<int> b(n);
	for(int i=0;i<n;i++) b[i]=i+1;
	int start=0;
	for(int i=0;i<k;i++){
        start=(start+a[i])%(b.size());
        cout<<b[start]<<"\n";
        b.erase(b.begin()+start); //O(n)
        start%=b.size();
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
