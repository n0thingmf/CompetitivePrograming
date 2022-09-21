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
	int n;
	cin>>n;
	vector<int> v(n);
	vector<ll> t(n+1);
	ll sum=0;
	for(int i=0;i<n;i++) cin>>v[i],sum+=v[i];
	ll now=0,pref=0;
	for(int i=0;i<n;i++){
        t[i+1]=max(now,(sum+i)/(i+1));
        pref+=v[i];
        now=max(now,(pref+i)/(i+1));
	}
	//for(int i=1;i<=n;i++) cout<<t[i]<<" ";
	//cout<<"\n";
	int q;
	cin>>q;
	while(q--){
        ll x;
        cin>>x;
        if(t[n]>x){
            cout<<"-1\n";
            continue;
        }
        int l=1,r=n;
        while(l<r){
            int m=(l+r)>>1;
            if(x>=t[m]) r=m;
            else l=m+1;
        }
        cout<<l<<"\n";
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
