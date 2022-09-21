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
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int i=n-1,j=n-1;
        bool ok=true;
        vector<int> f(n+1,0);
        while(i>=0 && j>=0 && ok){
              //  cout<<i<<" "<<j<<"\n";
            if(a[i]==b[j]){
                i--,j--;
            }else{
                if(j+1<n && b[j]==b[j+1]) f[b[j]]++,j--;
                else if(f[a[i]]) f[a[i]]--,i--;
                else ok=false;
            }
        }
        while(i>=0 && ok){
            if(f[a[i]]) f[a[i]]--,i--;
            else ok=false;
        }
        for(int i=0;i<=n;i++) if(f[i]!=0) ok=false;
        //if(i>0 || j>0) ok=false;
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
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
