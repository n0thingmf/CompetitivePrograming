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
const int maxn=5e3;
int a[maxn];
int l[maxn][maxn+1],r[maxn][maxn+1];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<=k;i++){
        if(a[0]==i) l[0][i]=1;
        else l[0][i]=0;
        if(a[n-1]==i) r[n-1][i]=1;
        else r[n-1][i]=0;
	}
	l[0][0]=1;
	r[n-1][0]=1;
	for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            if(j>=a[i]) l[i][j]=l[i-1][j]|l[i-1][j-a[i]];
            else l[i][j]=l[i-1][j];
        }
	}
	for(int i=n-2;i>=0;i--){
        for(int j=0;j<=k;j++){
            if(j>=a[i]) r[i][j]=r[i+1][j]|r[i+1][j-a[i]];
            else r[i][j]=r[i+1][j];
        }
	}
	int ans=0;
	for(int i=0;i<n;i++){
        if(k<=a[i]) continue;
        int minv=k-a[i];
        bool ok=true;
        if(i==0){
            for(int j=minv;j<k;j++){
                if(r[1][j]){
                    ok=false;
                    break;
                }
            }
        }else if(i==n-1){
            for(int j=minv;j<k;j++){
                if(l[n-2][j]){
                    ok=false;
                    break;
                }
            }
        }else{
            int x=0,y=0,cnt=r[i+1][0];
            for(int j=k-1;j>=0;j--){
                if(x+j<minv){
                    cnt-=r[i+1][x];
                    x++;
                }
                if(y+j<k-1){
                    y++;
                    cnt+=r[i+1][y];
                }
                if(l[i-1][j] && (cnt>0)){
                    ok=false;
                    break;
                }
            }
        }
        if(ok) ans++;
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
