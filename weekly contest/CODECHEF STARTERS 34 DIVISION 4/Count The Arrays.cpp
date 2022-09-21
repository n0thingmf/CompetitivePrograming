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

const ll mod=1e9+7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> c(2*n);
        for(int i=0;i<2*n;i++) cin>>c[i];
        sort(all(c));
        vector<int> v,m;
        if(c[0]%2==0){
            cout<<"0\n";
            continue;
        }
        m.pb(1);
        v.pb(c[0]);
        bool ok=true;
        for(int i=1;i<2*n && ok;i++){
            if(c[i]==v.back()) m.back()++;
            else if(c[i]==v.back()+1){
                for(int j=i;j<i+m.back();j++){
                    if(c[i]!=v.back()+1){
                        ok=false;
                        break;
                    }
                }
                i+=m.back()-1;
            }else{
                if(c[i]%2==0) ok=false;
                m.pb(1);
                v.pb(c[i]);
            }
        }
        if(!ok){
            cout<<"0\n";
            continue;
        }
        vector<ll> dp1(n+1,0),dp2(n+1,0);
        dp1[0]=1,dp2[0]=1;
        for(int i=0;i<m.size();i++){
            for(int j=1;j<=m[i];j++){
                for(int k=0;k+j<=n;k++){
                    dp2[k+j]=(dp2[k+j]+dp1[k])%mod;
                }
            }
            dp1=dp2;
        }
        for(int i=0;i<v.size();i++){
            k-=m[i]*v[i];
        }
        if(k<0 || k>n) cout<<"0\n";
        else cout<<dp1[k]<<"\n";
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
