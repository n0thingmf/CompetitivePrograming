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
        vector<int> c(n);
        for(int i=0;i<n;i++) cin>>c[i];
        vector<int> a(2*n);
        for(int i=0;i<c[0];i++) a[i]=1;
        a[c[0]]=0;
        int j=c[0],unos=c[0];
        for(int i=1;i<n;i++){
            if(i<=j){
                int k;
                for(k=0;k<c[i]-unos-i*a[i];k++){
                    a[j+k+1]=1;
                }
                a[j+k+1]=0;
                j=j+k+1;
                unos+=k;
            }else{
                if(c[i]==0){
                    a[i]=0;
                    j=i;
                }else{
                    int k;
                    for(k=0;k<c[i]-i;k++){
                        a[j+k+1]=1;
                    }
                    a[j+k+1]=0;
                    j=j+k+1;
                    unos+=k;
                }
            }
        }
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
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
