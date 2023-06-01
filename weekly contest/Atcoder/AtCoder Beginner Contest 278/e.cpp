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

int uniq(vector<int> &f){
    int n=f.size();
    int ans=0;
    for(int i=0;i<n;i++){
        if(f[i]!=0) ans++;
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int H,W,n,h,w;
	cin>>H>>W>>n>>h>>w;
	vector<vector<int>> a(H,vector<int>(W));
	vector<int> tf(n+1,0);
	for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>a[i][j];
            tf[a[i][j]]++;
        }
	}
	vector<vector<int>> ans(H-h+1,vector<int>(W-w+1));
	for(int i=0;i+h-1<H;i++){
        vector<int> f=tf;
        for(int u=i;u<i+h;u++){
            for(int j=0;j<w;j++){
                f[a[u][j]]--;
            }
        }
        //for(int x=0;x<n;x++) cout<<f[x]<<" ";
        //cout<<"\n";
        ans[i][0]=uniq(f);
        for(int j=1;j+w-1<W;j++){
            for(int u=i;u<i+h;u++){
                f[a[u][j-1]]++;
                f[a[u][j+w-1]]--;
            }
            ans[i][j]=uniq(f);
        }
	}
	for(int i=0;i+h-1<H;i++){
        for(int j=0;j+w-1<W;j++){
            cout<<ans[i][j]<<" ";
        }
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
