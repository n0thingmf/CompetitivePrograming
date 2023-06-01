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
        int ua=0,ub=0;
        for(int i=0;i<n;i++) cin>>a[i],ua+=a[i]==1;
        for(int i=0;i<n;i++) cin>>b[i],ub+=b[i]==1;
        if(a==b) cout<<"0\n";
        else{
            if(ua==ub) cout<<"1\n";
            else if(ua>ub){
                bool ok=true;
                for(int i=0;i<n;i++){
                    if(a[i]<b[i]){
                        cout<<ua-ub+1<<"\n";
                        ok=false;
                        break;
                    }
                }
                if(ok) cout<<ua-ub<<"\n";
            }else{
                bool ok=true;
                for(int i=0;i<n;i++){
                    if(a[i]>b[i]){
                        cout<<ub-ua+1<<"\n";
                        ok=false;
                        break;
                    }
                }
                if(ok) cout<<ub-ua<<"\n";
            }
        }
	}
	cout << setprecision(12) << fixed;
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
