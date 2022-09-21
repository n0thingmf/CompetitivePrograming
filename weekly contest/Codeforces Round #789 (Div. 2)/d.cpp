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
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<int> a(n*m);
        for(int i=0;i<n*m;i++) a[i]=s[i]-'0';
        vector<int> f(m,0);
        vector<int> dpr(n*m,0),dpc(n*m,0);
        for(int i=0,fi=0,cnt1=0;i<n*m;i++){

            if(i>0) dpc[i]=dpc[i-1]-f[(fi+m-1)%m];
            else dpc[i]=0;
            f[(fi+m-1)%m]|=a[i];
            dpc[i]+=f[(fi+m-1)%m];
            fi++;
            if(i>=m){
                cnt1-=a[i-m]>0;
                cnt1+=a[i]>0;
                dpr[i]=dpr[i-m]+(int)(cnt1>0);
            }else{
                cnt1+=a[i]>0;
                dpr[i]=cnt1>0;
            }
        }
        for(int i=0;i<n*m;i++) cout<<dpr[i]+dpc[i]<<" ";
        cout<<"\n";
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
