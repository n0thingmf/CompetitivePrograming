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

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,d;
        cin>>n>>d;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int g=gcd(n,d),ans=0;
        bool ok=true;
        for(int i=0;i<g;i++){
            vector<int> cycle;
            if(a[i]==0) cycle.pb(0);
            int pos=1;
            for(int j=(i+d)%n;j!=i;j=(j+d)%n,pos++){
                if(a[j]==0) cycle.pb(pos);
            }
            if(cycle.size()==0){
                ok=false;
                break;
            }else{
                int res=cycle[0]+pos-cycle.back()-1;
                for(int j=1;j<cycle.size();j++){
                    res=max(res,cycle[j]-cycle[j-1]-1);
                }
                ans=max(ans,res);
            }
        }
        if(ok) cout<<ans<<"\n";
        else cout<<"-1\n";
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
