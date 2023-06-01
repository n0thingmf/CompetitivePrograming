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
	int t;
	cin>>t;
	while(t--){
        int n,k;
        cin>>n>>k;
        vector<bool> a(2*n+1,false);
        int mx=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[x]=true;
            mx=max(mx,x);
        }
        ll ans=0;
        if(mx-n>=k){
            ll res=0;
            for(int i=1,j=0;i<mx && j<k;i++){
                if(!a[i]){
                    //cout<<"aea "<<i<<" "<<j<<" "<<k<<"\n";
                    res+=mx-i;
                    j++;
                }
            }
            ans=max(ans,res);
        }
        ll res=0;
        for(int i=1,j=0;i<2*n && j<k-1;i++){
            if(!a[i]){
                   // cout<<"aea22 "<<i<<" "<<j<<" "<<k<<"\n";
                res+=2*n-i;
                j++;
            }
        }
           // cout<<res<<"\n";
        ans=max(res,ans);
        cout<<ans<<"\n";
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
