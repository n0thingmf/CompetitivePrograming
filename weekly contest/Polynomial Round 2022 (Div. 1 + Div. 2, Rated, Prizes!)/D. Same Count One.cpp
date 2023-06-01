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
        vector<vector<int>> a(n,vector<int>(m));
        vector<pair<int,int>> b(n);
        int sum=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++) cin>>a[i][j],cnt+=a[i][j];
            b[i]={cnt,i};
            sum+=cnt;
        }
        if(sum%n==0){
            int sz=sum/n;
            int ans=0;
            for(int i=0;i<n;i++) if(b[i].first>sz) ans+=b[i].first-sz;
            cout<<ans<<"\n";
            sort(all(b));
            for(int i=n-1,j=0;i>=0 && b[i].first>sz;i--){
                while(b[i].first>sz && j<n){
                    for(int k=0;k<m;k++){
                        if(a[b[i].second][k]==1 && a[b[j].second][k]==0){
                            swap(a[b[i].second][k],a[b[j].second][k]);
                            cout<<b[i].second+1<<" "<<b[j].second+1<<" "<<k+1<<"\n";
                            b[i].first--;
                            b[j].first++;
                        }
                        if(b[i].first==sz || b[j].first==sz) break;
                    }
                    j++;
                }
            }

        }else{
            cout<<"-1\n";
        }
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
