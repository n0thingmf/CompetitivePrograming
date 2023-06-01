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
	int k;
	cin>>k;
	map<ll,pair<int,int>> mp;
	bool ok=false;
	for(int i=0;i<k;i++){
        int n;
        cin>>n;
        vector<int> a(n);
        ll sum=0;
        for(int j=0;j<n;j++) cin>>a[j],sum+=a[j];
        //if(ok) continue;
        for(int j=0;j<n;j++){
            if(mp.count(sum-a[j])){
                cout<<"YES\n";
                pair<int,int> p=mp[sum-a[j]];
                cout<<p.first+1<<" "<<p.second+1<<"\n";
                cout<<i+1<<" "<<j+1<<"\n";
                return 0;
            }
        }
        for(int j=0;j<n;j++){
            mp[sum-a[j]]={i,j};
        }
	}
	cout<<"NO\n";
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
