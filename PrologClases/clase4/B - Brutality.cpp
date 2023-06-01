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
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	string s;
	cin>>s;
	vector<int> a;
	a.pb(v[0]);
	ll ans=0;
	for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            sort(all(a));
            for(int j=a.size()-1;j>=0 && j>=(int)a.size()-k;j--){
                ans+=a[j];
            }
            a.clear();
            a.pb(v[i]);
        }else{
            a.pb(v[i]);
        }
	}
	sort(all(a));
    for(int i=a.size()-1;i>=0 && i>=(int)a.size()-k;i--){
        ans+=a[i];
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
