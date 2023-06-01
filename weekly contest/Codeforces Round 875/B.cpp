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
	cout << setprecision(12) << fixed;
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        vector<int> fa(2*n+1),fb(2*n+1);
        int last=-1,cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]!=last){
                if(last!=-1) fa[last]=max(fa[last],cnt);
                cnt=1;
                last=a[i];
            }else{
                cnt++;
            }
        }
        if(last!=-1) fa[last]=max(fa[last],cnt);
        last=-1,cnt=0;
        for(int i=0;i<n;i++){
            if(b[i]!=last){
                if(last!=-1) fb[last]=max(fb[last],cnt);
                cnt=1;
                last=b[i];
            }else{
                cnt++;
            }
        }
        if(last!=-1) fb[last]=max(fb[last],cnt);
        int ans=0;
        for(int i=1;i<=2*n;i++){
            ans=max(ans,fa[i]+fb[i]);
        }
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
