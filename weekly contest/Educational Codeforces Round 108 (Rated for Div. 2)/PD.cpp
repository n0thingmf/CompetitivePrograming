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
	ll ans=0,total=0,now;
	cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) total+=1ll*a[i]*b[i];
    ans=total;
    for(int i=1;i<n-1;i++){
        int l=i-1,r=i+1;
        now=total;
        while(l>=0 && r<n){
            now+=(a[r]-a[l])*b[l]+(a[l]-a[r])*b[r];
            ans=max(ans,now);
            l--,r++;
        }
    }
    for(int i=0;i<n-1;i++){
        int l=i,r=i+1;
        now=total;
        while(l>=0 && r<n){
            now+=(a[r]-a[l])*b[l]+(a[l]-a[r])*b[r];
            ans=max(ans,now);
            l--,r++;
        }
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
